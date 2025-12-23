#ifndef INTERACTIONDAO_H
#define INTERACTIONDAO_H

#include "Interaction.h"
#include <QList>

class InteractionDAO {
public:
    static bool insert(const Interaction &i, const QString &type);
    static QList<Interaction*> findByArticle(int idArticle);
    static bool remove(int idInteraction);
};

#endif
