#include "notification.h"
<<<<<<< HEAD
#include <QDebug>

notification::notification(QObject *parent)
    : QObject(parent)
{
    qDebug() << "Notification object created";
}
=======

notification::notification(QObject *parent)
    : QObject{parent}
{}
>>>>>>> 83403929ce121ce417630a984ae9fd2c9ad199d3
