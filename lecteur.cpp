#include "Lecteur.h"

// ----- CONSTRUCTEUR -----
Lecteur::Lecteur(int id,
                 const QString &nom,
                 const QString &email,
                 const QString &motDePasse,
                 const QDate &dateInscription,
                 const QString &photoProfil)
    : Utilisateur(id, nom, email, motDePasse, dateInscription, photoProfil)
{
}

// ----- ROLE -----
QString Lecteur::getRole() const
{
    return "Lecteur";
}
