#include "connexion.h"

connexion::connexion()
{

}
bool connexion::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("Projet2A");//inserer le nom de la source de données ODBC
db.setUserName("yasmine");//inserer nom de l'utilisateur
db.setPassword("yasmine");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}
