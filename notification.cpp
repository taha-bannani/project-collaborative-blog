#include "notification.h"
#include <QDebug>


Notification::Notification()
    : idNotification(0),
    id_Utilisateur(0),
    id_Interaction(0),
    message(""),
    typeNotification(""),
    lue(false),
    dateCreation(QDateTime::currentDateTime())
{
}

Notification::Notification(int idUser,
                           int idInteraction,
                           const QString& msg,
                           const QString& type)
    : idNotification(0),
    id_Utilisateur(idUser),
    id_Interaction(idInteraction),
    message(msg),
    typeNotification(type),
    lue(false),
    dateCreation(QDateTime::currentDateTime())
{
}



int Notification::getIdNotification() const
{
    return idNotification;
}

int Notification::getId_Utilisateur() const
{
    return id_Utilisateur;
}

int Notification::getId_Interaction() const
{
    return id_Interaction;
}

QString Notification::getMessage() const
{
    return message;
}

QString Notification::getTypeNotification() const
{
    return typeNotification;
}

bool Notification::isLue() const
{
    return lue;
}

QDateTime Notification::getDateCreation() const
{
    return dateCreation;
}


void Notification::setIdNotification(int id)
{
    idNotification = id;
}

void Notification::setLue(bool l)
{
    lue = l;
}


bool Notification::create()
{
    qDebug() << "Notification created (stub)";
    return true;
}

Notification* Notification::read(int id)
{
    qDebug() << "Read notification id:" << id << "(stub)";
    return nullptr;
}

bool Notification::update()
{
    qDebug() << "Notification updated (stub)";
    return true;
}

bool Notification::remove()
{
    qDebug() << "Notification removed (stub)";
    return true;
}

QList<Notification*> Notification::listAll()
{
    qDebug() << "List all notifications (stub)";
    return {};
}

QList<Notification*> Notification::listByUser(int idUser)
{
    qDebug() << "List notifications for user:" << idUser << "(stub)";
    return {};
}


void Notification::marquerCommeLue()
{
    lue = true;
    qDebug() << "Notification marked as read";
}



void Notification::afficherInfos() const
{
    qDebug() << "=== Notification ===";
    qDebug() << "ID:" << idNotification;
    qDebug() << "User ID:" << id_Utilisateur;
    qDebug() << "Interaction ID:" << id_Interaction;
    qDebug() << "Message:" << message;
    qDebug() << "Type:" << typeNotification;
    qDebug() << "Read:" << (lue ? "Yes" : "No");
    qDebug() << "Date:" << dateCreation.toString();
}
