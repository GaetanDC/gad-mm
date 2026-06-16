#include "mylogmodel.h"
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

 myLogModel::myLogModel(QSqlDatabase _db, QUndoStack* _undo, QObject *parent):
 	QSqlRelationalTableModel(parent, _db)
/*
*/{
    setTable("Log_M");// = new QSqlQuery("ELECT ID,Asset,Action,DueDate FROM LOG_M WHERE (Done != 1)",db);
    setFilter("Done = 1");
//    this->refreshData();
	select();

	}

myLogModel::~myLogModel()
/* */{
}

int myLogModel::columnCount(const QModelIndex &parent) const
{
	return QSqlRelationalTableModel::columnCount(parent);
}

QVariant myLogModel::headerData(int section, Qt::Orientation orientation, int role) const
/*
*/{
    if(section>=QSqlRelationalTableModel::columnCount() && role == Qt::DisplayRole)
    	return " ";
    
    return QSqlRelationalTableModel::headerData(section, orientation, role);
}


QString myLogModel::toString()
/*
*/{
	return "myLogModel";
}

