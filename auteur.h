#ifndef AUTEUR_H
#define AUTEUR_H

<<<<<<< HEAD
#include "Utilisateur.h"
#include "Article.h"

class Auteur : public Utilisateur
{
private:
    QString biographie;

public:
    Auteur(int id_Utilisateur, const QString &nom, const QString &email,
           const QString &motDePasse, const QDate &dateInscription,
           const QString &photoProfil, const QString &biographie);

    QString getRole() const override;

    // Auteur-specific
    void publierArticle(Article &article);
    void modifierArticle(Article &article, const QString &contenu);
    void supprimerArticle(Article &article);
=======
#include <QObject>

class auteur : public QObject
{
    Q_OBJECT
public:
    explicit auteur(QObject *parent = nullptr);

signals:
>>>>>>> 83403929ce121ce417630a984ae9fd2c9ad199d3
};

#endif // AUTEUR_H
