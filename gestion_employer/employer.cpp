#include "employer.h"
#include "connexion.h"
#include <QSqlQuery>
#include <QtDebug>

employer::employer()
{
cin="";
}
employer::employer(QString cin,QString nom,QString prenom,QString adresse,QString email)
{
    this->cin=cin; this->nom=nom; this->prenom=prenom; this->adresse=adresse; this->email=email;

}
QString employer::getcin()
{
    return  cin;
}
QString employer::getnom()
{
    return  nom;
}
QString employer::getprenom()
{
    return  prenom;
}
QString employer::getadresse()
{
    return  adresse;
}
QString employer::getemail()
{
    return  email;
}
void employer::setcin(QString cin)
{
    this->cin=cin;
}
void employer::setnom(QString nom)
{
    this->nom=nom;
}
void employer::setprenom(QString prenom)
{
    this->prenom=prenom;
}
void employer::setadresse(QString adresse)
{
    this->adresse=adresse;
}
void employer::setemail(QString email)
{
    this->email=email;
}

bool employer:: ajouter_employer()
{
    QSqlQuery query;
    QString cin_string = cin;

    query.prepare("INSERT INTO personnel (cin,nom,prenom,adresse,email) " "VALUES (:cin,:nom,:prenom,:adresse,:email)");
    query.bindValue(":cin",cin);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":adresse",adresse);
    query.bindValue(":email", email);


    return    query.exec();

}


bool employer::supprimer_employer()
{

    QSqlQuery query;
    query.prepare("Delete from personnel where cin = :cin ");
    query.bindValue(":cin",cin);
    return    query.exec();

}
QSqlQueryModel * employer:: afficher_employer()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from personnel");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("adresse"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("email"));
    return model;
}

 bool employer::modifier_employer()
 {      QSqlQuery query;
        query.prepare("update personnel set nom=:nom,prenom=:prenom,adresse=:adresse,email=:email where cin=:cin");
        query.bindValue(":cin",cin);
        query.bindValue(":nom",nom);
        query.bindValue(":prenom",prenom);
        query.bindValue(":adresse", adresse);
        query.bindValue(":email", email);


        return    query.exec();

}

QSqlQueryModel * employer:: afficher_list()
{
    QSqlQueryModel * model= new QSqlQueryModel();

        model->setQuery("select cin from personnel");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));


            return model;
}
void employer:: chercher()
{    QSqlQuery query1;
     query1.prepare("SELECT nom,prenom,adresse,email FROM personnel WHERE cin =:cin");
     query1.bindValue(":cin",cin);
     query1.exec();
     while(query1.next())
     {
     nom = query1.value(0).toString();
     prenom = query1.value(0).toString();
     adresse = query1.value(0).toString();
     email = query1.value(0).toString();
     }

}
QSqlQueryModel * employer:: recherche(QString valeur, int etat)
{
    QSqlQueryModel * model=new QSqlQueryModel();

    QSqlQuery query;
    if(etat==0)
   { query.prepare("SELECT * FROM personnel WHERE cin LIKE :valeur order by cin");}
    else   { query.prepare("SELECT * FROM personnel WHERE cin LIKE :valeur order by cin desc");}
    valeur="%"+valeur+"%";
    query.bindValue(":valeur",valeur);
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("adresse"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("email"));
    return model;

}

