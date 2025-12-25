#ifndef DATABASE_H
#define DATABASE_H

#include <QSqlDatabase>

class Database {
public:
    Database();
    bool connect();
    void createTables();
};

#endif
