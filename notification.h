#ifndef NOTIFICATION_H
#define NOTIFICATION_H

#include <QObject>

class notification : public QObject
{
    Q_OBJECT
public:
    explicit notification(QObject *parent = nullptr);

signals:
};

#endif // NOTIFICATION_H
