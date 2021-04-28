#ifndef EVENEMENT_H
#define EVENEMENT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDateTime>


class Evenement
{
public:
    Evenement();
    Evenement(QString,QString,QDateTime,QDateTime,QString);

    QString getid_ev();
    QString getnom_ev();
    QDateTime getdat_deb();
    QDateTime getdat_fin();
    QString getproduit();

    void setid_ev(QString);
    void setnom_ev(QString);
    void setdat_deb(QDateTime);
    void setdat_fin(QDateTime);
    void setproduit(QString);

    bool ajouter_ev();
    QSqlQueryModel* afficher_ev();
    bool supprimer_ev(QString);
    bool modifier_ev(QString,QString,QDateTime,QDateTime,QString);

    QString recherche_id_produit(QString);

    QSqlQueryModel * rechercher_ev(QString);
    QSqlQueryModel * tri_ev();
    QStringList recherche_id_ev();
    QStringList recherche_produit();
    QStringList recherche_idclient();
    Evenement search_id(QString id_f);
    QString COUNT_FACT();
    QString remplir_ev ();
    int * recherche_id_client(QString);
    QString recherche_nom_client();
    QString search_nom_c(QString);
    QString mode_pp(QString);
    QString date_ff(QString);
    QString total_ttc(QString);
    QString recherche_mail();
    int recher_arduino(QByteArray);

private:
    QString id_ev;
    QString nom_ev;
    QDateTime dat_deb;
    QDateTime dat_fin;
    QString produit;

};

#endif // EVENEMENT_H
