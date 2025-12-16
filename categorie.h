#ifndef CATEGORIE_H
#define CATEGORIE_H

#include <QObject>

class categorie : public QObject
{
    Q_OBJECT
public:
    explicit categorie(QObject *parent = nullptr);

signals:
};

#endif // CATEGORIE_H
