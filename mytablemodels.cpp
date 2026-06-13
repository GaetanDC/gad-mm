#include "mytablemodels.h"
#include "def.h"

#include <QFont>
#include <QRegularExpression>
#include <QDebug>
#include <vector>
#include <QList>

//#include "todo_undo.h"

 myTableModel::myTableModel(QSqlDatabase db, QUndoStack* _undo, QObject *parent):
	QAbstractTableModel(parent)
/*
*/{
	Q_UNUSED(_undo)
	Q_UNUSED(db)
}
  
myTableModel::~myTableModel()
/*
*/{
}

QVariant myTableModel::data(const QModelIndex &index, int role) const
/*
*/{
	Q_UNUSED(index)
	Q_UNUSED(role)
	return QVariant();
}


QVariant myTableModel::headerData(int section, Qt::Orientation orientation, int role) const
/*
*/{
	Q_UNUSED(section)
	Q_UNUSED(orientation)
	Q_UNUSED(role)
return QVariant();    
}

Qt::ItemFlags myTableModel::flags(const QModelIndex& index) const
/*
*/{
	Q_UNUSED(index)
return Qt::ItemIsEditable;
}


bool myTableModel::setData(const QModelIndex & index, const QVariant & value, int role)
/*
*/{
	Q_UNUSED(index)
	Q_UNUSED(value)
	Q_UNUSED(role)
   return true;
}



void myTableModel::refresh()
/*
*/{

}

void myTableModel::startModelChange(QString desc){
	Q_UNUSED(desc)
	}
	
	void myTableModel::endModelChange(){}



 myTodoModel::myTodoModel(QSqlDatabase db, QUndoStack* _undo, QObject *parent):
 	myTableModel(db, _undo, parent)
/*
*/{
    q = new QSqlQuery("SELECT tag,Action,DueD FROM Planning",db);
    	// q = new QSqlQuery("SELECT asset,Action, DueD FROM log_M WHERE (Done != 1)",db);
    	
    this->refreshData();
	}

myTodoModel::~myTodoModel()
/* */{
	delete q;
}


void myTodoModel::refreshData()
/* For some reasons, model has changed, we should reload the data...
*/{
	q->exec();
	content.clear();
	while (q->next()){
		content.append(*new todoItem(
				 q->value(0).toString(),
				 q->value(1).toString(),
				 QDate::fromString(q->value(2).toString(),"yyyy-MM-dd")
				 ));
		}
}

QVariant myTodoModel::data(const QModelIndex &index, int role) const
/*
*/{
    if (!index.isValid()) return QVariant();
    if (content.empty()) return QVariant();
    if (index.row() >= (int) content.size() || index.row() < 0) return QVariant();
    
    qDebug()<<"myTodoModel::data"<<endline;
    if (role == Qt::DisplayRole || role==Qt::ToolTipRole){
        switch (index.column()){
        	case 0:
       	 return content.at(index.row()).asset;
        	 break;
       	case 1:
       	 return content.at(index.row()).action;
        	 break;
        	case 2:
       	 return content.at(index.row()).dueDate;
        	 break;
			}

     }
	return QVariant();
}

QString myTodoModel::toString()
/*
*/{
	return "myTodoModel";
}


///§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§

myAssetsModel::myAssetsModel(QSqlDatabase db, QUndoStack* _undo, QObject *parent) :
	myTableModel(db,_undo,parent)
/*
*/{
	  q = new QSqlQuery("SELECT "
	  			"Tag,	"
	  			"Location, "
	  			"System,	"
	  			"subSystem, "
	  			"Type, "
	  			"subType, "
	  			"description, "
	  			"Supplier, "
	  			"Date_install, "
	  			"Characteristics, "
	  			"Comment, " 
	  			"Parent "
	  			"FROM asset_list",db);
    this->refreshData();


}
myAssetsModel::~myAssetsModel()
/* */{
	delete q;
}

void myAssetsModel::refreshData()
/* For some reasons, model has changed, we should reload the data...
*/{
	q->exec();
	content.clear();
	while (q->next()){
		content.append(*new assetItem(
				 q->value(0).toString(), //Tag
				 q->value(1).toString(), //Location
				 q->value(2).toString(), //System
				 q->value(3).toString(), //subSystem
				 q->value(4).toString(), //Type
				 q->value(5).toString(), //subType
				 q->value(6).toString(), //description
				 q->value(7).toString(), //Supplier				 
				 QDate::fromString(q->value(8).toString(),"yyyy-MM-dd"), //Date_install
				 q->value(9).toString(),//Characteristics
				 q->value(10).toString(), //Comment
				 q->value(11).toString() //Parent
				 ));
		}
		
	
}

QVariant myAssetsModel::data(const QModelIndex &index, int role) const
/*struct assetItem{QString Tag;
						QString Location;
						QString System;
						QString subSystem;
						QString Type;
						QString subType;
						QString description;
						QString Supplier;
						QDate Date_install;
						QString Characteristics;
						QString Comment;
						QString Parent;
						};
*/{
    if (!index.isValid()) return QVariant();
    if (content.empty()) return QVariant();
    if (index.row() >= (int) content.size() || index.row() < 0) return QVariant();
    
    qDebug()<<"myTodoModel::data"<<endline;
    if (role == Qt::DisplayRole || role==Qt::ToolTipRole){
        switch (index.column()){
        	case 0:
       	 return content.at(index.row()).Tag;
        	 break;
       	case 1:
       	 return content.at(index.row()).Location;
        	 break;
        	case 2:
       	 return content.at(index.row()).System;
        	 break;
       	case 3:
       	 return content.at(index.row()).subSystem;
        	 break;
       	case 4:
       	 return content.at(index.row()).Type;
        	 break;
       	case 5:
       	 return content.at(index.row()).subType;
        	 break;
       	case 6:
       	 return content.at(index.row()).description;
        	 break;
       	case 7:
       	 return content.at(index.row()).Supplier;
        	 break;
       	case 8:
       	 return content.at(index.row()).Date_install;
        	 break;
       	case 9:
       	 return content.at(index.row()).Characteristics;
        	 break;
       	case 10:
       	 return content.at(index.row()).Comment;
        	 break;
       	case 11:
       	 return content.at(index.row()).Parent;
        	 break;
			}

     }
	return QVariant();
}

QString myAssetsModel::toString()
/*
*/{
return "myAssetModel";
}


///§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§


myLogModel::myLogModel(QSqlDatabase db, QUndoStack* _undo, QObject *parent) :
	myTableModel(db,_undo,parent)
/*-
*/{
	  q = new QSqlQuery("SELECT "
									"log_M.ID, "
									"asset, "
									"Action, "
									"Planned_date, "
									"Done, "
									"Actual_date, "
									"people.name, "
									"Comment "
									"FROM log_M INNER JOIN people ON (Executor=people.ID)",db);

    this->refreshData();
}

void myLogModel::refreshData()
/* For some reasons, model has changed, we should reload the data...
*/{
	q->exec();
	content.clear();
	while (q->next()){
		content.append(*new logItem(
				 q->value(0).toInt(),
				 q->value(1).toString(),
				 q->value(2).toString(),				 
				 QDate::fromString(q->value(3).toString(),"yyyy-MM-dd"),
				 q->value(4).toBool(),
				 QDate::fromString(q->value(5).toString(),"yyyy-MM-dd"),
				 q->value(6).toString(),
				 q->value(7).toString()
				 ));
		}
}
myLogModel::~myLogModel()
/* */{
	delete q;
}

QVariant myLogModel::data(const QModelIndex &index, int role) const
/*
						int ID;
						QString asset;
						QString Action;
						QDate Planned_date;
						bool Done;
						QDate Actual_date;
						QString Executor;
						QString Comment;

*/{
    if (!index.isValid()) return QVariant();
    if (content.empty()) return QVariant();
    if (index.row() >= (int) content.size() || index.row() < 0) return QVariant();
    
    qDebug()<<"myTodoModel::data"<<endline;
    if (role == Qt::DisplayRole || role==Qt::ToolTipRole){
        switch (index.column()){
        	case 0:
       	 return content.at(index.row()).ID;
        	 break;
       	case 1:
       	 return content.at(index.row()).asset;
        	 break;
        	case 2:
       	 return content.at(index.row()).Action;
        	 break;
       	case 3:
       	 return content.at(index.row()).Planned_date;
        	 break;
        	case 4:
       	 return content.at(index.row()).Done;
        	 break;
        	case 5:
       	 return content.at(index.row()).Actual_date;
        	 break;
        	case 6:
       	 return content.at(index.row()).Executor;
        	 break;
        	case 7:
       	 return content.at(index.row()).Comment;
        	 break;

			}
     }
	return QVariant();
}



QString myLogModel::toString()
/*
*/{
return "myLogModel";
}

