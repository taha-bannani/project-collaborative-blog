#include "auteurdao.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

bool AuteurDAO::insert(const Auteur &a) {
    QSqlQuery query;
    query.prepare(
        "INSERT INTO auteur (id_utilisateur, biographie) "
        "VALUES (:id, :bio)"
        );

    query.bindValue(":id", a.getIdUtilisateur());


    if (!query.exec()) {
        qDebug() << "Insert Auteur failed:" << query.lastError().text();
        return false;
    }
    return true;
}

bool AuteurDAO::updateBio(int idAuteur, const QString &bio) {
    QSqlQuery query;
    query.prepare(
        "UPDATE auteur SET biographie = :bio "
        "WHERE id_utilisateur = :id"
        );

    query.bindValue(":bio", bio);
    query.bindValue(":id", idAuteur);

    if (!query.exec()) {
        qDebug() << "Update biographie failed:" << query.lastError().text();
        return false;
    }
    return true;
}
