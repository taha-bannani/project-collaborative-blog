#ifndef ARTICLEDAO_H
#define ARTICLEDAO_H

#include "article.h"
#include <QList>

class ArticleDAO {
public:
    static bool insert(const Article &a);
    static bool update(int id, const Article &a);
    static bool remove(int id);
    static QList<Article> findAll();
    static QList<Article> findByKeyword(const QString &keyword);
};

#endif // ARTICLEDAO_H
