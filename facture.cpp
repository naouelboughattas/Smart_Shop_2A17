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
mode_f="";
nom_c="";
}
Facture::Facture(QString id_f,QDateTime date_f,QString ttc_f, QString mode_f, QString nom_c){
    this->id_f=id_f;
    this->date_f=date_f;
    this->ttc_f=ttc_f;
    this->mode_f=mode_f;
    this->nom_c=nom_c;

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
QString Facture::getmode_f(){
    return mode_f;
}
QString Facture::getnom_c(){
    return nom_c;
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
void Facture::setmode_f(QString mode_f){
    this->mode_f=mode_f;
}
void Facture::setnom_c(QString nom_c){
    this->nom_c=nom_c;
}
bool Facture::ajouter(){
    bool test=true;
    QSqlQuery query;
    QString id_string= id_f;
          query.prepare("INSERT INTO FACTURES (ID_F, DATE_F, TTC_F, MODE_P_F,ID_C) "
                        "VALUES (:id_f, :forename, :surname, :mode_f, :nom_c)");
          query.bindValue(":id_f", id_string);
          query.bindValue(":forename", date_f);
          query.bindValue(":surname", ttc_f);
          query.bindValue(":mode_f", mode_f);
          query.bindValue(":nom_c", nom_c);
          if(query.exec()){
            return test;
          }else{
            return false;
          }
}
QSqlQueryModel *Facture::afficher(){
    QSqlQueryModel* model=new QSqlQueryModel();

          model->setQuery("SELECT ID_F, ID_C, DATE_F, MODE_P_F, TTC_F FROM FACTURES where FACTURES.ID_C=CLIENTS.ID_CLIENT ORDER BY DATE_F DESC");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("Référence"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("Client"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("Date"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("Paiement"));
          model->setHeaderData(4, Qt::Horizontal, QObject::tr("Total TTC"));
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
    query.prepare("SELECT ID_F, NOM_C, DATE_F, MODE_P_F, TTC_F FROM FACTURES, CLIENTS where FACTURES.ID_C=CLIENTS.ID_CLIENT AND ID_F like '"+a+"' ||'%' OR DATE_F like '"+a+"' ||'%' OR TTC_F like '"+a+"' ||'%' OR MODE_P_F like '"+a+"' OR NOM_C like '"+a+"' ORDER BY DATE_F DESC ");
    query.bindValue(":id",a);
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Référence"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Client"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Date"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Paiement"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Total TTC"));
    return model;
}
QSqlQueryModel * Facture::tri()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT ID_F, NOM_C, DATE_F, MODE_P_F, TTC_F FROM FACTURES, CLIENTS where FACTURES.ID_C=CLIENTS.ID_CLIENT ORDER BY ID_F DESC");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Référence"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Client"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Date"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Paiement"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Total TTC"));
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
QStringList Facture::recherche_client(){
    QSqlQuery query;
    query.prepare("select NOM_C from CLIENTS");
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
    query.prepare("SELECT COUNT(*) FROM FACTURES;");
    query.exec();
    while(query.next()){
        l=query.value(0).toInt();
    }
    l++;
    return QString::number(l);
}

QString Facture::remplir(){
    QSqlQuery qy;
    int res;
    QString ref;
    qy.prepare("SELECT COUNT(*) FROM FACTURES");
    qy.exec();
    while(qy.next()){
    res=qy.value(0).toInt();
    }
    res++;
  return  ref="#FC000"+QString::number(res);
}

QString Facture::recherche_nom_client(){
    QSqlQuery query;
    query.prepare("select NOM_C from CLIENTS");
    query.exec();
    QString list;
    while(query.next()){
        list=query.value(0).toString();
    }

    return list;

}
QStringList Facture::recherche_idclient(){
    QSqlQuery query;
    query.prepare("select distinct ID_CLIENT from CLIENTS");
    query.exec();
    QStringList list;
    while(query.next()){
        list.append(query.value(0).toString());
    }

    return list;

}


