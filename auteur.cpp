#include "auteur.h"
#include <QDebug>

// ----- CONSTRUCTEUR -----
Auteur::Auteur(int id_Utilisateur, const QString &nom, const QString &email,
               const QString &motDePasse, const QDate &dateInscription,
               const QString &photoProfil, const QString &biographie)
    : Utilisateur(id_Utilisateur, nom, email, motDePasse, dateInscription, photoProfil),
    biographie(biographie)
{
}

// ----- ROLE -----
QString Auteur::getRole() const
{
    return "Auteur";
}

// ----- PUBLICATION -----
void Auteur::publierArticle(Article &article)
{
    // L'auteur devient l'auteur officiel de l'article
    article.setIdAuteur(this->getIdUtilisateur());
}

// ----- MODIFICATION -----
void Auteur::modifierArticle(Article &article, const QString &contenu)
{
    if (article.getIdAuteur() == this->getIdUtilisateur()) {
        article.setContenu(contenu);
    } else {
        qDebug() << "Vous ne pouvez modifier que vos propres articles.";
    }
}

// ----- SUPPRESSION -----
void Auteur::supprimerArticle(Article &article)
{
    if (article.getIdAuteur() == this->getIdUtilisateur()) {
        article.setContenu(""); // logique simple de suppression
    } else {
        qDebug() << "Vous ne pouvez supprimer que vos propres articles.";
    }
}
