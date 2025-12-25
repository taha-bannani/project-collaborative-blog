#ifndef LIKEDISLIKEDAO_H
#define LIKEDISLIKEDAO_H

#include <QList>
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include <QDebug>

#include "Like_Dislike.h"

class LikeDislikeDAO
{
public:
    LikeDislikeDAO();

    bool insert(const Like_Dislike &ld);
    static Like_Dislike* getById(int idInteraction);
    bool update(const Like_Dislike &ld);
    bool remove(int idInteraction);

    static QList<Like_Dislike*> getAll();
    static QList<Like_Dislike*> getByArticle(int idArticle);
};

#endif
