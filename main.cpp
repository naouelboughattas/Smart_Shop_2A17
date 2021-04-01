#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include <QDebug>
#include "connection.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Connection c;
    bool test=c.createconnection();

    MainWindow w;
w.show();
   /* if(test)
    {


        QMessageBox::information(nullptr,QObject::tr("database is open"),QObject::tr("connection successful.\n""Click Cancel to exit."),QMessageBox::Cancel);
    }*/
    if(test==false) //else
        QMessageBox::critical(nullptr,QObject::tr("database is not open"),QObject::tr("connection failed.\n"),QMessageBox::Cancel);

    return a.exec();
}
