#ifndef NOTIFICATIONDAO_H
#define NOTIFICATIONDAO_H

#include <QString>
#include <QList>

class NotificationDAO {
public:
    static bool insert(int idNotification,
                       int idUtilisateur,
                       const QString &message);

    static bool markAsRead(int idNotification);

    static bool remove(int idNotification);

    static QList<QString> findByUser(int idUtilisateur);
};

#endif
