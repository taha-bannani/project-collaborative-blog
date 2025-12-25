#ifndef LECTEUR_H
#define LECTEUR_H

#include "Utilisateur.h"

class Lecteur : public Utilisateur {
private:
    int nombreArticlesLus;

public:
    Lecteur();
    Lecteur(const QString& n, const QString& p, const QString& e, const QString& mdp);

    int getNombreArticlesLus() const;
    void setNombreArticlesLus(int n);


    void afficherInfos() const override;
};

#endif
