#ifndef LIVREUR_H
#define LIVREUR_H

#include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>


class livreur
{
private:
    QString cin;
    QString nom;
    QString prenom;
    QString statue;
public:
    livreur();
    livreur(QString,QString,QString,QString);
    bool ajouter_liv();
    QSqlQueryModel * afficher_liv();
    bool supprimer_liv(QString);
    bool modifier_liv(QString,QString);
    QSqlQueryModel * rechercher_liv_dynamique(QString a);
    QSqlQueryModel * tri_liv();
    QSqlQueryModel * afficher_id();
    QStringList recherche_liv() ;
};
#endif // LIVREUR_H
