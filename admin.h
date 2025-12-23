#ifndef ADMINISTRATEUR_H
#define ADMINISTRATEUR_H

#include "Utilisateur.h"

class Administrateur : public Utilisateur
{
public:
<<<<<<< HEAD
    Administrateur(int id_Utilisateur, const QString &nom, const QString &email,
=======
    Administrateur(int id, const QString &nom, const QString &email,
>>>>>>> 83403929ce121ce417630a984ae9fd2c9ad199d3
                   const QString &motDePasse, const QDate &dateInscription,
                   const QString &photoProfil);

    QString getRole() const override;

    void supprimerProfil(Utilisateur *user);
    void desactiverProfil(Utilisateur *user);
};

#endif // ADMINISTRATEUR_H
