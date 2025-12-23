#ifndef DATABASE_H
#define DATABASE_H

#include <QSqlDatabase>

class Database {
public:
    Database();      // ← constructor MUST exist in .cpp
    bool connect();
    void createTables();
};

#endif
