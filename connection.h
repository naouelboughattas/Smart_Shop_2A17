#ifndef CONNECTION_H
#define CONNECTION_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

class Connection
{

public:
    Connection();
    bool createconnection();

};

#endif // CONNECTION_H
