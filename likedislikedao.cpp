#include "LikeDislikeDAO.h"

LikeDislikeDAO::LikeDislikeDAO() {}


bool LikeDislikeDAO::insert(const Like_Dislike &ld)
{
    QSqlQuery query;
    query.prepare(
        "INSERT INTO LIKE_DISLIKE "
        "(ID_INTERACTION, ID_UTILISATEUR, ID_ARTICLE, IS_LIKE) "
        "VALUES (:idI, :idU, :idA, :isLike)"
        );

    query.bindValue(":idI", ld.getId_Interaction());
    query.bindValue(":idU", ld.getId_Utilisateur());
    query.bindValue(":idA", ld.getId_Article());
    query.bindValue(":isLike", ld.getIsLike());

    if (!query.exec()) {
        qDebug() << "Insert Like_Dislike failed:" << query.lastError().text();
        return false;
    }
    return true;
}

Like_Dislike* LikeDislikeDAO::getById(int idInteraction)
{
    QSqlQuery query;
    query.prepare(
        "SELECT * FROM LIKE_DISLIKE WHERE ID_INTERACTION = :id"
        );
    query.bindValue(":id", idInteraction);

    if (query.exec() && query.next()) {
        return new Like_Dislike(
            query.value("ID_INTERACTION").toInt(),
            query.value("ID_UTILISATEUR").toInt(),
            query.value("ID_ARTICLE").toInt(),
            query.value("IS_LIKE").toBool()
            );
    }
    return nullptr;
}

bool LikeDislikeDAO::update(const Like_Dislike &ld)
{
    QSqlQuery query;
    query.prepare(
        "UPDATE LIKE_DISLIKE SET IS_LIKE = :isLike "
        "WHERE ID_INTERACTION = :id"
        );

    query.bindValue(":isLike", ld.getIsLike());
    query.bindValue(":id", ld.getId_Interaction());

    if (!query.exec()) {
        qDebug() << "Update Like_Dislike failed:" << query.lastError().text();
        return false;
    }
    return true;
}

bool LikeDislikeDAO::remove(int idInteraction)
{
    QSqlQuery query;
    query.prepare(
        "DELETE FROM LIKE_DISLIKE WHERE ID_INTERACTION = :id"
        );
    query.bindValue(":id", idInteraction);

    if (!query.exec()) {
        qDebug() << "Delete Like_Dislike failed:" << query.lastError().text();
        return false;
    }
    return true;
}

QList<Like_Dislike*> LikeDislikeDAO::getAll()
{
    QList<Like_Dislike*> list;
    QSqlQuery query("SELECT * FROM LIKE_DISLIKE");

    while (query.next()) {
        list.append(new Like_Dislike(
            query.value("ID_INTERACTION").toInt(),
            query.value("ID_UTILISATEUR").toInt(),
            query.value("ID_ARTICLE").toInt(),
            query.value("IS_LIKE").toBool()
            ));
    }
    return list;
}

QList<Like_Dislike*> LikeDislikeDAO::getByArticle(int idArticle)
{
    QList<Like_Dislike*> list;
    QSqlQuery query;
    query.prepare(
        "SELECT * FROM LIKE_DISLIKE WHERE ID_ARTICLE = :idA"
        );
    query.bindValue(":idA", idArticle);

    if (query.exec()) {
        while (query.next()) {
            list.append(new Like_Dislike(
                query.value("ID_INTERACTION").toInt(),
                query.value("ID_UTILISATEUR").toInt(),
                query.value("ID_ARTICLE").toInt(),
                query.value("IS_LIKE").toBool()
                ));
        }
    }
    return list;
}
