#ifndef LIKE_DISLIKE_H
#define LIKE_DISLIKE_H

#include <QObject>

class like_dislike : public QObject
{
    Q_OBJECT
public:
    explicit like_dislike(QObject *parent = nullptr);

signals:
};

#endif // LIKE_DISLIKE_H
