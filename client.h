#ifndef CLIENT_H
#define CLIENT_H
 #include<QString>
#include<QSqlQuery>
//#include <QPrinter>

#include"mainwindow.h"
#include"ui_mainwindow.h"
#include<QString>
#include<QSqlDatabase>
#include<QSqlError>
#include<QSqlQuery>
#include<QFileInfo>
#include<QMessageBox>
#include<QSqlQueryModel>
#include<QDebug>
#include<QFileDialog>
#include<QDialog>
#include<QtCore>
#include<QtGui>

class CLIENT
{
private:
    QString ID_CLIENT,nom,prenom,adresse,numero ;
public:
     CLIENT(QString,QString,QString,QString,QString);
    CLIENT();

    void setCin(QString n){ ID_CLIENT=n;}
     void setnom(QString n){ nom=n;}
      void setprenom(QString n){ prenom=n;}
       void setadresse(QString n){ adresse=n;}
        void setnum(QString n){ numero=n;}

           QString getCin(){return ID_CLIENT;}
           QString getnom(){return nom;}
           QString getprenom(){return prenom;}
           QString getadresse(){return adresse;}
           QString getnum(){return numero;}

            bool ajouterclient();
             bool modifierclient();
             void afficherclient(Ui::MainWindow *ui);
             void selectionnerclient(Ui::MainWindow *ui,const QModelIndex &index);
              bool supprimerclient(Ui::MainWindow *ui);
              void TRI1(Ui::MainWindow *ui);
              void TRI2(Ui::MainWindow *ui);
              void recherche(Ui::MainWindow *ui);
            void pdf();




};

#endif // CLIENT_H
