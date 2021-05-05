#ifndef LIVRAISON_H
#define LIVRAISON_H


#include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include "qcustomplot.h"

class livraison
{
private:
    QString ttc;
    QString nom_c;
    QString adresse;
    QString livreur;
    QString statue;
public:
    livraison();
    livraison(QString,QString,QString,QString,QString);

    QSqlQueryModel * afficher_livraison();
    bool ajouter_livraison() ;
    bool ajouter_livraison_re() ;

    bool supprimer_livraison(QString);
    bool livre(QString);
    bool modifier_livraison(QString,QString);
    QSqlQueryModel * rechercher_liv_dynamique(QString a);
    QSqlQueryModel * tri_livraison();
    void stat(QCustomPlot *customPlot);

};






#endif // LIVRAISON_H
