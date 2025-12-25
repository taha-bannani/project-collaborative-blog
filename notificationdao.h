#ifndef NOTIFICATIONDAO_H
#define NOTIFICATIONDAO_H

#include "Notification.h"
#include <QList>

class NotificationDAO
{
public:
    static bool create(const Notification &n);
    static Notification* read(int id);
    static bool update(const Notification &n);
    static bool remove(int id);


    static QList<Notification*> listAll();
    static QList<Notification*> listByUser(int idUser);
};

#endif
