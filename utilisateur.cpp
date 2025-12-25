#include "utilisateur.h"
#include <QDebug>

Utilisateur::Utilisateur()
    : id_Utilisateur(0),
    nom(""),
    email(""),
    motDePasse(""),
    dateInscription(QDate::currentDate()),
    photoProfil(""),
    role("")
{
}

Utilisateur::Utilisateur(const QString& n,
                         const QString& p,
                         const QString& e,
                         const QString& mdp,
                         const QString& r)
    : id_Utilisateur(0),
    nom(n),
    email(e),
    motDePasse(mdp),
    dateInscription(QDate::currentDate()),
    photoProfil(p),
    role(r)
{
}

int Utilisateur::getId_Utilisateur() const
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

QString Utilisateur::getMotDepass() const
{
    return motDePasse;
}

QString Utilisateur::getrole() const
{
    return role;
}


void Utilisateur::setId_Utilisateur(int id)
{
    id_Utilisateur = id;
}

void Utilisateur::setNom(const QString& n)
{
    nom = n;
}

void Utilisateur::setPrenom(const QString& p)
{
    photoProfil = p;   // you used "prenom" but stored in photoProfil
}

void Utilisateur::setEmail(const QString& e)
{
    email = e;
}


bool Utilisateur::create()
{
    qDebug() << "Utilisateur created (stub)";
    return true;
}

Utilisateur* Utilisateur::read(int id)
{
    qDebug() << "Read utilisateur id:" << id << "(stub)";
    return nullptr;
}

bool Utilisateur::update()
{
    qDebug() << "Utilisateur updated (stub)";
    return true;
}

bool Utilisateur::remove()
{
    qDebug() << "Utilisateur removed (stub)";
    return true;
}

QList<Utilisateur*> Utilisateur::listAll()
{
    qDebug() << "List all utilisateurs (stub)";
    return {};
}


void Utilisateur::afficherInfos() const
{
    qDebug() << "=== Utilisateur ===";
    qDebug() << "ID:" << id_Utilisateur;
    qDebug() << "Nom:" << nom;
    qDebug() << "Email:" << email;
    qDebug() << "Role:" << role;
    qDebug() << "Date inscription:" << dateInscription.toString();
}
