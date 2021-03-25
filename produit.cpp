#include "produit.h"
#include <QSqlQuery>
#include <QDebug>
#include <QObject>
#include <QTableView>

Produit::Produit()
{id_P=0; nom_P=""; type=""; prix=0;
}

Produit::Produit(int id_P,QString nom_P,QString type,int prix)
{   this->id_P=id_P;
    this->nom_P=nom_P;
    this->type=type;
    this->prix=prix;
}

int Produit::getid_P(){return id_P;}
QString Produit::getnom_P(){return nom_P;}
QString Produit::gettype(){return type;}
int Produit::getprix(){return prix;}

void Produit::setid_P(int id_P){ this->id_P=id_P;}
void Produit::setnom_P(QString nom_P){ this->nom_P=nom_P;}
void Produit::settype(QString type){ this->type=type;}
void Produit::setprix(int prix){ this->prix=prix;}
bool Produit::ajouter()
{
    QString id_string=QString::number(id_P);
    QSqlQuery query;
        query.prepare("INSERT INTO produit (id_P, nom_P, type,prix) "
                      "VALUES (:id_P, :nom_P, :type, :prix)");
         query.bindValue(":id_P",id_P);
         query.bindValue(":nom_P",nom_P);
         query.bindValue(":type",type);
         query.bindValue(":prix",prix);
         return query.exec();
}
bool Produit::supprimer(int id_P)
{
    QSqlQuery query;
        query.prepare("Delete from produit where id_P=:id_P ");
         query.bindValue(":id_P",id_P);

         return query.exec();

}
QSqlQueryModel* Produit::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();


    model->setQuery("SELECT* FROM produit");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id Produit"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom Produit"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Type Produit"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Prix Produit"));

    return model;
}
bool Produit::modifier(int id_P,QString nom_P,QString type,int prix)
{
    QSqlQuery query;
    query.prepare("UPDATE produit SET nom_P= :nom_P,type= :type,prix= :prix WHERE id_P= :id_P");
    query.bindValue(":id_P",id_P);
    query.bindValue(":nom_P",nom_P);
    query.bindValue(":type",type);
    query.bindValue(":prix",prix);
    return query.exec();

}
