#include "NotificationDAO.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include <QDebug>

bool NotificationDAO::create(const Notification &n)
{
    QSqlQuery query;
    query.prepare(
        "INSERT INTO NOTIFICATION "
        "(id_utilisateur, id_interaction, message, type_notification, lue, date_creation) "
        "VALUES (:idUser, :idInter, :msg, :type, :lue, :date)"
        );

    query.bindValue(":idUser", n.getId_Utilisateur());
    query.bindValue(":idInter", n.getId_Interaction());
    query.bindValue(":msg", n.getMessage());
    query.bindValue(":type", n.getTypeNotification());
    query.bindValue(":lue", n.isLue());
    query.bindValue(":date", n.getDateCreation());

    if (!query.exec()) {
        qDebug() << "Notification create error:" << query.lastError().text();
        return false;
    }
    return true;
}

Notification* NotificationDAO::read(int id)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM NOTIFICATION WHERE id_notification = :id");
    query.bindValue(":id", id);

    if (query.exec() && query.next()) {
        Notification *n = new Notification(
            query.value("id_utilisateur").toInt(),
            query.value("id_interaction").toInt(),
            query.value("message").toString(),
            query.value("type_notification").toString()
            );

        n->setIdNotification(query.value("id_notification").toInt());
        n->setLue(query.value("lue").toBool());
        return n;
    }
    return nullptr;
}


bool NotificationDAO::update(const Notification &n)
{
    QSqlQuery query;
    query.prepare(
        "UPDATE NOTIFICATION SET "
        "message = :msg, "
        "type_notification = :type, "
        "lue = :lue "
        "WHERE id_notification = :id"
        );

    query.bindValue(":msg", n.getMessage());
    query.bindValue(":type", n.getTypeNotification());
    query.bindValue(":lue", n.isLue());
    query.bindValue(":id", n.getIdNotification());

    if (!query.exec()) {
        qDebug() << "Notification update error:" << query.lastError().text();
        return false;
    }
    return true;
}

bool NotificationDAO::remove(int id)
{
    QSqlQuery query;
    query.prepare("DELETE FROM NOTIFICATION WHERE id_notification = :id");
    query.bindValue(":id", id);

    if (!query.exec()) {
        qDebug() << "Notification delete error:" << query.lastError().text();
        return false;
    }
    return true;
}

QList<Notification*> NotificationDAO::listAll()
{
    QList<Notification*> list;
    QSqlQuery query("SELECT * FROM NOTIFICATION");

    while (query.next()) {
        Notification *n = new Notification(
            query.value("id_utilisateur").toInt(),
            query.value("id_interaction").toInt(),
            query.value("message").toString(),
            query.value("type_notification").toString()
            );

        n->setIdNotification(query.value("id_notification").toInt());
        n->setLue(query.value("lue").toBool());
        list.append(n);
    }
    return list;
}

QList<Notification*> NotificationDAO::listByUser(int idUser)
{
    QList<Notification*> list;
    QSqlQuery query;
    query.prepare("SELECT * FROM NOTIFICATION WHERE id_utilisateur = :id");
    query.bindValue(":id", idUser);

    if (query.exec()) {
        while (query.next()) {
            Notification *n = new Notification(
                query.value("id_utilisateur").toInt(),
                query.value("id_interaction").toInt(),
                query.value("message").toString(),
                query.value("type_notification").toString()
                );

            n->setIdNotification(query.value("id_notification").toInt());
            n->setLue(query.value("lue").toBool());
            list.append(n);
        }
    }
    return list;
}
