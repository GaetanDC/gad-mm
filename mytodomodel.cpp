#include "mytodomodel.h"
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

 myTodoModel::myTodoModel(QSqlDatabase _db, QUndoStack* _undo, QObject *parent):
 	QSqlRelationalTableModel(parent, _db)
/*
*/{
    setTable("Log_M");// = new QSqlQuery("ELECT ID,Asset,Action,DueDate FROM LOG_M WHERE (Done != 1)",db);
    setFilter("Done != 1");
	setRelation(1, QSqlRelation("asset_list", "tag", "tag"));
	setRelation(2, QSqlRelation("Actions", "tag", "tag"));
	select();

	}

myTodoModel::~myTodoModel()
/* */{
//	delete q;
}

int myTodoModel::columnCount(const QModelIndex &parent) const
{
	return QSqlRelationalTableModel::columnCount(parent)+2;
}

QVariant myTodoModel::headerData(int section, Qt::Orientation orientation, int role) const
/*
*/{
    if(section>=QSqlRelationalTableModel::columnCount() && role == Qt::DisplayRole)
    	return " ";
    
    return QSqlRelationalTableModel::headerData(section, orientation, role);
}


QString myTodoModel::toString()
/*
*/{
	return "myTodoModel";
}

