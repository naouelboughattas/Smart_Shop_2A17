#include "categorie.h"
#include <QSqlQuery>
#include <QDebug>
#include <QObject>
#include <QTableView>

Categorie::Categorie()
{
    ID_cat=0; Nom_cat="";
}

Categorie::Categorie(int ID_cat,QString Nom_cat)
{   this->ID_cat=ID_cat;
    this->Nom_cat=Nom_cat;
}

int Categorie::getID_cat(){return ID_cat;}
QString Categorie::getNom_cat(){return Nom_cat;}

void Categorie::setID_cat(int ID_cat){ this->ID_cat=ID_cat;}
void Categorie::setNom_cat(QString Nom_cat){ this->Nom_cat=Nom_cat;}
bool Categorie::ajouter()
{
    QString id_string=QString::number(ID_cat);
    QSqlQuery query;
        query.prepare("INSERT INTO categorie (ID_cat, Nom_cat) "
                      "VALUES (:ID_cat, :Nom_cat)");
         query.bindValue(":ID_cat",ID_cat);
         query.bindValue(":Nom_cat",Nom_cat);
         return query.exec();
}
bool Categorie::supprimer(int ID_cat)
{
    QSqlQuery query;
        query.prepare("Delete from categorie where ID_cat=:ID_cat");
        query.bindValue(":ID_cat",ID_cat);

         return query.exec();

}
QSqlQueryModel* Categorie::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();


    model->setQuery("SELECT* FROM categorie");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id Categorie"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom Categorie"));

    return model;
}
bool Categorie::modifier(int ID_cat,QString Nom_cat)
{
    QSqlQuery query;
    query.prepare("UPDATE categorie SET Nom_cat= :Nom_cat WHERE ID_cat= :ID_cat");
    query.bindValue(":ID_cat",ID_cat);
    query.bindValue(":Nom_cat",Nom_cat);
    return query.exec();

}
