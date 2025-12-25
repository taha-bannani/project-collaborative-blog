#ifndef UTILISATEURDAO_H
#define UTILISATEURDAO_H

#include "Utilisateur.h"
#include <QList>
#include <QSqlDatabase>
class UtilisateurDAO
{
public:
    static bool insert(const Utilisateur& u);


    static Utilisateur* findById(int id);
    static QList<Utilisateur*> listAll();


    static bool update(const Utilisateur& u);


    static bool remove(int id);

};

#endif
