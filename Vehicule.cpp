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

}
vehicule::vehicule(QString mat,QString marq,QString col)
{
    this->matricule=mat;
    this->marque=marq;
    this->couleur=col;

}
bool vehicule::ajouter_veh()
{
    QSqlQuery query;
    query.prepare("INSERT INTO vehicule (matricule,marque,couleur) VALUES (:matricule,:marque,:couleur)");
    query.bindValue(":matricule",matricule);
    query.bindValue(":marque",marque);
    query.bindValue(":couleur",couleur);
    return query.exec();
}
QSqlQueryModel * vehicule::afficher_veh()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from vehicule");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("matricule"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("marque"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("couleur"));

    return model;
}
QSqlQueryModel * vehicule::afficher_id()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select matricule from vehicule");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("matricule"));
    return model;
}

bool vehicule::modifier_veh(QString mat,QString marq,QString col)
{
    QSqlQuery query;
    query.prepare("UPDATE vehicule SET matricule= :matricule,marque = :marque,couleur = :couleur  WHERE matricule= :matricule ");
    query.bindValue(":matricule",mat);
    query.bindValue(":marque",marq);
    query.bindValue(":couleur",col);

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

        return model;
}
QSqlQueryModel * vehicule::tri_veh()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM vehicule ORDER BY matricule");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("matricule"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("marque"));

    model->setHeaderData(3, Qt::Horizontal, QObject::tr("couleur"));

    return model;
}
