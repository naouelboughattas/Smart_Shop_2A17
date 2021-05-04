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
    bool ajouter_cat();
    QSqlQueryModel* afficher_cat();
    bool modifier_cat(int,QString);
    bool supprimer_cat(int);
    QSqlQueryModel* tri_cat();
    QSqlQueryModel* recherche_cat(QString);
    QStringList recherche_id_categorie();

private:
    int ID_cat;
    QString Nom_cat;
};

#endif // CATEGORIE_H
