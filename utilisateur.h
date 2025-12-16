#ifndef UTILISATEUR_H
#define UTILISATEUR_H

#include <QObject>

class utilisateur : public QObject
{
    Q_OBJECT
public:
    explicit utilisateur(QObject *parent = nullptr);

signals:
};

#endif // UTILISATEUR_H
