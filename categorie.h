#ifndef CATEGORIE_H
#define CATEGORIE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDateTime>

class Categorie
{
public:
    Categorie();
    Categorie(int,QString);
    int getID_cat();
    QString getNom_cat();
    void setID_cat(int);
    void setNom_cat(QString);
    bool ajouter();
    QSqlQueryModel* afficher();
    bool modifier(int,QString);
    bool supprimer(int);

private:
    int ID_cat;
    QString Nom_cat;
};

#endif // CATEGORIE_H
