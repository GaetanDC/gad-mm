#ifndef MYTABLEDELEGATES_H
#define MYTABLEDELEGATES_H


#include <QStyledItemDelegate>
#include <QSqlRelationalDelegate>


class myEditDelegate : public QStyledItemDelegate
{
    Q_OBJECT
    
public:
    myEditDelegate(QObject *parent = 0);
        
   void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
   bool editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index);     
	QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const;
     
protected:

};

class myDeleteDelegate : public QStyledItemDelegate
{
    Q_OBJECT
    
public:
    myDeleteDelegate(QObject *parent = 0);
    
   void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    bool editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index);
    
    	QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const;

protected:

};

class myDoneDelegate : public QStyledItemDelegate
{
    Q_OBJECT
    
public:
    myDoneDelegate(QObject *parent = 0);
    
   void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    bool editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index);
    
    	QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const;

protected:

};

#endif // MYTABLEDELEGATES_H
