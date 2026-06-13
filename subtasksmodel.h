#ifndef SUBTASKSMODEL_H
#define SUBTASKSMODEL_H

#include <QAbstractTableModel>
#include <QMouseEvent>
#include "task.h"
#include <QUndoStack>
#include <vector>
#include "taskset.h"
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QList>


//TODO: consider inherting from QAbstractTableModel instead of QSqlTableModel

class subtasksTableModel : public QSqlTableModel{
    Q_OBJECT
protected:
	taskset* tasklist;
public:
    explicit subtasksTableModel(taskset* _tasklist,QUndoStack* _undo, QSqlDatabase db, QObject *parent = 0);
    ~subtasksTableModel();
    int columnCount(const QModelIndex &parent) const;
	 int rowCount(const QModelIndex &parent) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    Qt::ItemFlags flags(const QModelIndex& index) const;
//	 inline task* getTask(QModelIndex index) {return (tasklist->at(index.row()));};
	QVariant data(const QModelIndex &index, int role) const;
	bool setData(const QModelIndex & index, const QVariant & value, int role);

    void refresh();    
//    void refreshActive(); //cycle through all task to recalculate the active state
	QString toString();
	
	 void safeComplete(const QModelIndex & index, bool state);
	 void safeEdit(const QModelIndex & index, QString _raw);
    void safeAdd(QString title, QString context);
    void safeDelete(QUuid index);

	void startModelChange(QString desc);
	void endModelChange();
	inline int getParentTask() {return parentTask;};

public slots:
	void setParentTask(int i);

protected:

private:
	QUndoStack* undoS;
	int parentTask;
	QSqlQuery q;
	QList<subtask> subtaskList;
	
};

#endif //#ifndef TODO_PROXYMODEL_H
