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
    Facture(QString,QDateTime,QString);
    QString getid_f();
    QDateTime getdate_f();
    QString getttc_f();
    void setid_f(QString);
    void setdate_f(QDateTime);
    void setttc_f(QString);
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(QString);
    bool modifier(QString,QDateTime,QString);
    QSqlQueryModel * rechercher(QString);
    QSqlQueryModel * tri();
    QStringList recherche_id();
    Facture search_id(QString id_f);


private:
    QString id_f;
    QString ttc_f;
    QDateTime date_f;
};

#endif // FACTURE_H
