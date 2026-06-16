#ifndef MYTODOMODEL_H
#define MYTODOMODEL_H

#include <QSqlRelationalTableModel>
#include <QUndoStack>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QString>
#include <QDate>
#include <QStyledItemDelegate>


class myTodoModel : public QSqlRelationalTableModel{
    Q_OBJECT
public:
   explicit myTodoModel(QSqlDatabase, QUndoStack*, QObject *parent = 0);
   ~myTodoModel();
	QString toString();
//	inline int rowCount(const QModelIndex &parent) const {Q_UNUSED(parent) return content.size();};
 	 int columnCount(const QModelIndex &parent) const;
//	virtual QVariant data(const QModelIndex &index, int role) const;
//	virtual bool setData(const QModelIndex & index, const QVariant & value, int role);
//    Qt::ItemFlags flags(const QModelIndex& index) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;



protected:
   QUndoStack* undoS;
	
public slots:

};


/*

class myTodoDelegate : public QStyledItemDelegate
{
    Q_OBJECT
        
public:
    myTodoDelegate(QObject *parent = 0);
        
   void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
   bool editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index);     
	QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const;
     
     
     
	virtual QWidget *	createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const override;

	virtual void 	setEditorData(QWidget *editor, const QModelIndex &index) const override;
	virtual void 	setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const override;

protected:

};
*/


#endif // MYTODMODELS_H
