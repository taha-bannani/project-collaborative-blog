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
<<<<<<< HEAD
QString Commentaire::getContenu() const {
=======
QString Commentaire::getContenu() {
>>>>>>> 83403929ce121ce417630a984ae9fd2c9ad199d3
    return contenu;
}

void Commentaire::setContenu(const QString &value) {
    contenu = value;
}
<<<<<<< HEAD
void Commentaire::afficher() const
{
    qDebug() << "Commentaire:"
             << contenu
             << "| Article:" << id_Article
             << "| User:" << id_Utilisateur;
}

=======
>>>>>>> 83403929ce121ce417630a984ae9fd2c9ad199d3
