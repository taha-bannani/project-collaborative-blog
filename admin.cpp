#include "admin.h"
#include <QDebug>


Administrateur::Administrateur()
    : Utilisateur(),
    niveauAcces("ADMIN")
{
    role = "Administrateur";
}

Administrateur::Administrateur(const QString& n,
                               const QString& p,
                               const QString& e,
                               const QString& mdp)
    : Utilisateur(n, p, e, mdp, "Administrateur"),
    niveauAcces("ADMIN")
{
}


QString Administrateur::getRole() const
{
    return "Administrateur";
}

void Administrateur::supprimerProfil(Utilisateur *user)
{
    if (!user) {
        qDebug() << " Aucun utilisateur à supprimer";
        return;
    }

    qDebug() << "️ Profil supprimé pour l'utilisateur ID:"
             << user->getId_Utilisateur();


}

bool Administrateur::bloquerUtilisateur(int id_Utilisateur)
{
    qDebug() << " Utilisateur bloqué. ID:" << id_Utilisateur;
    return true;
}

bool Administrateur::debloquerUtilisateur(int id_Utilisateur)
{
    qDebug() << " Utilisateur débloqué. ID:" << id_Utilisateur;
    return true;
}


void Administrateur::afficherInfos() const
{
    qDebug() << "=== Administrateur ===";
    qDebug() << "ID:" << id_Utilisateur;
    qDebug() << "Nom:" << nom;
    qDebug() << "Email:" << email;
    qDebug() << "Niveau d'accès:" << niveauAcces;
}
