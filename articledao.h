#ifndef ARTICLEDAO_H
#define ARTICLEDAO_H

#include "Article.h"
#include <QList>

class ArticleDAO
{
public:

    static bool insert(const Article& article);


    static Article* findById(int id);
    static QList<Article*> listAll();

    static bool update(const Article& article);

    static bool remove(int id);
};

#endif // ARTICLEDAO_H
