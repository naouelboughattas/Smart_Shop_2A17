#ifndef STOCK_H
#define STOCK_H
#include<QString>
#include<QSqlQuery>
//#include"zeinebwindow.h"
//#include"ui_zeinebwindow.h"
#include<QSqlQueryModel>

class STOCK
{
private:
    QString nomp,quantite,referencep,noms,references ;
public:
     STOCK(QString,QString,QString,QString,QString);
    STOCK();

    void setnomp(QString n){ nomp=n;}
     void setquantite(QString n){ quantite=n;}
      void setreferencep(QString n){ referencep=n;}
       void setnoms(QString n){ noms=n;}
        void setreferences(QString n){ references=n;}

           QString getnomp(){return nomp;}
           QString getquantite(){return quantite;}
           QString getreferencep(){return referencep;}
           QString getnoms(){return noms;}
           QString getreferences(){return references;}
           QString recherche_id_produit(QString);

            bool ajouterproduit();
             bool modifierstock(QString nomp, QString quantite,QString referencep,QString noms,QString references);
             QSqlQueryModel * afficherstock();
             static QSqlQueryModel * afficher1();

//         void selectionnerstock(Ui::zeinebwindow *ui,const QModelIndex &index);
              bool supprimerstock(QString);
              bool  search(QString nomp );

              QSqlQueryModel *sort1();
                  QSqlQueryModel *sort2();
              void TRI1();
              void TRI2();
              void recherche();
              void pdf();





};
#endif // STOCK_H
