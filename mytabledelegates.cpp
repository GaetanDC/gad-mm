
#include <QtGui>
#include <QApplication>
#include <QDialog>

#include "mytabledelegates.h"

 MyTodoEditDelegate::MyTodoEditDelegate(QObject *parent)
     : QStyledItemDelegate(parent)
 {
 }


 void MyTodoEditDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
 {
     QStyleOptionButton button;
     QRect r = option.rect;//getting the rect of the cell
     int x,y,w,h;
     x = r.left() + r.width() - 30;//the X coordinate
     y = r.top();//the Y coordinate
     w = 30;//button width
     h = 30;//button height
     button.rect = QRect(x,y,w,h);
     button.text = "=^.^=";
     button.state = QStyle::State_Enabled;

     QApplication::style()->drawControl( QStyle::CE_PushButton, &button, painter);
 }

 bool MyTodoEditDelegate::editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index)
 {
 
 
     if( event->type() == QEvent::MouseButtonRelease )
     {
         QMouseEvent * e = (QMouseEvent *)event;
         int clickX = e->x();
         int clickY = e->y();

         QRect r = option.rect;//getting the rect of the cell
         int x,y,w,h;
         x = r.left() + r.width() - 30;//the X coordinate
         y = r.top();//the Y coordinate
       w = 30;//button width
         h = 30;//button height

         if( clickX > x && clickX < x + w )
             if( clickY > y && clickY < y + h )
             {
                 QDialog * d = new QDialog();
                 d->setGeometry(0,0,100,100);
                 d->show();
             }
     }

     return true;
 }
