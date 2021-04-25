#ifndef FACTURE_H
#define FACTURE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDateTime>
#include "qcustomplot.h"

class Facture
{
public:
    Facture();
    Facture(QString,QDateTime,QString,QString,QString);

    QString getid_f();
    QDateTime getdate_f();
    QString getttc_f();
    QString getmode_f();
    QString getnom_c();

    void setid_f(QString);
    void setdate_f(QDateTime);
    void setttc_f(QString);
    void setmode_f(QString);
    void setnom_c(QString);

    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(QString);
    bool modifier(QString,QDateTime,QString,QString,QString);
    QSqlQueryModel * rechercher(QString);
    QSqlQueryModel * tri();
    QStringList recherche_id();
    QStringList recherche_client();
    QStringList recherche_idclient();
    Facture search_id(QString id_f);
    QString COUNT_FACT();
    QString remplir ();
    int * recherche_id_client(QString);
    QString recherche_nom_client();
    QString search_nom_c(QString);
    QString mode_pp(QString);
    QString date_ff(QString);
    QString total_ttc(QString);
    QString stat_count();
    QString max_p();
    QString min_p();
    QString top_c();
    QString top_cc();
    void stat(QCustomPlot *customPlot);



private:
    QString id_f;
    QString ttc_f;
    QDateTime date_f;
    QString mode_f;
    QString nom_c;
    QString dat_info;

};

#endif // FACTURE_H
