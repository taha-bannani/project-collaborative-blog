#include "UtilisateurDAO.h"
#include "Lecteur.h"
#include "Auteur.h"
#include "Admin.h"
#include <QSqlQuery>

Utilisateur* UtilisateurDAO::findById(int id) {
    QSqlQuery query;
    query.prepare("SELECT * FROM utilisateur WHERE id_utilisateur = :id");
    query.bindValue(":id", id);

    if (!query.exec() || !query.next())
        return nullptr;

    QString role = query.value("role").toString();

    if (role == "Lecteur")
        return new Lecteur(
            id,
            query.value("nom").toString(),
            query.value("email").toString(),
            query.value("mot_de_passe").toString(),
            query.value("date_inscription").toDate(),
            query.value("photo_profil").toString()
            );

    if (role == "Auteur")
        return new Auteur(
            id,
            query.value("nom").toString(),
            query.value("email").toString(),
            query.value("mot_de_passe").toString(),
            query.value("date_inscription").toDate(),
            query.value("photo_profil").toString(),
            query.value("biographie").toString()
            );

    if (role == "Administrateur")
        return new Administrateur(
            id,
            query.value("nom").toString(),
            query.value("email").toString(),
            query.value("mot_de_passe").toString(),
            query.value("date_inscription").toDate(),
            query.value("photo_profil").toString()
            );

    return nullptr;
}
