#include "connection.h"

Connection::Connection(){}

bool Connection::createconnection()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("Projet_2a");//inserer le nom de la source de données ODBC
db.setUserName("nina");//inserer nom de l'utilisateur
db.setPassword("nina");//inserer mot de passe de cet utilisateur

if (db.open())

test=true;

return test;

}
