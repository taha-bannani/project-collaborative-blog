#ifndef COMMENTAIRE_H
#define COMMENTAIRE_H

#include <QObject>
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





#endif // COMMENTAIRE_H
