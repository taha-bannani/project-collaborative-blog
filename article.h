#ifndef ARTICLE_H
#define ARTICLE_H

#include <QObject>

class article : public QObject
{
    Q_OBJECT
public:
    explicit article(QObject *parent = nullptr);

signals:
};

#endif // ARTICLE_H
