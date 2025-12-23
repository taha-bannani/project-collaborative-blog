#ifndef LIKE_DISLIKE_H
#define LIKE_DISLIKE_H

#include <QObject>
#include "interaction.h"

class Like_Dislike : public Interaction{
private:

    bool isLike;

public:
    Like_Dislike();
    Like_Dislike(int id_Interaction,int id_Utilisateur, int id_Article, bool isLike );

    bool getIsLike() const;
    void setIsLike(bool value);
    void afficher() const override;
};

#endif // LIKE_DISLIKE_H
