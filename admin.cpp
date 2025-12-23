#include "admin.h"
#include <QDebug>

Administrateur::Administrateur(int id_Utilisateur,
                               const QString &nom,
                               const QString &email,
                               const QString &motDePasse,
                               const QDate &dateInscription,
                               const QString &photoProfil)
    : Utilisateur(id_Utilisateur, nom, email, motDePasse, dateInscription, photoProfil)
{}

QString Administrateur::getRole() const {
    return "Administrateur";
}

void Administrateur::supprimerProfil(Utilisateur *user) {
    if (!user) {
        qDebug() << "Utilisateur invalide. Impossible de supprimer.";
        return;
    }
    qDebug() << "Profil supprimé pour ID =" << user->getIdUtilisateur();
}

void Administrateur::desactiverProfil(Utilisateur *user) {
    if (!user) {
        qDebug() << "Utilisateur invalide. Impossible de désactiver.";
        return;
    }
    qDebug() << "Profil désactivé pour ID =" << user->getIdUtilisateur();
}
