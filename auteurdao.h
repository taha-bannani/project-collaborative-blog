#ifndef AUTEURDAO_H
#define AUTEURDAO_H

#include "auteur.h"
#include <QList>

class AuteurDAO {
public:
    static bool insert(const Auteur& a);
    static Auteur* findById(int id);
    static QList<Auteur*> findAll();
};

#endif
