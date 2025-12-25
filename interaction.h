#ifndef INTERACTION_H
#define INTERACTION_H

#include <QString>
#include <QJsonObject>
#include <QList>
#include <QDateTime>

class Interaction {
protected:
    int id_Interaction;
    int id_Utilisateur;
    int id_Article;
    QString typeInteraction;
    QDateTime dateInteraction;

public:
    Interaction();
    Interaction(int id_Interaction,int id_Utilisateur, int id_Article, const QString& type);
    virtual ~Interaction();

    int getId_Interaction() const;
    int getId_Utilisateur() const;
    int getId_Article() const;
    QString getTypeInteraction() const;
    QDateTime getDateInteraction() const;

    void setId_Interaction(int id);



    virtual bool create();
    static Interaction* read(int id);
    virtual bool update();
    virtual bool remove();
    static QList<Interaction*> listAll();

    virtual void afficherInfos() const;
};

#endif // INTERACTION_H
