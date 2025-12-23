#include "articledao.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

bool ArticleDAO::insert(const Article &a) {
    QSqlQuery query;
    query.prepare(
        "INSERT INTO article "
        "(titre, contenu, date_publication, image_couverture, id_auteur) "
        "VALUES (:titre, :contenu, :date_pub, :image, :id_auteur)"
        );

    query.bindValue(":titre", a.getTitre());
    query.bindValue(":contenu", a.getContenu());
    query.bindValue(":date_pub", a.getDatePublication());
    query.bindValue(":image", a.getImageCouverture());
    query.bindValue(":id_auteur", a.getIdAuteur());

    if (!query.exec()) {
        qDebug() << "Insert Article failed:" << query.lastError().text();
        return false;
    }
    return true;
}

bool ArticleDAO::update(int id, const Article &a) {
    QSqlQuery query;
    query.prepare(
        "UPDATE article SET "
        "titre = :titre, "
        "contenu = :contenu, "
        "date_publication = :date_pub, "
        "image_couverture = :image, "
        "id_auteur = :id_auteur "
        "WHERE id_article = :id"
        );

    query.bindValue(":titre", a.getTitre());
    query.bindValue(":contenu", a.getContenu());
    query.bindValue(":date_pub", a.getDatePublication());
    query.bindValue(":image", a.getImageCouverture());
    query.bindValue(":id_auteur", a.getIdAuteur());
    query.bindValue(":id", id);

    if (!query.exec()) {
        qDebug() << "Update Article failed:" << query.lastError().text();
        return false;
    }
    return true;
}

bool ArticleDAO::remove(int id) {
    QSqlQuery query;
    query.prepare("DELETE FROM article WHERE id_article = :id");
    query.bindValue(":id", id);

    if (!query.exec()) {
        qDebug() << "Delete Article failed:" << query.lastError().text();
        return false;
    }
    return true;
}

QList<Article> ArticleDAO::findAll() {
    QList<Article> list;
    QSqlQuery query("SELECT titre, contenu, date_publication, image_couverture, id_auteur FROM article");

    while (query.next()) {
        Article a(
            query.value(0).toString(),
            query.value(1).toString(),
            query.value(2).toDate(),
            query.value(3).toString(),
            query.value(4).toInt()
            );
        list.append(a);
    }
    return list;
}

QList<Article> ArticleDAO::findByKeyword(const QString &keyword) {
    QList<Article> list;
    QSqlQuery query;
    query.prepare(
        "SELECT titre, contenu, date_publication, image_couverture, id_auteur "
        "FROM article WHERE titre LIKE :kw OR contenu LIKE :kw"
        );
    query.bindValue(":kw", "%" + keyword + "%");
    query.exec();

    while (query.next()) {
        Article a(
            query.value(0).toString(),
            query.value(1).toString(),
            query.value(2).toDate(),
            query.value(3).toString(),
            query.value(4).toInt()
            );
        list.append(a);
    }
    return list;
}
