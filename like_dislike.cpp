#include "like_dislike.h"

Like_Dislike::Like_Dislike() {}

Like_Dislike::Like_Dislike(int id_Interaction,int id_Utilisateur, int id_Article, bool isLike)
    : Interaction(id_Interaction, id_Utilisateur, id_Article , date) {}

bool Like_Dislike::getIsLike() const { return isLike; }
void Like_Dislike::setIsLike(bool value) { isLike = value; }
