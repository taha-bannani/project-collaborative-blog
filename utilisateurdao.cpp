#include "utilisateurdao.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include <QDebug>

bool UtilisateurDAO::insert(const Utilisateur& u)
{
    QSqlQuery query;

    query.prepare(
        "INSERT INTO UTILISATEUR "
        "(ID_UTILISATEUR, NOM, EMAIL, MOT_DE_PASSE, ROLE) "
        "VALUES (:id, :nom, :email, :mdp, :role)"
        );

    query.bindValue(":id", u.getId_Utilisateur());
    query.bindValue(":nom", u.getNom());
    query.bindValue(":email", u.getEmail());
    query.bindValue(":mdp", u.getMotDepass());
    query.bindValue(":role", u.getRole());

    if (!query.exec()) {
        qDebug() << "Utilisateur insert error:" << query.lastError().text();
        return false;
    }

    qDebug() << "Utilisateur inserted successfully";
    return true;
}



Utilisateur* UtilisateurDAO::findById(int id)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM UTILISATEUR WHERE id_utilisateur = :id");
    query.bindValue(":id", id);

    if (!query.exec() || !query.next()) {
        return nullptr;
    }

    Utilisateur* u = nullptr;
}

QList<Utilisateur*> UtilisateurDAO::listAll()
{
    QList<Utilisateur*> list;
    QSqlQuery query("SELECT * FROM UTILISATEUR");

    while (query.next()) {

    }
    return list;
}


bool UtilisateurDAO::update(const Utilisateur& u)
{
    QSqlQuery query;
    query.prepare(
        "UPDATE UTILISATEUR SET "
        "nom = :nom, email = :email, mot_de_passe = :mdp "
        "WHERE id_utilisateur = :id"
        );

    query.bindValue(":nom", u.getNom());
    query.bindValue(":email", u.getEmail());
    query.bindValue(":mdp", u.getMotDepass());
    query.bindValue(":id", u.getId_Utilisateur());

    if (!query.exec()) {
        qDebug() << "Utilisateur update error:" << query.lastError().text();
        return false;
    }
    return true;
}

bool UtilisateurDAO::remove(int id)
{
    QSqlQuery query;
    query.prepare("DELETE FROM UTILISATEUR WHERE id_utilisateur = :id");
    query.bindValue(":id", id);

    if (!query.exec()) {
        qDebug() << "Utilisateur delete error:" << query.lastError().text();
        return false;
    }
    return true;
}
