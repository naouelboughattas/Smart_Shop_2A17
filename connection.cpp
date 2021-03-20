#include "connection.h"

connection::connection()
{

}

bool connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("projet_2A");//inserer le nom de la source de données ODBC
db.setUserName("ibrahim");//inserer nom de l'utilisateur
db.setPassword("aqwxsz123");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}
