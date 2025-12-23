#ifndef LIKEDISLIKEDAO_H
#define LIKEDISLIKEDAO_H

#include "like_dislike.h"
#include <QList>

class LikeDislikeDAO {
public:
    static bool insert(const Like_Dislike &ld);
    static bool update(const Like_Dislike &ld);
    static bool remove(int idInteraction);
     QList<Like_Dislike> findByArticle(int idArticle);

    static int countLikes(int idArticle);
    static int countDislikes(int idArticle);
};

#endif
