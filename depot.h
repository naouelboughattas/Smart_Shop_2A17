#ifndef DEPOT_H
#define DEPOT_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>

class depot
{
private:
    QString nom,adresse,capacite;
public:
    depot(QString,QString,QString);
    depot();

       void setnomd(QString n){ nom=n;}
       void setadresse(QString n){ adresse=n;}
       void setcapacite(QString n){ capacite=n;}




         QString getnomd(){return nom;}
         QString getadresse(){return adresse;}
         QString getcapacite(){return capacite;}

          bool ajouterdepot();
          bool supprimerdepot(QString nom);
          bool modifierdepot(QString nom, QString adresse,QString capacite);
          QSqlQueryModel * afficherdepot();//affichage normal
          bool  search(QString );
          QSqlQueryModel *sort1();
          static QSqlQueryModel * afficher1();//affichage sur combobox
          void pdf();

};
#endif // DEPOT_H
