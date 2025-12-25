#ifndef CATEGORIEDAO_H
#define CATEGORIEDAO_H

#include "Categorie.h"
#include <QList>

class CategorieDAO
{
public:
    static bool insert(const Categorie& c);


    static Categorie* findById(int id);
    static QList<Categorie*> listAll();

    static bool update(const Categorie& c);

    static bool remove(int id);
};

#endif // CATEGORIEDAO_H
