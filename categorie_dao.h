#ifndef CATEGORIE_DAO_H
#define CATEGORIE_DAO_H

#include "categorie.h"
#include <QSqlDatabase>
#include <vector>

class CategorieDAO {
public:
    static bool insert(const Categorie& c);
    static bool update(const Categorie& c);
    static bool remove(int id);
    static bool findById(int id, Categorie& c);
    static std::vector<Categorie> findAll();
};

#endif
