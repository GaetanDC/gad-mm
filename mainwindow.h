#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QModelIndex>
//#include <uglobalhotkeys.h>
#include <QSystemTrayIcon>
#include <QMenu>
#include <QTimer> //used for hiding version bar
#include <QDesktopServices> //used for showing the online user manual.
#include <QUndoStack>
#include <QClipboard>
#include <QCompleter>
#include <QSqlDatabase>
#include "mylogmodel.h"
#include "mytodomodel.h"
#include "myassetsmodel.h"
#include <memory>

#include "version.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
public slots:
   void updateTitle();
 	void selectionChanged(const QModelIndex, const QModelIndex);
    
private slots:
	void actionAdd_triggered();
	void assetAdd_triggered();

	
    void updateSettings();


    void on_actionSettings_triggered();
    void on_actionAbout_triggered();
    void on_actionPrint_triggered();
    void on_actionSave_triggered();
    inline void on_actionCheck_for_updates_triggered() {Version->onlineCheck(true);}
    inline void on_actionManual_triggered()
    		{QDesktopServices::openUrl(QUrl("https://sverrirvalgeirsson.github.io/Todour"));};    
    		
    inline void on_actionQuit_triggered(){cleanup();}
    void cleanup(); // Need to have a quit slot of my own to save settings and so on.
    		
    void on_actionStay_On_Top_changed();   		
	 void dataInModelChanged(QModelIndex,QModelIndex);
    
   void on_actionUndo();
   void on_actionRedo();
    
   void new_version(QString);

private:
    QSqlDatabase CMMSDB;

    Ui::MainWindow *ui;
	myTodoModel * todoModel;
	myAssetsModel * assetsModel;
	myLogModel * logModel;

    void stayOnTop();
    void closeEvent(QCloseEvent *ev);

	QTimer *versionTimer;
	QTimer *autoSaver;

    QString baseTitle;
    QAction *minimizeAction;
    QAction *maximizeAction;
    QAction *restoreAction;
    QAction *quitAction;
    
	gadmm_version *Version;
	
	QUndoStack* _undoStack;
};
#endif // MAINWINDOW_H
