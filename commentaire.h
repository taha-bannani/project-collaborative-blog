#ifndef COMMENTAIRE_H
#define COMMENTAIRE_H

#include <QObject>
<<<<<<< HEAD
#include "interaction.h"


class Commentaire :public Interaction
{private:

    QString contenu;
public:
    Commentaire();
    Commentaire(int id_Intiracttion,QString contenu,int id_Article,int id_Utilisateur);

    QString getContenu()const;

    void setContenu(const QString &value);
    void afficher() const override;

    void ajouterCommentaire();
    void supprimerCommentaire();


};





=======

class commentaire : public QObject
{
    Q_OBJECT
public:
    explicit commentaire(QObject *parent = nullptr);

signals:
};

>>>>>>> 83403929ce121ce417630a984ae9fd2c9ad199d3
#endif // COMMENTAIRE_H
