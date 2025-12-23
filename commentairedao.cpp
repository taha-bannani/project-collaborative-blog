#include "commentairedao.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

bool CommentaireDAO::insert(const Commentaire &c) {
    QSqlQuery query;
    query.prepare(
        "INSERT INTO commentaire "
        "(id_interaction, id_utilisateur, id_article, contenu) "
        "VALUES (:id, :user, :article, :contenu)"
        );

    query.bindValue(":id", c.getId_Interaction());
    query.bindValue(":user", c.getId_Utilisateur());
    query.bindValue(":article", c.getId_Article());
    query.bindValue(":contenu", c.getContenu());

    if (!query.exec()) {
        qDebug() << "Insert Commentaire failed:" << query.lastError().text();
        return false;
    }
    return true;
}

bool CommentaireDAO::update(const Commentaire &c) {
    QSqlQuery query;
    query.prepare(
        "UPDATE commentaire SET contenu = :contenu "
        "WHERE id_interaction = :id"
        );

    query.bindValue(":contenu", c.getContenu());
    query.bindValue(":id", c.getId_Interaction());

    if (!query.exec()) {
        qDebug() << "Update Commentaire failed:" << query.lastError().text();
        return false;
    }
    return true;
}

bool CommentaireDAO::remove(int idInteraction) {
    QSqlQuery query;
    query.prepare(
        "DELETE FROM commentaire WHERE id_interaction = :id"
        );
    query.bindValue(":id", idInteraction);

    if (!query.exec()) {
        qDebug() << "Delete Commentaire failed:" << query.lastError().text();
        return false;
    }
    return true;
}

QList<Commentaire> CommentaireDAO::findByArticle(int idArticle) {
    QList<Commentaire> list;
    QSqlQuery query;

    query.prepare(
        "SELECT id_interaction, contenu, id_article, id_utilisateur "
        "FROM commentaire WHERE id_article = :id"
        );
    query.bindValue(":id", idArticle);
    query.exec();

    while (query.next()) {
        Commentaire c(
            query.value(0).toInt(),
            query.value(1).toString(),
            query.value(2).toInt(),
            query.value(3).toInt()
            );
        list.append(c);
    }
    return list;
}
