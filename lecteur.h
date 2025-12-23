#ifndef LECTEUR_H
#define LECTEUR_H

#include "Utilisateur.h"

class Lecteur : public Utilisateur
{
public:
    Lecteur(int id, const QString &nom, const QString &email,
            const QString &motDePasse, const QDate &dateInscription,
            const QString &photoProfil);

    QString getRole() const override;
};

#endif // LECTEUR_H
