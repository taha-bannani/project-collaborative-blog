#include "Utilisateur.h"

// ---- CONSTRUCTEURS ----

Utilisateur::Utilisateur()
    : id_Utilisateur(0),
    nom(""),
    email(""),
    motDePasse(""),
    dateInscription(QDate::currentDate()),
    photoProfil("")
{
}

Utilisateur::Utilisateur(int id,
                         const QString &nom,
                         const QString &email,
                         const QString &motDePasse,
                         const QDate &dateInscription,
                         const QString &photoProfil)
    : id_Utilisateur(id),
    nom(nom),
    email(email),
    motDePasse(motDePasse),
    dateInscription(dateInscription),
    photoProfil(photoProfil)
{
}

// ---- GETTERS ----
int Utilisateur::getIdUtilisateur() const
{
    return id_Utilisateur;
}

QString Utilisateur::getNom() const
{
    return nom;
}

QString Utilisateur::getEmail() const
{
    return email;
}

// ---- SETTERS ----
void Utilisateur::setNom(const QString &nom)
{
    this->nom = nom;
}

void Utilisateur::setEmail(const QString &email)
{
    this->email = email;
}

// ⚠️ getRole() is **pure virtual**, so no implementation here.
