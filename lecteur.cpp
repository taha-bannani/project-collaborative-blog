#include "lecteur.h"
#include <QDebug>

// ===============================

Lecteur::Lecteur()
    : Utilisateur(),
    nombreArticlesLus(0)
{
}

Lecteur::Lecteur(const QString& n,
                 const QString& p,
                 const QString& e,
                 const QString& mdp)
    : Utilisateur(),
    nombreArticlesLus(0)
{
}


int Lecteur::getNombreArticlesLus() const
{
    return nombreArticlesLus;
}

void Lecteur::setNombreArticlesLus(int n)
{
    nombreArticlesLus = n;
}



void Lecteur::afficherInfos() const
{
    qDebug() << "=== Lecteur ===";
    qDebug() << "ID:" << id_Utilisateur;
    qDebug() << "Nom:" << nom;
    qDebug() << "Email:" << email;
    qDebug() << "Articles lus:" << nombreArticlesLus;
}
