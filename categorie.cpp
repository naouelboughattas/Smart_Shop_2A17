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

bool Categorie::ajouter_cat()
{
    QString id_string=QString::number(ID_cat);
    QSqlQuery query;
        query.prepare("INSERT INTO categorie (ID_cat, Nom_cat) "
                      "VALUES (:ID_cat, :Nom_cat)");
         query.bindValue(":ID_cat",ID_cat);
         query.bindValue(":Nom_cat",Nom_cat);
         return query.exec();
}
bool Categorie::supprimer_cat(int ID_cat)
{
    QSqlQuery query;
        query.prepare("Delete from categorie where ID_cat=:ID_cat");
        query.bindValue(":ID_cat",ID_cat);

         return query.exec();

}
QSqlQueryModel* Categorie::afficher_cat()
{
    QSqlQueryModel* model=new QSqlQueryModel();


    model->setQuery("SELECT* FROM categorie");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id Categorie"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom Categorie"));

    return model;
}
bool Categorie::modifier_cat(int ID_cat,QString Nom_cat)
{
    QSqlQuery query;
    query.prepare("UPDATE categorie SET Nom_cat= :Nom_cat WHERE ID_cat= :ID_cat");
    query.bindValue(":ID_cat",ID_cat);
    query.bindValue(":Nom_cat",Nom_cat);
    return query.exec();

}
QSqlQueryModel* Categorie::tri_cat()
{
    QSqlQueryModel* model=new QSqlQueryModel();


    model->setQuery("SELECT* FROM categorie ORDER BY ID_cat");//bich nbadalha
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id Produit"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom Produit"));

    return model;
}
QSqlQueryModel* Categorie::recherche_cat(QString r)
{
    QSqlQueryModel* model=new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("SELECT* FROM categorie WHERE ID_cat like '"+r+"' ||'%' OR Nom_cat like '"+r+"' ");
    query.bindValue(":id",r);
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id Produit"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom Produit"));

    return model;
}
QStringList Categorie::recherche_id_categorie(){
    QSqlQuery query;
    query.prepare("select ID_cat from CATEGORIE");
    query.exec();
    QStringList list;
    while(query.next()){
        list.append(query.value(0).toString());
    }

    return list;

}
