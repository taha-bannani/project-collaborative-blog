#ifndef COMMENTAIREDao_H
#define COMMENTAIREDao_H

#include "Commentaire.h"
#include <QList>

class CommentaireDAO
{
public:

    static bool insert(const Commentaire& c);

    static QList<Commentaire*> findByArticle(int idArticle);

    static bool remove(int idInteraction);
};

#endif // COMMENTAIREDao_H
