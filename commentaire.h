#ifndef COMMENTAIRE_H
#define COMMENTAIRE_H

#include <QObject>

class commentaire : public QObject
{
    Q_OBJECT
public:
    explicit commentaire(QObject *parent = nullptr);

signals:
};

#endif // COMMENTAIRE_H
