#include "article.h"
#include <QDebug>


Article::Article()
    : titre(""),
    contenu(""),
    id_Auteur(0),
    idCategorie(0),
    statut("BROUILLON"),
    nombreVues(0),
    nombreCommentaires(0),
    nombreLikes(0),
    nombreDislikes(0)
{
}

Article::Article(const QString& t, const QString& c, int auteur, int cat)
    : titre(t),
    contenu(c),
    id_Auteur(auteur),
    idCategorie(cat),
    statut("BROUILLON"),
    nombreVues(0),
    nombreCommentaires(0),
    nombreLikes(0),
    nombreDislikes(0)
{
}


QString Article::getTitre() const { return titre; }
int Article::getId_Auteur() const { return id_Auteur; }
int Article::getIdCategorie() const { return idCategorie; }
QString Article::getStatut() const { return statut; }
int Article::getNombreVues() const { return nombreVues; }
int Article::getNombreLikes() const { return nombreLikes; }
int Article::getNombreDislikes() const { return nombreDislikes; }
QString Article::getContenu() const {
    return contenu;
}


void Article::setTitre(const QString& t) { titre = t; }
void Article::setStatut(const QString& s) { statut = s; }
void Article::setContenu(const QString &c) {
    contenu = c;
}



void Article::incrementerVues() { ++nombreVues; }
void Article::incrementerLikes() { ++nombreLikes; }
void Article::incrementerDislikes() { ++nombreDislikes; }
void Article::incrementerCommentaires() { ++nombreCommentaires; }


bool Article::create()
{

    qDebug() << "Article::create() called";
    return true;
}

Article* Article::read(int id)
{

    qDebug() << "Article::read(" << id << ")";
    return nullptr;
}

bool Article::update()
{

    qDebug() << "Article::update() called";
    return true;
}

bool Article::remove()
{

    qDebug() << "Article::remove() called";
    return true;
}

QList<Article*> Article::listAll()
{
    qDebug() << "Article::listAll() called";
    return {};
}

void Article::publier()
{
    statut = "PUBLIE";
}


void Article::afficherInfos() const
{
    qDebug() << "=== Article ===";
    qDebug() << "Titre:" << titre;
    qDebug() << "Auteur ID:" << id_Auteur;
    qDebug() << "Categorie ID:" << idCategorie;
    qDebug() << "Statut:" << statut;
    qDebug() << "Vues:" << nombreVues;
    qDebug() << "Commentaires:" << nombreCommentaires;
    qDebug() << "Likes:" << nombreLikes;
    qDebug() << "Dislikes:" << nombreDislikes;
}
