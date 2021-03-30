#include "evenement.h"

Evenement::Evenement()
{
    id_ev="";
    nom_ev="";
    dat_deb=QDateTime(QDate(2000,01,01),QTime(00,00,00));
    dat_fin=QDateTime(QDate(2000,01,01),QTime(00,00,00));
    produit="";
}
    Evenement::Evenement(QString id_ev,QString nom_ev,QDateTime dat_deb, QDateTime dat_fin, QString produit){
        this->id_ev=id_ev;
        this->nom_ev=nom_ev;
        this->dat_deb=dat_deb;
        this->dat_fin=dat_fin;
        this->produit=produit;
    }
    QString Evenement::getid_ev(){
        return id_ev;
    }
    QString Evenement::getnom_ev(){
        return nom_ev;
    }
    QDateTime Evenement::getdat_deb(){
        return dat_deb;
    }
    QDateTime Evenement::getdat_fin(){
        return dat_fin;
    }
    QString Evenement::getproduit(){
        return produit;
    }
    void Evenement::setid_ev(QString id_ev){
        this->id_ev=id_ev;
    }
    void Evenement::setnom_ev(QString nom_ev){
        this->nom_ev=nom_ev;
    }
    void Evenement::setdat_deb(QDateTime dat_deb){
        this->dat_deb=dat_deb;
    }
    void Evenement::setdat_fin(QDateTime dat_fin){
        this->dat_fin=dat_fin;
    }
    void Evenement::setproduit(QString produit){
        this->produit=produit;
    }

    bool Evenement::ajouter_ev(){
        bool test=true;
        QSqlQuery query;
              query.prepare("INSERT INTO EVENEMENTS (ID_EV, NOM_EV, DEB_EV, FIN_EV, ID_P) "
                            "VALUES (:id_ev, :forename, :surname, :mode_f, :produit)");
              query.bindValue(":id_ev", id_ev);
              query.bindValue(":forename", nom_ev);
              query.bindValue(":surname", dat_deb);
              query.bindValue(":mode_f", dat_fin);
              query.bindValue(":produit", produit);
              if(query.exec()){
                return test;
              }else{
                return false;
              }
    }
    QStringList Evenement::recherche_produit(){
        QSqlQuery query;
        query.prepare("select NOM_P from PRODUITS");
        query.exec();
        QStringList list;
        while(query.next()){
            list.append(query.value(0).toString());
        }
        return list;

    }
    QString Evenement::recherche_id_produit(QString produit){
        QSqlQuery query;
        QString result;
        query.prepare("SELECT ID_P FROM PRODUITS WHERE NOM_P=:produit ");
        query.bindValue(":a",produit);
        query.exec();
        while(query.next()){
       result=query.value(0).toString();
        }
        return result;

    }

