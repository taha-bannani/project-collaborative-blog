#include "commentaire.h"

// ----- CONSTRUCTEURS -----
Commentaire::Commentaire() : Interaction(), contenu("") {}

Commentaire::Commentaire(int id_Interaction,
                          QString contenu,
                         int id_Article,
                         int id_Utilisateur)
    : Interaction(id_Interaction, id_Utilisateur, id_Article, date),
    contenu(contenu)
{
}

// ----- GETTERS / SETTERS -----
QString Commentaire::getContenu() const {
    return contenu;
}

void Commentaire::setContenu(const QString &value) {
    contenu = value;
}
void Commentaire::afficher() const
{
    qDebug() << "Commentaire:"
             << contenu
             << "| Article:" << id_Article
             << "| User:" << id_Utilisateur;
}

