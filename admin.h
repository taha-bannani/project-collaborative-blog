#ifndef ADMINISTRATEUR_H
#define ADMINISTRATEUR_H

#include "Utilisateur.h"

class Administrateur : public Utilisateur
{
public:
    Administrateur(int id, const QString &nom, const QString &email,
                   const QString &motDePasse, const QDate &dateInscription,
                   const QString &photoProfil);

    QString getRole() const override;

    void supprimerProfil(Utilisateur *user);
    void desactiverProfil(Utilisateur *user);
};

#endif // ADMINISTRATEUR_H
