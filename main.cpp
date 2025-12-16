#include <QCoreApplication>
#include "database.h"

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    Database db;

    if (db.connect()) {
        db.createTables();
    }

    return 0;   // no GUI, no event loop needed
}
