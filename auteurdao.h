#ifndef AUTEURDAO_H
#define AUTEURDAO_H

#include "auteur.h"

class AuteurDAO {
public:
    static bool insert(const Auteur &a);
    static bool updateBio(int idAuteur, const QString &bio);
};

#endif
