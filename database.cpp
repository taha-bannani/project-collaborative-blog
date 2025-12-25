#include "database.h"
#include <QSqlQuery>
#include <QDebug>

Database::Database() {}

bool Database::connect() {
    QSqlDatabase db = QSqlDatabase::addDatabase("QOCI");
    db.setDatabaseName("//192.168.56.1:1521/XEPDB1");
    db.setUserName("blog_user");
    db.setPassword("blog1234");

    if (!db.open()) {
        qDebug() << "Database not connected";
        return false;
    }

    qDebug() << "Database connected";
    return true;

db.transaction();
}

void Database::createTables() {
    QSqlQuery q;

    q.exec("CREATE TABLE test_table (id NUMBER PRIMARY KEY, name VARCHAR2(50))");

    qDebug() << "Tables created (if they didn’t already exist)";
}
