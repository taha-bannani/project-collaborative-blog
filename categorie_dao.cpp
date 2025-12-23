#include "categorie_dao.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include <QDebug>

bool CategorieDAO::insert(const Categorie& c)
{
    QSqlQuery query;
    query.prepare(
        "INSERT INTO categorie (id_categorie, nom, description, tags) "
        "VALUES (:id, :nom, :description, :tags)"
        );

    query.bindValue(":id", c.getIdCategorie());
    query.bindValue(":nom", QString::fromStdString(c.getNom()));
    query.bindValue(":description", QString::fromStdString(c.getDescription()));
    query.bindValue(":tags", QString::fromStdString(c.getTags()));

    if (!query.exec()) {
        qDebug() << "Insert Categorie failed:" << query.lastError().text();
        return false;
    }
    return true;
}

bool CategorieDAO::findById(int id, Categorie& c) {
    QSqlQuery query;
    query.prepare("SELECT * FROM categorie WHERE id_categorie = :id");
    query.bindValue(":id", id);

    if (!query.exec() || !query.next())
        return false;

    c.setIdCategorie(query.value("id_categorie").toInt());
    c.setNom(query.value("nom").toString().toStdString());
    c.setDescription(query.value("description").toString().toStdString());
    c.setTags(query.value("tags").toString().toStdString());

    return true;
}

bool CategorieDAO::update(const Categorie& c) {
    QSqlQuery query;
    query.prepare(
        "UPDATE categorie SET nom=:nom, description=:description, tags=:tags "
        "WHERE id_categorie=:id"
        );

    query.bindValue(":id", c.getIdCategorie());
    query.bindValue(":nom", QString::fromStdString(c.getNom()));
    query.bindValue(":description", QString::fromStdString(c.getDescription()));
    query.bindValue(":tags", QString::fromStdString(c.getTags()));

    return query.exec();
}
bool CategorieDAO::remove(int id) {
    QSqlQuery query;
    query.prepare("DELETE FROM categorie WHERE id_categorie=:id");
    query.bindValue(":id", id);
    return query.exec();
}
