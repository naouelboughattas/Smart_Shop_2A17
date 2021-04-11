#ifndef ABONNEMENT_H
#define ABONNEMENT_H
#include<QString>
#include<QSqlQuery>
#include"mainwindow.h"
#include"ui_mainwindow.h"
#include<QSqlQueryModel>

class abonnement
{
private:
    QString id,cinabo,type;
public:
    abonnement(QString,QString,QString);
    abonnement();

    void setId(QString n){ id=n;}
    void setCinabo(QString n){ cinabo=n;}
    void settype(QString n){ type=n;}

     QString getId(){return id;}
      QString getCinabo(){return cinabo;}
       QString gettype(){return type;}

       bool ajouterabonnement();
        bool modifierabonnement();
        void afficherabonnement(Ui::MainWindow *ui);
        void selectionnerabonnement(Ui::MainWindow *ui,const QModelIndex &index);
         bool supprimerabonnement(Ui::MainWindow *ui);
};

#endif // ABONNEMENT_H
