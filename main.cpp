#include "zeinebwindow.h"
#include <QApplication>
#include"connexion.h"
#include<QMessageBox>
#include<QtCore/QCoreApplication>
#include<QFile>
#include<QString>
#include<QDebug>
#include<QTextStream>

void Read(QString MyFiles)
{
    QFile mFile(MyFiles);
if (!mFile.open(QFile::ReadOnly | QFile::Text))
{
    qDebug() <<"could not open file for read";
   return;
}
QTextStream in (&mFile);
QString mText = in.readAll();
qDebug() << mText;
mFile.close();
}
int main(int argc, char *argv[])
{   Read(";/MyFiles/zeinebproj.pro");
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
