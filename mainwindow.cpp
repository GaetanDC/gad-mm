#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "settingsdialog.h"
#include "aboutbox.h"
#include "def.h"

#include "task_adder.h"
#include "task_closer.h"
#include "asset_editor.h"
#include "mytabledelegates.h"

#include <QTime>
#include <QDebug>

#include <QShortcut>
#include <QCloseEvent>
#include <QtAwesome.h>	//used for fonts and icons
#include <QPalette>
#include <QDir>
#include <QSystemTrayIcon>
#include <QUuid>
#include <QPrinter> //used for printing
#include <QPrintDialog> //used for printing
#include <QTextDocument> //used for printing
#include <QGuiApplication>



//#define NEW_VERSION_STRING "<a href=\"http://nerdur.com/todour-pl\">http://nerdur.com/todour-pl</a>"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
	qDebug()<<"Start mainwindow creation..."<<endline;
    ui->setupUi(this);
    QString title=this->windowTitle();

    QCoreApplication::setOrganizationName("GAD-computing");
    QCoreApplication::setOrganizationDomain("gadcomputing.net");
    QCoreApplication::setApplicationName("gad-mm");


#ifdef QT_NO_DEBUG
//    QCoreApplication::setOrganizationName("Nerdur");
//    QCoreApplication::setOrganizationDomain("nerdur.com");
//    QCoreApplication::setApplicationName("Todour");
//    title.append("-");
#else
//    QCoreApplication::setOrganizationName("Nerdur-debug");
//    QCoreApplication::setOrganizationDomain("nerdur-debug.com");
//    QCoreApplication::setApplicationName("Todour-Debug");
    title.append("-DEBUG-");
#endif
	QSettings settings;
	
    title.append(gadmm_version::get_version());
    baseTitle=title;
    this->setWindowTitle(title);

    // Check if we're supposed to have the settings from .ini file or not
    if(QCoreApplication::arguments().contains("-portable")){
        QSettings::setDefaultFormat(QSettings::IniFormat);
        QSettings::setPath(QSettings::IniFormat,QSettings::UserScope,QDir::currentPath());
        qDebug()<<"Setting ini file path to: "<<QDir::currentPath()<<endline;
    }

    // Restore the position of the window
    restoreGeometry(settings.value( SETTINGS_GEOMETRY, saveGeometry() ).toByteArray());
    restoreState(settings.value( SETTINGS_SAVESTATE, saveState() ).toByteArray());
    if ( settings.value( SETTINGS_MAXIMIZED, isMaximized() ).toBool() )
        showMaximized();

    // Check that we have an UUID for this application (used for undo for example)
    if(!settings.contains(SETTINGS_UUID)){
        settings.setValue(SETTINGS_UUID,QUuid::createUuid().toString());
    }

    // Fix some font-awesome stuff
    fa::QtAwesome* awesome = new fa::QtAwesome(qApp);
    awesome->initFontAwesome();     // This line is important as it loads the font and initializes the named icon map
    awesome->setDefaultOption("scale-factor",0.9);
    QVariantMap options;
	options.insert("color-active" , QColor(255, 0 ,0));
	options.insert("color-active-off",QApplication::palette().color(QPalette::Normal, QPalette::ButtonText));
	
// connect ui signals
	connect(ui->actionAdd_button, SIGNAL(clicked()),this, SLOT(actionAdd_triggered()));
	connect(ui->assetAdd_button, SIGNAL(clicked()),this, SLOT(assetAdd_triggered()));
	
	
	//undo
	_undoStack = new QUndoStack(this);
		ui->undoAction->setEnabled(_undoStack->canUndo());				
    	ui->undoAction->setShortcuts(QKeySequence::Undo);
		connect(_undoStack, SIGNAL(canUndoChanged(bool)), ui->undoAction, SLOT(setEnabled(bool)));
		connect(ui->undoAction, SIGNAL(triggered()), this, SLOT(on_actionUndo()));
		
		ui->redoAction->setEnabled(_undoStack->canRedo());				
    	ui->redoAction->setShortcuts(QKeySequence::Redo);
		connect(_undoStack, SIGNAL(canRedoChanged(bool)), ui->redoAction, SLOT(setEnabled(bool)));
		connect(ui->redoAction, SIGNAL(triggered()), this, SLOT(on_actionRedo()));
	    	
	
    // Version check
    Version = new gadmm_version();
    connect(Version,SIGNAL(NewVersion(QString)),this,SLOT(new_version(QString)));
	Version->onlineCheck(false);
	versionTimer = new QTimer(this);
	connect(versionTimer,SIGNAL(timeout()),this,SLOT(on_pb_closeVersionBar_clicked()));


    // Started. Lets open the db.
   CMMSDB = QSqlDatabase::addDatabase("QSQLITE","CMMSDB");
   CMMSDB.setDatabaseName("/home/gaetan/prog/GAD-MM/cmms.db");
   if (! CMMSDB.open()){
//        emit backendError("Unable to open database");
        return;
        }


	todoModel = new myTodoModel (CMMSDB, _undoStack, this);
	ui->tableView->setModel(todoModel);
	ui->tableView->setItemDelegateForColumn(todoModel->getEditCol(), (QStyledItemDelegate*) new MyTodoEditDelegate(ui->tableView));
	ui->tableView->resizeColumnToContents(todoModel->getEditCol());
	ui->tableView->setItemDelegateForColumn(todoModel->getDeleteCol(), (QStyledItemDelegate*) new MyTodoEditDelegate(ui->tableView));
	ui->tableView->resizeColumnToContents(todoModel->getDeleteCol());

	assetsModel = new myAssetsModel (CMMSDB, _undoStack, this);
	ui->tableView_2->setModel(assetsModel);
	ui->tableView_2->resizeColumnsToContents();


	logModel = new myLogModel (CMMSDB, _undoStack, this);
	ui->logTableView->setModel(logModel);
	ui->logTableView->resizeColumnsToContents();





//GOOD GADMM code
	ui->dateEdit->setDate(QDate::currentDate());

	autoSaver = new QTimer(this);
	QObject::connect(autoSaver,SIGNAL(timeout()),this,SLOT(on_actionSave_triggered()));
	// #TODO put this as a setting: autosave on/off?
	autoSaver->start(1000*60*15); // milliseconds

	this->updateSettings();
	qDebug()<<"mainwindow initialised"<<endline;	
}


void MainWindow::updateSettings()
/* This function regroups all the layout issued from settings.
It is intended to be run at startup, and at closing of settings dialog.
It should be safe to run it at any time.
*/{
QSettings settings;
      // Set some defaults if they dont exist
    if(!settings.contains(SETTINGS_LIVE_SEARCH))
        		settings.setValue(SETTINGS_LIVE_SEARCH,DEFAULT_LIVE_SEARCH);
      
    ui->actionStay_On_Top->setChecked(settings.value( SETTINGS_STAY_ON_TOP,DEFAULT_STAY_ON_TOP).toBool());
    stayOnTop();
       
	//set font size
    int size = settings.value(SETTINGS_FONT_SIZE).toInt();
    if(size >0){
        auto f = qApp->font();
        f.setPointSize(size);
        qApp->setFont(f);

	updateTitle();
	qDebug()<<"Mainwindow: finished update settings"<<endline;
	}
}

void MainWindow::dataInModelChanged(QModelIndex i1,QModelIndex i2)
/* dataInModelChanged informs us that data has changed.
We need to update the title + recalculate the tasks active.
*/{
    Q_UNUSED(i2)// one day, we can limit the computation to some subset...
    Q_UNUSED(i1)
    
//	task_set->recalculate();
	this->updateTitle();  
	}

MainWindow::~MainWindow()
/*
*/{
    delete ui;
    delete todoModel;
	 delete assetsModel;
	 delete logModel;

	}

void MainWindow::updateTitle()
/*
*/{
//    if(proxyModel != NULL){
//        int visible = proxyModel->rowCount();
//        int total = proxyModel->sourceModel()->rowCount();
//		if (_undoStack->isClean())
//				this->setWindowTitle(baseTitle+" (" +QString::number(visible)+"/"+QString::number(total)+")");
//		else 
//				this->setWindowTitle(baseTitle+" * (" +QString::number(visible)+"/"+QString::number(total)+")");
//		}
	}

void MainWindow::new_version(QString s)
/*
*/{
	Q_UNUSED(s)
}

void MainWindow::on_actionAbout_triggered()
/*
*/{
	 AboutBox d;
    d.setModal(true);
    d.show();
    d.exec();
    //myanalytics->check_update();
}

void MainWindow::on_actionSettings_triggered()
/* Opens settings dialog.
 */{
    SettingsDialog d;
    d.setModal(true);
    d.show();
    d.exec();

        this->updateSettings();
//        model->refresh();
}

void MainWindow::actionAdd_triggered()
/*
*/{
	qDebug()<<"MainWindo::addAction_triggered"<<endline;
	task_adder d(this);
	d.setModal(true);
	d.show();
	d.exec();

}

void MainWindow::assetAdd_triggered()
/*
*/{
	qDebug()<<"MainWindo::addAsset_triggered"<<endline;
	asset_editor d(this);
	d.setModal(true);
	d.show();
	d.exec();
	
}


void MainWindow::stayOnTop()
/* */{
    if(ui->actionStay_On_Top->isChecked()){
        setWindowFlags(windowFlags() | Qt::WindowStaysOnTopHint);
    } else {
        setWindowFlags(windowFlags() & ~Qt::WindowStaysOnTopHint);
    }
    show(); // This is needed as setWindowFlags can hide the window
}




void MainWindow::on_actionSave_triggered()
/* */{
	if (! _undoStack->isClean()){
//		task_set->flush();
   	_undoStack->setClean();
   	}
}

void MainWindow::cleanup()
/* */{
	QSettings settings;
	qDebug()<<"Clean up ..."<<endline;	
	on_actionSave_triggered();
   settings.setValue( SETTINGS_GEOMETRY, saveGeometry() );
   settings.setValue( SETTINGS_SAVESTATE, saveState() );
   settings.setValue( SETTINGS_MAXIMIZED, isMaximized() );
//   settings.setValue(SETTINGS_SEARCH_STRING,ui->lineEditFilter->text());
    
    qApp->quit();
}

void MainWindow::closeEvent(QCloseEvent *ev)
/* */{
        cleanup();
        ev->accept();
}

void MainWindow::on_actionStay_On_Top_changed()
/* */{
	QSettings settings;
    settings.setValue(SETTINGS_STAY_ON_TOP,ui->actionStay_On_Top->isChecked());
    stayOnTop();
}

void MainWindow::on_actionUndo()
/* */{
	_undoStack->undo();
//	model->refresh();
	updateTitle();
}

void MainWindow::on_actionRedo()
/* */{
	_undoStack->redo();
//	model->refresh();
	updateTitle();
}



void MainWindow::on_actionPrint_triggered()
/* The user has clicked on "Print". We print the selected tasks
#TODO: consider printing the notes...
*/{
    auto selection = ui->tableView->selectionModel();
    if(selection->hasSelection()){
		QPrinter printer;
		
		QPrintDialog dialog(&printer, this);
		dialog.setWindowTitle(tr("Print Tasks"));
		if (dialog.exec() != QDialog::Accepted)
			return;
		QString txt_str;
		QModelIndexList list=selection->selection().indexes();
		for (QList<QModelIndex>::iterator i=list.begin(); i!=list.end();++i)
		{
			txt_str=txt_str + "<br>";
			txt_str=txt_str+i->data(Qt::DisplayRole).toString();
		}
		QTextDocument text(this);
		text.setHtml(txt_str);
		text.print(&printer);
	}
}


void MainWindow::selectionChanged(const QModelIndex curr, const QModelIndex prev)
/* SLOT activated when the Task selection is changed. save what needs, update display
*/{
	Q_UNUSED(curr)
	Q_UNUSED(prev)
	qDebug()<<"MainWindow::selectionChanged"<<endline;
//	if (prev.isValid()) 	model->noteUpdate(prev,ui->noteView->toPlainText());
//	if (curr.isValid()){
//		subtasksModel->setParentTask(model->getTask(proxyModel->mapToSource(curr))->getDbIndex());
//		ui->noteView->setPlainText(model->getNoteTxt(curr));
//		}
}





/////////////////////////////////////////////////////////////
AboutBox::AboutBox(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutBox)
{
    ui->setupUi(this);
}
