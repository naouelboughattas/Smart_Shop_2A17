#include "tache.h"
#include "connexion.h"
#include <QSqlQuery>
#include <QtDebug>

tache::tache()
{
id="";
}
tache::tache(QString id,QString descri,QDateTime duree)
{
    this->id=id; this->descri=descri; this->duree=duree;

}
QString tache::getid()
{
    return  id;
}
QString tache::getdescri()
{
    return  descri;
}
QDateTime tache::getduree()
{
    return  duree;
}

void tache:: setid(QString id)
{
    this->id=id;
}
void tache::setdescri(QString descri)
{
    this->descri=descri;
}
void tache::setduree(QDateTime duree)
{
    this->duree=duree;
}

bool tache:: ajouter_tache()
{
    QSqlQuery query;
    QString id_string = id;

    query.prepare("INSERT INTO tache (id,descri,duree) " "VALUES (:id,:descri,:duree)");
    query.bindValue(":id",id);
    query.bindValue(":descri",descri);
    query.bindValue(":duree",duree);


    return    query.exec();

}


bool tache::supprimer_tache()
{

    QSqlQuery query;
    query.prepare("DELETE FROM tache WHERE id = :id ");
    query.bindValue(":id",id);
    return    query.exec();

}
QSqlQueryModel * tache:: afficher_tache()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("SELECT * FROM tache");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("descri"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("duree"));

    return model;
}

 bool tache::modifier_tache()
 {      QSqlQuery query;
        query.prepare("UPDATE tache SET descri=:descri,duree=:duree WHERE id=:id");
        query.bindValue(":id",id);
        query.bindValue(":descri",descri);
        query.bindValue(":duree",duree);
        return    query.exec();

}
 void tache:: chercher()
 {    QSqlQuery query1;
      query1.prepare("SELECT descri,duree FROM tache WHERE id =:id");
      query1.bindValue(":id",id);
      query1.exec();
      while(query1.next())
      {
      descri = query1.value(0).toString();
      duree = query1.value(1).toDateTime();

      }

 }

 QSqlQueryModel * tache:: afficher_liste()
 {
     QSqlQueryModel * model= new QSqlQueryModel();

         model->setQuery("SELECT id FROM tache");
         model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));


             return model;
 }
 QSqlQueryModel *tache:: tri_tache()
 {
     QSqlQueryModel * model= new QSqlQueryModel();
     model->setQuery("SELECT * FROM tache ORDER BY descri");
     model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
     model->setHeaderData(1,Qt::Horizontal,QObject::tr("descri"));
     model->setHeaderData(2,Qt::Horizontal,QObject::tr("duree"));
        return model;
 }



 QSqlQueryModel * tache:: recherche (QString a)
 {
     QSqlQueryModel * model= new QSqlQueryModel();
     QSqlQuery query;
     query.prepare("SELECT * FROM tache WHERE id LIKE '"+a+"' ||'%'");
     query.bindValue(":id",a);
     query.exec();
     model->setQuery(query);
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
     model->setHeaderData(1,Qt::Horizontal,QObject::tr("descri"));
     model->setHeaderData(2,Qt::Horizontal,QObject::tr("duree"));

         return model;

 }
