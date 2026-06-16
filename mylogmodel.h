#ifndef MYLOGMODEL_H
#define MYLOGMODEL_H

#include <QDate>
#include <QString>
#include <QSqlQuery>
#include <QUndoStack>
#include <QModelIndex>
#include <QSqlRelationalTableModel>


class myLogModel :public QSqlRelationalTableModel{
    Q_OBJECT

public:
    explicit myLogModel(QSqlDatabase db, QUndoStack* _undo, QObject *parent = 0);
    ~myLogModel();
	QString toString();
   int columnCount(const QModelIndex &parent) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;

protected:
         QUndoStack* undoS;

public slots:
};


#endif //#ifndef MYLOGMODEL_H
