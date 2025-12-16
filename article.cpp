#include "article.h"
#include <QDebug>

Article::Article() {}

Article::Article(const QString &titre,
                 const QString &contenu,
                 const QDate &datePublication,
                 const QString &imageCouverture,
                 int idAuteur)
    : titre(titre),
    contenu(contenu),
    datePublication(datePublication),
    imageCouverture(imageCouverture),
    idAuteur(idAuteur)
{}

QString Article::getTitre() const { return titre; }
QString Article::getContenu() const { return contenu; }
QDate Article::getDatePublication() const { return datePublication; }
QString Article::getImageCouverture() const { return imageCouverture; }
int Article::getIdAuteur() const { return idAuteur; }

void Article::setTitre(const QString &titre) { this->titre = titre; }
void Article::setContenu(const QString &contenu) { this->contenu = contenu; }
void Article::setDatePublication(const QDate &date) { this->datePublication = date; }
void Article::setImageCouverture(const QString &image) { this->imageCouverture = image; }
void Article::setIdAuteur(int idAuteur) { this->idAuteur = idAuteur; }

void Article::publier() {
    qDebug() << "Article publié:" << titre;
}

void Article::consulter() const {
    qDebug() << "Lecture de l'article:" << titre;
}

void Article::modifier(const QString &nouveauContenu) {
    contenu = nouveauContenu;
}

void Article::supprimer() {
    qDebug() << "Article supprimé";
}

QList<Article> Article::rechercher(const QString &motCle) {
    qDebug() << "Recherche d'articles contenant:" << motCle;
    return {};
}
