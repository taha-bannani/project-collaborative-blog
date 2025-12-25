#ifndef ADMINISTRATEUR_H
#define ADMINISTRATEUR_H

#include "Utilisateur.h"

class Administrateur : public Utilisateur
{
    private:
              QString niveauAcces;

public:
    Administrateur();
    Administrateur(const QString& n, const QString& p, const QString& e, const QString& mdp);


    QString getRole() const override;

    void supprimerProfil(Utilisateur *user);
    bool bloquerUtilisateur(int id_Utilisateur);
    bool debloquerUtilisateur(int id_Utilisateur);

    void afficherInfos() const override;
};

#endif // ADMINISTRATEUR_H
