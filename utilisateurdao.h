#ifndef UTILISATEURDAO_H
#define UTILISATEURDAO_H

#include "Utilisateur.h"

class UtilisateurDAO {
public:
    static Utilisateur* findById(int id);
};

#endif
