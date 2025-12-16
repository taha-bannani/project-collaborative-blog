#ifndef UTILISATEUR_H
#define UTILISATEUR_H

#include <QObject>
#include <QString>
#include <QDate>

class Utilisateur
{
protected:
    int id_Utilisateur;
    QString nom;
    QString email;
    QString motDePasse;
    QDate dateInscription;
    QString photoProfil;

public:
    Utilisateur();
    Utilisateur(int id, const QString &nom, const QString &email,
                const QString &motDePasse, const QDate &dateInscription,
                const QString &photoProfil);

    virtual ~Utilisateur() {}

    // Getters
    int getIdUtilisateur() const;
    QString getNom() const;
    QString getEmail() const;

    // Setters
    void setNom(const QString &nom);
    void setEmail(const QString &email);

    // Role (polymorphism)
    virtual QString getRole() const = 0;
};

#endif
