#ifndef MYASSETSMODEL_H
#define MYASSETSMODEL_H


#include <QStyledItemDelegate>
#include <QSqlDatabase>
#include <QString>
#include <QDate>
#include <QModelIndex>
#include <QSqlQuery>
#include <QUndoStack>
#include <QSqlRelationalTableModel>

						
class myAssetsModel : public QSqlRelationalTableModel{
    Q_OBJECT
protected:

public:
    explicit myAssetsModel(QSqlDatabase db, QUndoStack* _undo, QObject *parent = 0);
    ~myAssetsModel();
	QString toString();
 	 int columnCount(const QModelIndex &parent) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;

protected:

         QUndoStack* undoS;

public slots:
};


#endif //#ifndef MYASSETSMODEL_H
