#include "notificationdao.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

bool NotificationDAO::insert(int idNotification,
                             int idUtilisateur,
                             const QString &message)
{
    QSqlQuery query;
    query.prepare(
        "INSERT INTO notification "
        "(id_notification, id_utilisateur, message, lu) "
        "VALUES (:id, :user, :msg, 0)"
        );

    query.bindValue(":id", idNotification);
    query.bindValue(":user", idUtilisateur);
    query.bindValue(":msg", message);

    if (!query.exec()) {
        qDebug() << "Insert notification failed:" << query.lastError().text();
        return false;
    }
    return true;
}

bool NotificationDAO::markAsRead(int idNotification)
{
    QSqlQuery query;
    query.prepare(
        "UPDATE notification SET lu = 1 "
        "WHERE id_notification = :id"
        );
    query.bindValue(":id", idNotification);

    return query.exec();
}

bool NotificationDAO::remove(int idNotification)
{
    QSqlQuery query;
    query.prepare(
        "DELETE FROM notification WHERE id_notification = :id"
        );
    query.bindValue(":id", idNotification);

    return query.exec();
}

QList<QString> NotificationDAO::findByUser(int idUtilisateur)
{
    QList<QString> notifications;
    QSqlQuery query;

    query.prepare(
        "SELECT message FROM notification "
        "WHERE id_utilisateur = :id "
        "ORDER BY date_notification DESC"
        );
    query.bindValue(":id", idUtilisateur);
    query.exec();

    while (query.next()) {
        notifications.append(query.value(0).toString());
    }

    return notifications;
}
