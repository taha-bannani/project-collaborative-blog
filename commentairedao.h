#ifndef COMMENTAIREDAO_H
#define COMMENTAIREDAO_H

#include "commentaire.h"
#include <QList>

class CommentaireDAO {
public:
    static bool insert(const Commentaire &c);
    static bool update(const Commentaire &c);
    static bool remove(int idInteraction);
    static QList<Commentaire> findByArticle(int idArticle);
};

#endif
