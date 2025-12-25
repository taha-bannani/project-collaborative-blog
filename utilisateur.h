#ifndef UTILISATEUR_H
#define UTILISATEUR_H

#include <QString>
#include <QDate>

class Utilisateur
{
protected:
    int id_Utilisateur;
    QString nom;
    QString email;
    QString motDePasse;
    QDate dateInscription;
    QString photoProfil;
    QString role;

public:
    Utilisateur();
    Utilisateur(const QString& n, const QString& p, const QString& e,
                const QString& mdp, const QString& r);

    virtual ~Utilisateur() {}

    int getId_Utilisateur() const;
    QString getNom() const;
    QString getEmail() const;
    QString getMotDepass() const;
    QString getrole() const;


    void setId_Utilisateur(int id);
    void setNom(const QString& n);
    void setPrenom(const QString& p);
    void setEmail(const QString& e);



    virtual bool create();
    static Utilisateur* read(int id);
    virtual bool update();
    virtual bool remove();
    static QList<Utilisateur*> listAll();

    virtual QString getRole() const = 0;

    virtual void afficherInfos() const ;
};

#endif
