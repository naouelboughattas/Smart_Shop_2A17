#ifndef TACHE_H
#define TACHE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDateTime>

class tache
{
public:
    tache();
    tache(QString,QString,QDateTime);
    QString getid();
    QString getdescri();
    QDateTime getduree();

    void setid(QString);
    void setdescri(QString);
    void setduree(QDateTime);



    bool ajouter_tache();
    bool modifier_tache();
    bool supprimer_tache();
    QSqlQueryModel * afficher_tache();
    QSqlQueryModel * afficher_list();
    void chercher();
    QSqlQueryModel * tri_tache();
    QSqlQueryModel * recherche(QString);
    QSqlQueryModel *afficher_liste();

private:

    QString id, descri;
    QDateTime duree ;

};


#endif // TACHE_H
