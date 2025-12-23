#include "interactiondao.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

bool InteractionDAO::insert(const Interaction &i, const QString &type) {
    QSqlQuery query;
    query.prepare(
        "INSERT INTO interaction "
        "(id_utilisateur, id_article, date_interaction, type) "
        "VALUES (:user, :article, :date, :type)"
        );

    query.bindValue(":user", i.getId_Utilisateur());
    query.bindValue(":article", i.getId_Article());
    query.bindValue(":date", i.getDate());
    query.bindValue(":type", type);

    if (!query.exec()) {
        qDebug() << "Insert Interaction failed:" << query.lastError().text();
        return false;
    }
    return true;
}

QList<Interaction*> InteractionDAO::findByArticle(int idArticle) {
    QList<Interaction*> list;
    QSqlQuery query;
    query.prepare(
        "SELECT id_interaction, id_utilisateur, id_article, date_interaction "
        "FROM interaction WHERE id_article = :id"
        );
    query.bindValue(":id", idArticle);
    query.exec();

    while (query.next()) {
        // abstract → normally you instantiate Like / Commentaire here
        qDebug() << "Interaction found id =" << query.value(0).toInt();
    }
    return list;
}

bool InteractionDAO::remove(int idInteraction) {
    QSqlQuery query;
    query.prepare("DELETE FROM interaction WHERE id_interaction = :id");
    query.bindValue(":id", idInteraction);

    if (!query.exec()) {
        qDebug() << "Delete Interaction failed:" << query.lastError().text();
        return false;
    }
    return true;
}
