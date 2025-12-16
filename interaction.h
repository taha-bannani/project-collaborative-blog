#ifndef INTERACTION_H
#define INTERACTION_H

#include <QObject>

class interaction : public QObject
{
    Q_OBJECT
public:
    explicit interaction(QObject *parent = nullptr);

signals:
};

#endif // INTERACTION_H
