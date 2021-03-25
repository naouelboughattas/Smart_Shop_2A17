#ifndef PRODUIT_H
#define PRODUIT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDateTime>

class Produit
{
public:
    Produit();
    Produit(int,QString,QString,int);
    int getid_P();
    QString getnom_P();
    QString gettype();
    int getprix();
    void setid_P(int);
    void setnom_P(QString);
    void settype(QString);
    void setprix(int);
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool modifier(int,QString,QString,int);

private:
    int id_P;
    QString nom_P;
    QString type;
    int prix;

};

#endif // PRODUIT_H
