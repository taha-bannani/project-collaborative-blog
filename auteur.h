#ifndef AUTEUR_H
#define AUTEUR_H

#include <QObject>

class auteur : public QObject
{
    Q_OBJECT
public:
    explicit auteur(QObject *parent = nullptr);

signals:
};

#endif // AUTEUR_H
