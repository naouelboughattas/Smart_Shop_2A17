#ifndef LIVRAISON_H
#define LIVRAISON_H


#include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>


class livraison
{
private:
    int id_liv;
    QString nom_c;
    QString adresse;
    QString livreur;
public:
    livraison();
    livraison(int,QString,QString,QString);

    QSqlQueryModel * afficher_livraison();

    bool supprimer_livraison(QString);
    bool modifier_livraison(QString,QString);
    QSqlQueryModel * rechercher_livraison_dynamique(QString a);
    QSqlQueryModel * tri_livraison();

};






#endif // LIVRAISON_H
