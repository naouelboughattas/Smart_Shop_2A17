#ifndef FACTURE_H
#define FACTURE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDateTime>

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


private:
    QString id_f;
    QString ttc_f;
    QDateTime date_f;
    QString mode_f;
    QString nom_c;
};

#endif // FACTURE_H
