#ifndef INTERACTIONDAO_H
#define INTERACTIONDAO_H

#include "Interaction.h"
#include <QList>

class InteractionDAO
{
public:
    static bool insert(const Interaction& i);

    static Interaction* findById(int id);
    static QList<Interaction*> listAll();

    static bool update(const Interaction& i);


    static bool remove(int id);
};

#endif
