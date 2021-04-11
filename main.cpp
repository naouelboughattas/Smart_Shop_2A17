#include "zeinebwindow.h"
#include <QApplication>
#include"connexion.h"
#include<QMessageBox>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    zeinebwindow w;

        connexion c;
        bool test=c.createconnect();
        if(test){
        //qDebug()<<"connexion etablie";

        QMessageBox::information(nullptr,QObject::tr("database is open"),
                                 QObject::tr("connexion etablie"),
                                 QMessageBox::Ok);
            w.show();}
        else{
        //qDebug()<<"connexion echouer";
        QMessageBox::critical(nullptr,QObject::tr("database is not open"),
                                QObject::tr("non connecter"),
                                QMessageBox::Cancel);}
         //qDebug()<<"connexion echouer";
    return a.exec();
}
