#ifndef VEHICULE_H
#define VEHICULE_H

#include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>


class vehicule
{
private:
    QString matricule;
    QString marque;
    QString couleur;
    QString date_ent;
public:
    vehicule();
    vehicule(QString,QString,QString,QString);
    bool ajouter_veh();
    QSqlQueryModel * afficher_veh();
    QSqlQueryModel * ent_veh();
    bool supprimer_veh(QString);
    bool modifier_veh(QString,QString);
    QSqlQueryModel * rechercher_veh_dynamique(QString a);
    QSqlQueryModel * tri_veh();
    QSqlQueryModel * afficher_id();
    QStringList recherche_veh() ;
};
#endif // VEHICULE_H
