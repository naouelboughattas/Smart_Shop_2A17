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
    Facture(int,QDateTime,QString);
    int getid_f();
    QDateTime getdate_f();
    QString getttc_f();
    void setid_f(int);
    void setdate_f(QDateTime);
    void setttc_f(QString);
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool modifier(int,QDateTime,QString);
    QSqlQueryModel * rechercher(QString);
    QSqlQueryModel * tri();
    QStringList recherche_id();
    Facture search_id(int id_f);


private:
    int id_f;
    QString ttc_f;
    QDateTime date_f;
};

#endif // FACTURE_H
