#ifndef MYTABLEDELEGATES_H
#define MYTABLEDELEGATES_H


#include <QStyledItemDelegate>

class MyTodoEditDelegate : public QStyledItemDelegate
{
    Q_OBJECT
    
public:
    MyTodoEditDelegate(QObject *parent = 0);
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    bool editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index);
};


#endif // MYTABLEDELEGATES_H
