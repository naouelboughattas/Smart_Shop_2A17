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

    QString Evenement::remplir_ev(){
        QSqlQuery qy;
        int res=0;
        QString ref;
        ref="#EV000"+QString::number(res);
        QSqlQuery qyr;
        qyr.prepare("SELECT ID_EV FROM EVENEMENTS WHERE ID_EV LIKE :id_ev");
        qyr.bindValue(":id_ev",ref);
        qyr.exec();
        while(qyr.next()){
        if(qyr.value(0).toString()==ref){
            res++;
            ref="#EV000"+QString::number(res);

        }

        qy.prepare("SELECT COUNT(*) FROM EVENEMENTS");
        qy.exec();
        while(qy.next()){
        res=qy.value(0).toInt();
        }
        res++;
        }

      return  ref="#EV000"+QString::number(res);
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
    QSqlQueryModel *Evenement::afficher_ev(){
        QSqlQueryModel* model=new QSqlQueryModel();

              model->setQuery("SELECT ID_EV, NOM_EV, NOM_P, DEB_EV, FIN_EV FROM EVENEMENTS, PRODUITS where EVENEMENTS.ID_P=PRODUITS.ID_P ORDER BY NOM_EV DESC");
              model->setHeaderData(0, Qt::Horizontal, QObject::tr("Référence"));
              model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
              model->setHeaderData(2, Qt::Horizontal, QObject::tr("Produit inclus"));
              model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date de début"));
              model->setHeaderData(4, Qt::Horizontal, QObject::tr("Date de fin"));
              return model;
    }
    QSqlQueryModel * Evenement::tri_ev()
    {
        QSqlQueryModel * model= new QSqlQueryModel();
        model->setQuery("SELECT ID_EV, NOM_EV, NOM_P, DEB_EV, FIN_EV FROM EVENEMENTS, PRODUITS where EVENEMENTS.ID_P=PRODUITS.ID_P ORDER BY DEB_EV DESC");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("Référence"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("Produit inclus"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date de début"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("Date de fin"));
        return model;
    }
    QSqlQueryModel * Evenement::rechercher_ev(QString a)
    {
        QSqlQueryModel * model= new QSqlQueryModel();
        QSqlQuery query;
        query.prepare("SELECT ID_EV, NOM_EV, NOM_P, DEB_EV, FIN_EV FROM EVENEMENTS, PRODUITS where EVENEMENTS.ID_P=PRODUITS.ID_P AND ID_EV like '"+a+"' ||'%' OR NOM_EV like '"+a+"' ||'%' OR NOM_P like '"+a+"' ||'%' OR DEB_EV like '"+a+"' OR FIN_EV like '"+a+"' ||'%' ORDER BY DEB_EV DESC ");
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


    QStringList Evenement::recherche_id_ev(){
        QSqlQuery query;
        query.prepare("select ID_EV from EVENEMENTS ORDER BY DEB_EV ASC");
        query.exec();
        QStringList list;
        while(query.next()){
            list.append(query.value(0).toString());
        }
        return list;

    }

    bool Evenement::supprimer_ev(QString id_ev){
        QSqlQuery query;

        query.prepare("DELETE FROM EVENEMENTS WHERE ID_EV = :id_ev ");
        query.bindValue(":id_ev", id_ev);
        return query.exec();
    }

    bool Evenement::modifier_ev(QString id_ev,QString nom_ev,QDateTime dat_deb,QDateTime dat_fin,QString produit)
    {
        QSqlQuery query;
        query.prepare("UPDATE EVENEMENTS SET NOM_EV= :nom_ev,DEB_EV = :dat_deb,FIN_EV= :dat_fin,ID_P = :produit WHERE ID_EV= :id_ev ");
        query.bindValue(":id_ev",id_ev);
        query.bindValue(":nom_ev",nom_ev);
        query.bindValue(":dat_deb",dat_deb);
        query.bindValue(":dat_fin",dat_fin);
        query.bindValue(":produit",produit);
        return    query.exec();
    }

