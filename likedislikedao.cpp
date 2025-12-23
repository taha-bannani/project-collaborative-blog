#include "likedislikedao.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

bool LikeDislikeDAO::insert(const Like_Dislike &ld) {
    QSqlQuery query;
    query.prepare(
        "INSERT INTO LIKE_DISLIKE "
        "(id_interaction, id_utilisateur, id_article, is_like) "
        "VALUES (:id_inter, :id_user, :id_article, :isLikeVal)"
        );

    query.bindValue(":id_inter", ld.getId_Interaction());
    query.bindValue(":id_user",  ld.getId_Utilisateur());
    query.bindValue(":id_article", ld.getId_Article());
    query.bindValue(":is_like", ld.getIsLike());


    if (!query.exec()) {
        qDebug() << "Insert Like/Dislike failed:" << query.lastError().text();
        return false;
    }
    return true;
}

bool LikeDislikeDAO::update(const Like_Dislike &ld) {
    QSqlQuery query;
    query.prepare(
        "UPDATE like_dislike SET is_like = :isLikeVal "
        "WHERE id_interaction = :id"
        );

    query.bindValue(":isLike", ld.getIsLike() ? 1 : 0);
    query.bindValue(":id", ld.getId_Interaction());

    if (!query.exec()) {
        qDebug() << "Update Like/Dislike failed:" << query.lastError().text();
        return false;
    }
    return true;
}

bool LikeDislikeDAO::remove(int idInteraction) {
    QSqlQuery query;
    query.prepare(
        "DELETE FROM like_dislike WHERE id_interaction = :id"
        );
    query.bindValue(":id", idInteraction);

    if (!query.exec()) {
        qDebug() << "Delete Like/Dislike failed:" << query.lastError().text();
        return false;
    }
    return true;
}

int LikeDislikeDAO::countLikes(int idArticle) {
    QSqlQuery query;
    query.prepare(
        "SELECT COUNT(*) FROM like_dislike "
        "WHERE id_article = :id AND is_like = 1"
        );
    query.bindValue(":id", idArticle);
    query.exec();

    if (query.next())
        return query.value(0).toInt();
    return 0;
}

int LikeDislikeDAO::countDislikes(int idArticle) {
    QSqlQuery query;
    query.prepare(
        "SELECT COUNT(*) FROM like_dislike "
        "WHERE id_article = :id AND is_like = 0"
        );
    query.bindValue(":id", idArticle);
    query.exec();

    if (query.next())
        return query.value(0).toInt();
    return 0;
}
QList<Like_Dislike> LikeDislikeDAO::findByArticle(int idArticle)
{
    QList<Like_Dislike> list;
    QSqlQuery query;

    query.prepare("SELECT id_interaction, id_utilisateur, id_article, is_like "
                  "FROM like_dislike WHERE id_article = :id");
    query.bindValue(":id", idArticle);
    query.exec();

    while (query.next()) {
        Like_Dislike l(
            query.value(0).toInt(),
            query.value(1).toInt(),
            query.value(2).toInt(),
            query.value(3).toBool()
            );
        list.append(l);
    }
    return list;
}

