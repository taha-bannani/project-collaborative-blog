#ifndef AUTEUR_H
#define AUTEUR_H

#include "Utilisateur.h"
#include "Article.h"

class Auteur : public Utilisateur
{
private:
    QString biographie;

public:
    Auteur(int id_Utilisateur,
           const QString &nom,
           const QString &email,
           const QString &motDePasse,
           const QDate &dateInscription,
           const QString &photoProfil,
           const QString &biographie);

    QString getRole() const override;

    // Auteur-specific
    void publierArticle(Article &article);
    void modifierArticle(Article &article, const QString &contenu);
    void supprimerArticle(Article &article);
    void afficherInfos() const override;
};

#endif // AUTEUR_H
