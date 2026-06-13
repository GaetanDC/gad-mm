#ifndef ABOUTBOX_H
#define ABOUTBOX_H

#include <QDialog>

#include "ui_aboutbox.h"


class AboutBox : public QDialog
{
    Q_OBJECT

public:
    explicit AboutBox(QWidget *parent = 0);
    inline ~AboutBox(){    delete ui;};

private:
    Ui::AboutBox *ui;
};





#endif // ABOUTBOX_H
