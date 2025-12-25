#include "InteractionDAO.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include <QDebug>

bool InteractionDAO::insert(const Interaction& i)
{
    QSqlQuery query;
    query.prepare(
        "INSERT INTO INTERACTION "
        "(id_utilisateur, id_article, type_interaction, date_interaction) "
        "VALUES (:user, :article, :type, :date)"
        );

    query.bindValue(":user", i.getId_Utilisateur());
    query.bindValue(":article", i.getId_Article());
    query.bindValue(":type", i.getTypeInteraction());
    query.bindValue(":date", i.getDateInteraction());

    if (!query.exec()) {
        qDebug() << "Interaction insert error:" << query.lastError().text();
        return false;
    }
    return true;
}

Interaction* InteractionDAO::findById(int id)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM INTERACTION WHERE id_interaction = :id");
    query.bindValue(":id", id);

    if (!query.exec() || !query.next()) {
        return nullptr;
    }

    Interaction* i = new Interaction(
        query.value("id_interaction").toInt(),
        query.value("id_utilisateur").toInt(),
        query.value("id_article").toInt(),
        query.value("type_interaction").toString()
        );

    return i;
}

QList<Interaction*> InteractionDAO::listAll()
{
    QList<Interaction*> list;
    QSqlQuery query("SELECT * FROM INTERACTION");

    while (query.next()) {
        Interaction* i = new Interaction(
            query.value("id_interaction").toInt(),
            query.value("id_utilisateur").toInt(),
            query.value("id_article").toInt(),
            query.value("type_interaction").toString()
            );
        list.append(i);
    }
    return list;
}

bool InteractionDAO::update(const Interaction& i)
{
    QSqlQuery query;
    query.prepare(
        "UPDATE INTERACTION SET "
        "type_interaction = :type "
        "WHERE id_interaction = :id"
        );

    query.bindValue(":type", i.getTypeInteraction());
    query.bindValue(":id", i.getId_Interaction());

    if (!query.exec()) {
        qDebug() << "Interaction update error:" << query.lastError().text();
        return false;
    }
    return true;
}

bool InteractionDAO::remove(int id)
{
    QSqlQuery query;
    query.prepare("DELETE FROM INTERACTION WHERE id_interaction = :id");
    query.bindValue(":id", id);

    if (!query.exec()) {
        qDebug() << "Interaction delete error:" << query.lastError().text();
        return false;
    }
    return true;
}
