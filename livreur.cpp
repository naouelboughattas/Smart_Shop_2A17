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
    this->statue="";

}
livreur::livreur(QString cin,QString nom,QString pr,QString st)
{
    this->cin=cin;
    this->nom=nom;
    this->prenom=pr;
    this->statue=st;

}
bool livreur::ajouter_liv()
{
    QSqlQuery query;
    query.prepare("INSERT INTO livreur (cin,nom,prenom,statue) VALUES (:cin,:nom,:prenom,:statue)");
    query.bindValue(":cin",cin);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":statue",statue);
    return query.exec();
}
QSqlQueryModel * livreur::afficher_liv()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from livreur");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("statue"));

    return model;
}
QSqlQueryModel * livreur::afficher_id()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select matricule from vehicule");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("matricule"));
    return model;
}

bool livreur::modifier_liv(QString cin,QString st)
{
    QSqlQuery query;
    query.prepare("UPDATE livreur SET cin= :cin,statue = :statue  WHERE cin= :cin ");
    query.bindValue(":cin",cin);
     query.bindValue(":statue",st);

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
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("statue"));

        return model;
}
QSqlQueryModel * livreur::tri_liv()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM livreur ORDER BY nom");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("statue"));

    return model;
}

QStringList livreur::recherche_liv(){
    QSqlQuery query;
    query.prepare("select CIN from LIVREUR");
    query.exec();
    QStringList list;
    while(query.next()){
        list.append(query.value(0).toString());
    }

    return list;

}

bool livreur::resaisie_liv(QString cin,QString nom,QString pr)
{
    QSqlQuery query;
    query.prepare("UPDATE livreur SET cin= :cin,nom = :nom,prenom = :prenom  WHERE cin= :cin ");
    query.bindValue(":cin",cin);
     query.bindValue(":nom",nom);
     query.bindValue("prenom",pr);

    return    query.exec();
}


