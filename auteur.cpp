#include "auteur.h"
#include <QDebug>


Auteur::Auteur(int id_Utilisateur,
               const QString &nom,
               const QString &email,
               const QString &motDePasse,
               const QDate &dateInscription,
               const QString &photoProfil,
               const QString &biographie)
    : Utilisateur(), biographie(biographie)
{

    this->id_Utilisateur = id_Utilisateur;
    this->nom = nom;
    this->email = email;
    this->motDePasse = motDePasse;
    this->dateInscription = dateInscription;
    this->photoProfil = photoProfil;
    this->role = "Auteur";
}


QString Auteur::getRole() const
{
    return "Auteur";
}


void Auteur::publierArticle(Article &article)
{
    qDebug() << " Auteur" << nom << "publie un article :"
             << article.getTitre();
}

void Auteur::modifierArticle(Article &article, const QString &contenu)
{
    article.setContenu(contenu);
    qDebug() << "️ Article modifié par l'auteur" << nom;
}

void Auteur::supprimerArticle(Article &article)
{
    qDebug() << "️ Article supprimé par l'auteur" << nom;
}

void Auteur::afficherInfos() const
{
    qDebug() << "=== Auteur ===";
    qDebug() << "ID:" << id_Utilisateur;
    qDebug() << "Nom:" << nom;
    qDebug() << "Email:" << email;
    qDebug() << "Bio:" << biographie;
}
