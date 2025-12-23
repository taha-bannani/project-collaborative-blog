#include "like_dislike.h"

Like_Dislike::Like_Dislike() {}

Like_Dislike::Like_Dislike(int id_Interaction,int id_Utilisateur, int id_Article, bool isLike)
    : Interaction(id_Interaction, id_Utilisateur, id_Article , date) {}

bool Like_Dislike::getIsLike() const { return isLike; }
void Like_Dislike::setIsLike(bool value) { isLike = value; }
<<<<<<< HEAD
void Like_Dislike::afficher() const
{
    qDebug() << (isLike ? "Like" : "Dislike")
    << "| Article:" << id_Article
    << "| User:" << id_Utilisateur;
}
=======
>>>>>>> 83403929ce121ce417630a984ae9fd2c9ad199d3
