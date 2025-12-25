#include "interaction.h"
#include <QDebug>

Interaction::Interaction()
    : id_Interaction(0),
    id_Utilisateur(0),
    id_Article(0),
    typeInteraction(""),
    dateInteraction(QDateTime::currentDateTime())
{
}

Interaction::Interaction(int idInteraction,
                         int idUtilisateur,
                         int idArticle,
                         const QString& type)
    : id_Interaction(idInteraction),
    id_Utilisateur(idUtilisateur),
    id_Article(idArticle),
    typeInteraction(type),
    dateInteraction(QDateTime::currentDateTime())
{
}

Interaction::~Interaction()
{
}


int Interaction::getId_Interaction() const
{
    return id_Interaction;
}

int Interaction::getId_Utilisateur() const
{
    return id_Utilisateur;
}

int Interaction::getId_Article() const
{
    return id_Article;
}

QString Interaction::getTypeInteraction() const
{
    return typeInteraction;
}

QDateTime Interaction::getDateInteraction() const
{
    return dateInteraction;
}


void Interaction::setId_Interaction(int id)
{
    id_Interaction = id;
}


bool Interaction::create()
{
    qDebug() << "Interaction created (stub)";
    return true;
}

Interaction* Interaction::read(int id)
{
    qDebug() << "Read Interaction id:" << id << "(stub)";
    return nullptr;
}

bool Interaction::update()
{
    qDebug() << "Interaction updated (stub)";
    return true;
}

bool Interaction::remove()
{
    qDebug() << "Interaction removed (stub)";
    return true;
}

QList<Interaction*> Interaction::listAll()
{
    qDebug() << "List all interactions (stub)";
    return {};
}


void Interaction::afficherInfos() const
{
    qDebug() << "=== Interaction ===";
    qDebug() << "ID:" << id_Interaction;
    qDebug() << "User ID:" << id_Utilisateur;
    qDebug() << "Article ID:" << id_Article;
    qDebug() << "Type:" << typeInteraction;
    qDebug() << "Date:" << dateInteraction.toString();
}
