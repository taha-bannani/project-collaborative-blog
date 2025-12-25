#ifndef NOTIFICATION_H
#define NOTIFICATION_H

#include <QString>
#include <QList>
#include <QDateTime>

class Notification {
private:
    int idNotification;
    int id_Utilisateur;
    int id_Interaction;
    QString message;
    QString typeNotification;
    bool lue;
    QDateTime dateCreation;

public:
    Notification();
    Notification(int id_Utilisateur, int id_Interaction, const QString& msg, const QString& type);

    int getIdNotification() const;
    int getId_Utilisateur() const;
    int getId_Interaction() const;
    QString getMessage() const;
    QString getTypeNotification() const;
    bool isLue() const;
    QDateTime getDateCreation() const;

    void setIdNotification(int id);
    void setLue(bool l);



    bool create();
    static Notification* read(int id);
    bool update();
    bool remove();
    static QList<Notification*> listAll();
    static QList<Notification*> listByUser(int idUser);

    void marquerCommeLue();
    void afficherInfos() const;
};

#endif // NOTIFICATION_H
