#include <QApplication>
#include <QDebug>

#include "database.h"

// DAOs
#include "articledao.h"
#include "commentairedao.h"
#include "likedislikedao.h"

// Entities
#include "article.h"
#include "commentaire.h"
#include "like_dislike.h"
#include "auteur.h"
#include "lecteur.h"
#include "admin.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // ===============================
    // 1️⃣ DATABASE CONNECTION
    // ===============================
    Database db;
    if (!db.connect()) {
        qDebug() << "❌ DB connection failed";
        return -1;
    }
    qDebug() << "✅ DB connected";

    // ===============================
    // 2️⃣ ARTICLE TEST
    // ===============================
    Article art(
        "Titre test",
        "Contenu test",
        QDate::currentDate(),
        "img.png",
        1
        );

    ArticleDAO articleDao;
    articleDao.insert(art);
    qDebug() << "✅ Article inserted";

    // ===============================
    // 3️⃣ COMMENTAIRE TEST
    // ===============================
    CommentaireDAO comDao;
    QList<Commentaire> commentaires = comDao.findByArticle(1);

    for (const Commentaire &c : commentaires) {
        c.afficher();   // 🔥 polymorphism test
    }

    // ===============================
    // 4️⃣ LIKE / DISLIKE TEST
    // ===============================
    Like_Dislike like(0, 1, 1, true);
    LikeDislikeDAO likeDao;
    likeDao.insert(like);

    QList<Like_Dislike> likes = likeDao.findByArticle(1);
    for (const Like_Dislike &l : likes) {
        l.afficher();
    }

    // ===============================
    // 5️⃣ UTILISATEUR POLYMORPHISM TEST
    // ===============================
    Utilisateur* u1 = new Auteur(1, "Auteur", "a@mail.com", "123", QDate::currentDate(), "", "bio");
    Utilisateur* u2 = new Lecteur(2, "Lecteur", "l@mail.com", "123", QDate::currentDate(), "");
    Utilisateur* u3 = new Administrateur(3, "Admin", "ad@mail.com", "123", QDate::currentDate(), "");

    qDebug() << u1->getRole();
    qDebug() << u2->getRole();
    qDebug() << u3->getRole();

    delete u1;
    delete u2;
    delete u3;

    qDebug() << "✅ ALL TESTS FINISHED";

    return a.exec();
}
