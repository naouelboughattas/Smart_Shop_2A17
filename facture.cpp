#include "facture.h"
#include <QSqlQuery>
#include <QDebug>
#include <QObject>
#include <QTableView>
#include <QDateTime>
#include <QDate>
#include <QTime>
#include <QSqlRecord>


Facture::Facture()
{
id_f="";
date_f=QDateTime(QDate(2000,01,01),QTime(00,00,00));
ttc_f="";
}
Facture::Facture(QString id_f,QDateTime date_f,QString ttc_f){
    this->id_f=id_f;
    this->date_f=date_f;
    this->ttc_f=ttc_f;

}
QString Facture::getid_f(){
    return id_f;
}
QDateTime Facture::getdate_f(){
    return date_f;
}
QString Facture::getttc_f(){
    return ttc_f;
}
void Facture::setid_f(QString id_f){
    this->id_f=id_f;
}
void Facture::setdate_f(QDateTime date_f){
    this->date_f=date_f;
}
void Facture::setttc_f(QString ttc_f){
    this->ttc_f=ttc_f;
}
bool Facture::ajouter(){
    bool test=true;
    QSqlQuery query;
    QString id_string= id_f;
          query.prepare("INSERT INTO FACTURES (ID_F, DATE_F, TTC_F) "
                        "VALUES (:id_f, :forename, :surname)");
          query.bindValue(":id_f", id_string);
          query.bindValue(":forename", date_f);
          query.bindValue(":surname", ttc_f);
          query.exec();
    return test;
}
QSqlQueryModel *Facture::afficher(){
    QSqlQueryModel* model=new QSqlQueryModel();

          model->setQuery("SELECT * FROM FACTURES");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("Référence de facture"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("Date de facture"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("Total TTC"));
          return model;
}
bool Facture::supprimer(QString id_f){
    QSqlQuery query;

    query.prepare("DELETE FROM FACTURES WHERE ID_F = :id_f ");
    query.bindValue(":id_f", id_f);
    return    query.exec();
}
bool Facture::modifier(QString id_f,QDateTime date_f,QString ttc_f)
{
    QSqlQuery query;
    query.prepare("UPDATE FACTURES SET date_f= :date_f,ttc_f = :ttc_f WHERE id_f= :id_f ");
    query.bindValue(":id_f",id_f);
    query.bindValue(":date_f",date_f);
    query.bindValue(":ttc_f",ttc_f);
    return    query.exec();
}
QSqlQueryModel * Facture::rechercher(QString a)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("SELECT * FROM FACTURES where ID_F like '"+a+"' ||'%' OR DATE_F like '"+a+"' ||'%' OR TTC_F like '"+a+"' ||'%'");
    query.bindValue(":id",a);
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Référence de facture"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Date de facture"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Total TTC"));
    return model;
}
QSqlQueryModel * Facture::tri()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM FACTURES ORDER BY ID_F");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Référence de facture"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Date de facture"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Total TTC"));
    return model;
}

QStringList Facture::recherche_id(){
    QSqlQuery query;
    query.prepare("select * from FACTURES ORDER BY ID_F ASC");
    query.exec();
    QStringList list;
    while(query.next()){
        list.append(query.value(0).toString());
    }

    return list;

}

Facture Facture::search_id(QString id_f){
    QSqlQuery query;
    query.prepare("select *from FACTURES where ID_F=:id_f");
    query.bindValue(":ID_F",id_f);
    query.exec();
    Facture p;
    while(query.next()){
        p.setid_f(query.value(0).toString());
        p.setdate_f(query.value(1).toDateTime());
        p.setttc_f(query.value(2).toString());

    }


    return p;
}


QString Facture::COUNT_FACT(){
    QSqlQuery query; int l=0;
    query.prepare("select count(*) from FACTURES ORDER BY ID_F ASC");
    query.exec();
    while(query.last()){
        l=query.value(0).toInt();
    }
    l++;
    return QString::number(l);
}

QString Facture::remplir(){
    QString s1="#FC000"; QString s3;
    Facture Ftemp;

   s3=COUNT_FACT();
   // s1=s1+s3;
return s1+s3;
}

