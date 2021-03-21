#include "Livreur.h"
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDialog>

livreur::livreur()
{
    this->cin="";
    this->nom="";
    this->prenom="";
    this->date_amb="";

}
livreur::livreur(QString cin,QString nom,QString pr,QString da)
{
    this->cin=cin;
    this->nom=nom;
    this->prenom=pr;
    this->date_amb=da;

}
bool livreur::ajouter_liv()
{
    QSqlQuery query;
    query.prepare("INSERT INTO livreur (cin,nom,prenom,date_amb) VALUES (:cin,:nom,:prenom,:date_amb)");
    query.bindValue(":cin",cin);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":date_amb",date_amb);
    return query.exec();
}
QSqlQueryModel * livreur::afficher_liv()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from livreur");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("date_amb"));

    return model;
}
QSqlQueryModel * livreur::afficher_id()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select matricule from vehicule");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("matricule"));
    return model;
}

bool livreur::modifier_liv(QString cin,QString nom,QString pr,QString da)
{
    QSqlQuery query;
    query.prepare("UPDATE livreur SET cin= :cin,nom = :nom,prenom = :prenom,date_amb = :date_amb  WHERE cin= :cin ");
    query.bindValue(":cin",cin);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",pr);
     query.bindValue(":date_amb",da);

    return    query.exec();
}
bool livreur::supprimer_liv(QString idd)
{
    QSqlQuery query;

    query.prepare("Delete from livreur where cin = :id ");
    query.bindValue(":id", idd);
    return    query.exec();
}
QSqlQueryModel * livreur::rechercher_liv_dynamique(QString a)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("SELECT * FROM livreur where cin like '"+a+"' ||'%'");
    query.bindValue(":id",a);
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("date_amb"));

        return model;
}
QSqlQueryModel * livreur::tri_liv()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM livreur ORDER BY nom");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("date_amb"));

    return model;
}
