#include "admindao.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

bool AdministrateurDAO::supprimerUtilisateur(int id)
{
    QSqlQuery query;
    query.prepare("DELETE FROM UTILISATEUR WHERE ID_UTILISATEUR=:id");
    query.bindValue(":id", id);

    if (!query.exec()) {
        qDebug() << "Delete user error:" << query.lastError().text();
        return false;
    }
    return true;
}

bool AdministrateurDAO::desactiverUtilisateur(int id)
{
    QSqlQuery query;
    query.prepare(
        "UPDATE UTILISATEUR SET ACTIF=0 WHERE ID_UTILISATEUR=:id"
        );
    query.bindValue(":id", id);
    return query.exec();
}
