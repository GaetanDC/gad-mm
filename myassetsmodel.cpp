#include "myassetsmodel.h"
#include "def.h"

#include <QFont>
#include <QRegularExpression>
#include <QDebug>
#include <QList>
#include <QMessageBox>
#include <QApplication>
#include <QComboBox>
#include <QDateEdit>


//#include "todo_undo.h"

 myAssetsModel::myAssetsModel(QSqlDatabase _db, QUndoStack* _undo, QObject *parent):
 	QSqlRelationalTableModel(parent, _db)
/*
*/{
    setTable("asset_list");
//    setFilter("Done != 1");
//    this->refreshData();
	select();

	}

myAssetsModel::~myAssetsModel()
/* */{

}

int myAssetsModel::columnCount(const QModelIndex &parent) const
{
	return QSqlRelationalTableModel::columnCount(parent)+2;
}

QVariant myAssetsModel::headerData(int section, Qt::Orientation orientation, int role) const
/*
*/{
    if(section>=QSqlRelationalTableModel::columnCount() && role == Qt::DisplayRole)
    	return " ";
    
    return QSqlRelationalTableModel::headerData(section, orientation, role);
}


QString myAssetsModel::toString()
/*
*/{
	return "myAssetsModel";
}


