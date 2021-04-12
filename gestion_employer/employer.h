#ifndef EMPLOYER_H
#define EMPLOYER_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class employer
{
public:
    employer();
    employer(QString,QString,QString,QString,QString);
    QString getcin();
    QString getnom();
    QString getprenom();
    QString getadresse();
    QString getemail();
    void setcin(QString);
    void setnom(QString);
    void setprenom(QString);
    void setadresse(QString);
    void setemail(QString);


    bool ajouter_employer();
    bool modifier_employer();
    bool supprimer_employer();
    QSqlQueryModel * afficher_employer();
    QSqlQueryModel * afficher_list();
    void chercher();
    QSqlQueryModel * recherche(QString valeur);

private:
    QString cin;
    QString nom, prenom,adresse,email;

};

#endif // EMPLOYER_H
