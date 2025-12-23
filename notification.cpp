#include "notification.h"
#include <QDebug>

notification::notification(QObject *parent)
    : QObject(parent)
{
    qDebug() << "Notification object created";
}
