#include <QApplication>
#include <QMessageBox>
#include <QPushButton>
#include <QDebug>

#include "mytabledelegates.h"

/*
\uf040 draws a pencil, like "editor"
\uf1f8 draws a trash, like "delete"
\uf05d draws a V, like "done"
*/


myEditDelegate::myEditDelegate(QObject *parent)
     : QStyledItemDelegate(parent)
{
qDebug()<<"myEditDelegate creator"<<Qt::endl;
}

QSize myEditDelegate::sizeHint(const QStyleOptionViewItem &option,const QModelIndex &index) const
{
	return QSize(25,25);
}

void myEditDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
 {
     QStyleOptionButton button;
     QRect r = option.rect;//getting the rect of the cell
     int x,y,w,h;
     x = r.left() + r.width() - 25;//the X coordinate
     y = r.top();//the Y coordinate
     w = 25;//button width
     h = 25;//button height
     button.rect = QRect(x,y,w,h);
	button.text = "\uf040";
     button.state = QStyle::State_Enabled;

     QApplication::style()->drawControl( QStyle::CE_PushButton, &button, painter);
 }

bool myEditDelegate::editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index)
 {


   QMessageBox * d = new QMessageBox(QMessageBox::Warning,
      "Edit",/*title*/
      "Here we should launch the editor, with indput data...", /*text*/
      QMessageBox::Yes | QMessageBox::No /*Buttons*/
      );
   d->exec();

     return true;
 }

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
myDeleteDelegate::myDeleteDelegate(QObject *parent)
     : QStyledItemDelegate(parent)
{
}

QSize myDeleteDelegate::sizeHint(const QStyleOptionViewItem &option,const QModelIndex &index) const
{
	return QSize(25,25);
}

void myDeleteDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
 {
     QStyleOptionButton button;
     QRect r = option.rect;//getting the rect of the cell
     int x,y,w,h;
     x = r.left() + r.width() - 25;//the X coordinate
     y = r.top();//the Y coordinate
     w = 25;//button width
     h = 25;//button height
     button.rect = QRect(x,y,w,h);
	button.text = "\uf1f8";
     button.state = QStyle::State_Enabled;

     QApplication::style()->drawControl( QStyle::CE_PushButton, &button, painter);
 }


bool myDeleteDelegate::editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index)
 {
                  QMessageBox * d = new QMessageBox(QMessageBox::Warning,
                 		"Are you sure?",/*title*/
                 		"You are about to delete this line, confirm?", /*text*/
                 		QMessageBox::Yes | QMessageBox::No /*Buttons*/
                 		);
                 d->exec();
     return true;

 }

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

myDoneDelegate::myDoneDelegate(QObject *parent)
     : QStyledItemDelegate(parent)
{
qDebug()<<"myDoneDelegate creator"<<Qt::endl;
}

QSize myDoneDelegate::sizeHint(const QStyleOptionViewItem &option,const QModelIndex &index) const
{
	return QSize(25,25);
}

void myDoneDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
 {
     QStyleOptionButton button;
     QRect r = option.rect;//getting the rect of the cell
     int x,y,w,h;
     x = r.left() + r.width() - 25;//the X coordinate
     y = r.top();//the Y coordinate
     w = 25;//button width
     h = 25;//button height
     button.rect = QRect(x,y,w,h);
   button.text = "\uf05d";
     button.state = QStyle::State_Enabled;

     QApplication::style()->drawControl( QStyle::CE_PushButton, &button, painter);
 }

bool myDoneDelegate::editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index)
 {
 
 
                  QMessageBox * d = new QMessageBox(QMessageBox::Warning,
                 		"Edit",/*title*/
                 		"Here we should set the task closed. confirm-window???", /*text*/
                 		QMessageBox::Yes | QMessageBox::No /*Buttons*/
                 		);
                 d->exec();
     return true;
 }
