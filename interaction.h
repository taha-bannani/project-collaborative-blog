#ifndef INTERACTION_H
#define INTERACTION_H

#include <QString>
#include <QDate>

class Interaction {
protected:
    int id_Interaction;
    int id_Utilisateur;
    int id_Article;
    QDate date;

public:
    Interaction();
<<<<<<< HEAD
    Interaction(int id_Interaction, int id_Utilisateur,int id_Article, const QDate &date);
=======
    Interaction(int id_Interaction, int id_Utilisateur,
                int id_Article, const QDate &date);
>>>>>>> 83403929ce121ce417630a984ae9fd2c9ad199d3

    virtual ~Interaction() {}

    // Getters
    int getId_Interaction() const;
    int getId_Utilisateur() const;
    int getId_Article() const;
    QDate getDate() const;

    // Setters
    void setDate(const QDate &d);

    // Logic
    bool estLieA(int idArt) const;
    bool estEffectuePar(int idUser) const;

    // Polymorphic method
    virtual void afficher() const = 0;
};

#endif
