#include <QApplication>

#include <QDebug>
#include "def.h"
#include "mainwindow.h"

int main(int argc, char *argv[])
{
	qDebug()<<"Hello, debug mode."<<endline;
    QApplication appl(argc, argv);
    MainWindow w;
    appl.setWindowIcon(QIcon(":/icons/todour.png"));
    w.show();
    return appl.exec();
    

}


