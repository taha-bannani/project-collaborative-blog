#include "ArticleDAO.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include <QDebug>

bool ArticleDAO::insert(const Article& article)
{
    QSqlQuery query;
    query.prepare(
        "INSERT INTO ARTICLE "
        "(titre, contenu, id_auteur, id_categorie, statut, "
        "nombre_vues, nombre_commentaires, nombre_likes, nombre_dislikes) "
        "VALUES "
        "(:titre, :contenu, :auteur, :categorie, :statut, "
        "0, 0, 0, 0)"
        );

    query.bindValue(":titre", article.getTitre());
    query.bindValue(":contenu", article.getContenu());
    query.bindValue(":auteur", article.getId_Auteur());
    query.bindValue(":categorie", article.getIdCategorie());
    query.bindValue(":statut", article.getStatut());

    if (!query.exec()) {
        qDebug() << "Article insert error:" << query.lastError().text();
        return false;
    }
    return true;
}

Article* ArticleDAO::findById(int id)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM ARTICLE WHERE id_article = :id");
    query.bindValue(":id", id);

    if (!query.exec() || !query.next()) {
        return nullptr;
    }

    Article* a = new Article(
        query.value("titre").toString(),
        query.value("contenu").toString(),
        query.value("id_auteur").toInt(),
        query.value("id_categorie").toInt()
        );

    a->setStatut(query.value("statut").toString());
    return a;
}

QList<Article*> ArticleDAO::listAll()
{
    QList<Article*> list;
    QSqlQuery query("SELECT * FROM ARTICLE");

    while (query.next()) {
        Article* a = new Article(
            query.value("titre").toString(),
            query.value("contenu").toString(),
            query.value("id_auteur").toInt(),
            query.value("id_categorie").toInt()
            );
        a->setStatut(query.value("statut").toString());
        list.append(a);
    }
    return list;
}

bool ArticleDAO::update(const Article& article)
{
    QSqlQuery query;
    query.prepare(
        "UPDATE ARTICLE SET "
        "titre = :titre, "
        "contenu = :contenu, "
        "statut = :statut "
        "WHERE id_auteur = :auteur AND titre = :titre"
        );

    query.bindValue(":titre", article.getTitre());
    query.bindValue(":contenu", article.getContenu());
    query.bindValue(":statut", article.getStatut());
    query.bindValue(":auteur", article.getId_Auteur());

    if (!query.exec()) {
        qDebug() << "Article update error:" << query.lastError().text();
        return false;
    }
    return true;
}

bool ArticleDAO::remove(int id)
{
    QSqlQuery query;
    query.prepare("DELETE FROM ARTICLE WHERE id_article = :id");
    query.bindValue(":id", id);

    if (!query.exec()) {
        qDebug() << "Article delete error:" << query.lastError().text();
        return false;
    }
    return true;
}
