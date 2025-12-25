#include "like_dislike.h"

Like_Dislike::Like_Dislike() {}

Like_Dislike::Like_Dislike(int id_Interaction,int id_Utilisateur, int id_Article, bool isLike)
    : Interaction() {}

bool Like_Dislike::getIsLike() const { return isLike; }
void Like_Dislike::setIsLike(bool value) { isLike = value; }
void Like_Dislike::afficher() const{
    qDebug() << (isLike ? "Like" : "Dislike")
    << "| Article:" << id_Article
    << "| User:" << id_Utilisateur;
}

