#include "CommentaireDAO.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include <QDebug>

bool CommentaireDAO::insert(const Commentaire& c)
{
    QSqlQuery query;
    query.prepare(
        "INSERT INTO COMMENTAIRE "
        "(id_utilisateur, id_article, contenu, date_interaction) "
        "VALUES (:user, :article, :contenu, SYSDATE)"
        );

    query.bindValue(":user", c.getId_Utilisateur());
    query.bindValue(":article", c.getId_Article());
    query.bindValue(":contenu", c.getContenu());

    if (!query.exec()) {
        qDebug() << "Commentaire insert error:" << query.lastError().text();
        return false;
    }
    return true;
}

QList<Commentaire*> CommentaireDAO::findByArticle(int idArticle)
{
    QList<Commentaire*> list;

    QSqlQuery query;
    query.prepare(
        "SELECT * FROM COMMENTAIRE WHERE id_article = :id"
        );
    query.bindValue(":id", idArticle);

    if (!query.exec()) {
        qDebug() << query.lastError().text();
        return list;
    }

    while (query.next()) {
        Commentaire* c = new Commentaire(
            query.value("id_interaction").toInt(),
            query.value("contenu").toString(),
            query.value("id_article").toInt(),
            query.value("id_utilisateur").toInt()
            );
        list.append(c);
    }
    return list;
}

bool CommentaireDAO::remove(int idInteraction)
{
    QSqlQuery query;
    query.prepare(
        "DELETE FROM COMMENTAIRE WHERE id_interaction = :id"
        );
    query.bindValue(":id", idInteraction);

    if (!query.exec()) {
        qDebug() << "Commentaire delete error:" << query.lastError().text();
        return false;
    }
    return true;
}
