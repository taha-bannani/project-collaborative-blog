#include "database.h"
#include <QSqlQuery>
#include <QDebug>

Database::Database() {}   // ← THIS FIXES THE LINKER ERROR

bool Database::connect() {
    QSqlDatabase db = QSqlDatabase::addDatabase("QOCI");
    db.setDatabaseName("//192.168.56.1:1521/XEPDB1"); // Replace with your Oracle DSN
    db.setUserName("blog_user");
    db.setPassword("blog1234");

    if (!db.open()) {
        qDebug() << "Database not connected";
        return false;
    }

    qDebug() << "Database connected";
    return true;
}


