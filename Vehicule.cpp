#include "Vehicule.h"
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDialog>

vehicule::vehicule()
{
    this->matricule="";
    this->marque="";
    this->couleur="";
    this->date_ent="";

}
vehicule::vehicule(QString mat,QString marq,QString col,QString de)
{
    this->matricule=mat;
    this->marque=marq;
    this->couleur=col;
    this->date_ent=de;

}
bool vehicule::ajouter_veh()
{
    QSqlQuery query;
    query.prepare("INSERT INTO vehicule (matricule,marque,couleur,date_ent) VALUES (:matricule,:marque,:couleur,:date_ent)");
    query.bindValue(":matricule",matricule);
    query.bindValue(":marque",marque);
    query.bindValue(":couleur",couleur);
    query.bindValue(":date_ent",date_ent);
    return query.exec();
}
QSqlQueryModel * vehicule::afficher_veh()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from vehicule");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("matricule"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("marque"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("couleur"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("date_ent"));

    return model;
}
QSqlQueryModel * vehicule::afficher_id()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select matricule from vehicule");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("matricule"));
    return model;
}

bool vehicule::modifier_veh(QString mat,QString marq,QString col,QString de)
{
    QSqlQuery query;
    query.prepare("UPDATE vehicule SET matricule= :matricule,marque = :marque,couleur = :couleur,date_ent = :date_ent  WHERE matricule= :matricule ");
    query.bindValue(":matricule",mat);
    query.bindValue(":marque",marq);
    query.bindValue(":couleur",col);
     query.bindValue(":date_ent",de);

    return    query.exec();
}
bool vehicule::supprimer_veh(QString idd)
{
    QSqlQuery query;

    query.prepare("Delete from vehicule where matricule = :id ");
    query.bindValue(":id", idd);
    return    query.exec();
}
QSqlQueryModel * vehicule::rechercher_veh_dynamique(QString a)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("SELECT * FROM vehicule where matricule like '"+a+"' ||'%'");
    query.bindValue(":id",a);
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("matricule"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("marque"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("couleur"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("date_ent"));

        return model;
}
QSqlQueryModel * vehicule::tri_veh()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM vehicule ORDER BY matricule");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("matricule"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("marque"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("couleur"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("date_ent"));

    return model;
}
