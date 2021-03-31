#include "Livraison.h"
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDialog>


livraison::livraison()
{
    this->id_liv=0;
    this->nom_c="";
    this->adresse="";
    this->livreur="";

}

livraison::livraison(int idl,QString nc,QString ad,QString li)
{
    this->id_liv=idl;
    this->nom_c=nc;
    this->adresse=ad;
    this->livreur=li;
}

QSqlQueryModel * livraison::afficher_livraison()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("SELECT NOM_C,ADRESSE,TTC_F FROM FACTURES,CLIENT where FACTURES.ID_C=CLIENT.ID_C");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Non Client"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Adresse"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Total Facture"));

    return model;
}
