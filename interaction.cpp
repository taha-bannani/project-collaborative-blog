#include "Interaction.h"

// Constructors
Interaction::Interaction()
    : id_Interaction(0), id_Utilisateur(0), id_Article(0), date(QDate::currentDate()) {}

Interaction::Interaction(int id_Interaction, int id_Utilisateur,
                         int id_Article, const QDate &date)
    : id_Interaction(id_Interaction),
    id_Utilisateur(id_Utilisateur),
    id_Article(id_Article),
    date(date)
{}

// Getters
int Interaction::getId_Interaction() const { return id_Interaction; }
int Interaction::getId_Utilisateur() const { return id_Utilisateur; }
int Interaction::getId_Article()     const { return id_Article; }
QDate Interaction::getDate()         const { return date; }

// Setters
void Interaction::setDate(const QDate &d) { date = d; }

// Logic
bool Interaction::estLieA(int idArt) const {
    return id_Article == idArt;
}

bool Interaction::estEffectuePar(int idUser) const {
    return id_Utilisateur == idUser;
}
