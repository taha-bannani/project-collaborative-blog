#include "Categorie_dAO.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include <QDebug>

bool CategorieDAO::insert(const Categorie& c)
{
    QSqlQuery query;
    query.prepare(
        "INSERT INTO CATEGORIE (nom, description, tags) "
        "VALUES (:nom, :desc, :tags)"
        );

    query.bindValue(":nom", QString::fromStdString(c.getNom()));
    query.bindValue(":desc", QString::fromStdString(c.getDescription()));
    query.bindValue(":tags", QString::fromStdString(c.getTags()));

    if (!query.exec()) {
        qDebug() << "Categorie insert error:" << query.lastError().text();
        return false;
    }
    return true;
}

Categorie* CategorieDAO::findById(int id)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM CATEGORIE WHERE id_categorie = :id");
    query.bindValue(":id", id);

    if (!query.exec() || !query.next()) {
        return nullptr;
    }

    Categorie* c = new Categorie(
        query.value("id_categorie").toInt(),
        query.value("nom").toString().toStdString(),
        query.value("description").toString().toStdString(),
        query.value("tags").toString().toStdString()
        );

    return c;
}

QList<Categorie*> CategorieDAO::listAll()
{
    QList<Categorie*> list;
    QSqlQuery query("SELECT * FROM CATEGORIE");

    while (query.next()) {
        Categorie* c = new Categorie(
            query.value("id_categorie").toInt(),
            query.value("nom").toString().toStdString(),
            query.value("description").toString().toStdString(),
            query.value("tags").toString().toStdString()
            );
        list.append(c);
    }
    return list;
}

bool CategorieDAO::update(const Categorie& c)
{
    QSqlQuery query;
    query.prepare(
        "UPDATE CATEGORIE SET "
        "nom = :nom, description = :desc, tags = :tags "
        "WHERE id_categorie = :id"
        );

    query.bindValue(":nom", QString::fromStdString(c.getNom()));
    query.bindValue(":desc", QString::fromStdString(c.getDescription()));
    query.bindValue(":tags", QString::fromStdString(c.getTags()));
    query.bindValue(":id", c.getIdCategorie());

    if (!query.exec()) {
        qDebug() << "Categorie update error:" << query.lastError().text();
        return false;
    }
    return true;
}

bool CategorieDAO::remove(int id)
{
    QSqlQuery query;
    query.prepare("DELETE FROM CATEGORIE WHERE id_categorie = :id");
    query.bindValue(":id", id);

    if (!query.exec()) {
        qDebug() << "Categorie delete error:" << query.lastError().text();
        return false;
    }
    return true;
}
