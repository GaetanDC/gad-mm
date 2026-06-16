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


//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 myTodoModel::myTodoModel(QSqlDatabase db, QUndoStack* _undo, QObject *parent):
 	myTableModel(db, _undo, parent)
/*
*/{
	max_col_num=5;
    q = new QSqlQuery("SELECT tag,Action,DueD FROM Planning",db);
    	// q = new QSqlQuery("SELECT asset,Action, DueD FROM log_M WHERE (Done != 1)",db);
    	
    this->refreshData();
	}

myTodoModel::~myTodoModel()
/* */{
	delete q;
}
QVariant myTodoModel::headerData(int section, Qt::Orientation orientation, int role) const
/*
*/{
    if(orientation==Qt::Vertical || role != Qt::DisplayRole) return QVariant();
    switch (section){
      case 0: return "Tag";
      case 1: return "Action";
      case 2: return "Due Date";
            default: return QVariant();
    }
    return QVariant();
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
    
//    qDebug()<<"myTodoModel::data"<<endline;
    if (role == Qt::DisplayRole || role==Qt::ToolTipRole){
        switch (index.column()){
        	case 0: return content.at(index.row()).asset;
       	case 1: return content.at(index.row()).action;
       	case 2: return content.at(index.row()).dueDate;
			}

     }
	return QVariant();
}


bool myTodoModel::setData(const QModelIndex & index, const QVariant & value, int role)
/* */
{
// TODO Manage here the undo stacks
// TODO Define some UserRole+11 to delete the item
//			+ define UserRole+12 to says "item done".  Item done means
//				add in log table  /  remove to flag from the record
//				remove the line from the todo  /  do nothing if flag removed
//				update the display

}
Qt::ItemFlags myTodoModel::flags(const QModelIndex& index) const
/**/{

  return QAbstractItemModel::flags(index) | Qt::ItemIsEditable | Qt::ItemNeverHasChildren;

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
	 max_col_num=14;	
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
QVariant myAssetsModel::headerData(int section, Qt::Orientation orientation, int role) const
/*
*/{
    if(orientation==Qt::Vertical || role != Qt::DisplayRole) return QVariant();
    switch (section){
      case 0: return "Tag";
      case 1: return "Location";
      case 2: return "Sytem";
      case 3: return "Sub-system";
      case 4: return "Type";
      case 5: return "Sub-Type";
      case 6: return "Description";
      case 7: return "Supplier";
      case 8: return "Install Date";
      case 9: return "Characteristics";
      case 10: return "Comment";
      default: return QVariant();
    }
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
    
//    qDebug()<<"myTodoModel::data"<<endline;
    if (role == Qt::DisplayRole || role==Qt::ToolTipRole){
        switch (index.column()){
        	case 0:       	 return content.at(index.row()).Tag;
        	case 1:       	 return content.at(index.row()).Location;
        	case 2:       	 return content.at(index.row()).System;
       	case 3:       	 return content.at(index.row()).subSystem;
       	case 4:       	 return content.at(index.row()).Type;
       	case 5:       	 return content.at(index.row()).subType;
       	case 6:       	 return content.at(index.row()).description;
       	case 7:       	 return content.at(index.row()).Supplier;
       	case 8:       	 return content.at(index.row()).Date_install;
       	case 9:       	 return content.at(index.row()).Characteristics;
       	case 10:        return content.at(index.row()).Comment;
       	case 11:        return content.at(index.row()).Parent;
       	      default: return QVariant();
			}

     }
	return QVariant();
}

bool myAssetsModel::setData(const QModelIndex & index, const QVariant & value, int role)
/* */
{
// TODO Manage here the undo stacks
// TODO Define some UserRole+11 to delete the item
//			+ define UserRole+12 to says "edit item". We should then open a window.
// IDEA: can I use a specifi window as an Editor?  Then to be used as an editor from delegate.
//	IDEA: Do I need the "window" to edit?  I can just say that the tag is read-only, get all the other modifications from the table, with right "delegates and editors" to ensure validity.

//	The issue is with the sub-table of default actions...

	//update display
}
Qt::ItemFlags myAssetsModel::flags(const QModelIndex& index) const
/**/{

  return QAbstractItemModel::flags(index) | Qt::ItemIsEditable | Qt::ItemNeverHasChildren;

}

QString myAssetsModel::toString()
/*
*/{
return "myAssetModel";
}


///§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§



