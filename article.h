#ifndef ARTICLE_H
#define ARTICLE_H

#include <QString>
#include <QJsonObject>
#include <QList>

class Article {
private:
    QString titre;
    QString contenu;
    int id_Auteur;
    int idCategorie;
    QString statut;
    int nombreVues;
    int nombreCommentaires;
    int nombreLikes;
    int nombreDislikes;

public:
    Article();
    Article(const QString& t, const QString& c, int auteur, int cat);


    QString getTitre() const;
    QString getContenu() const;
    int getId_Auteur() const;
    int getIdCategorie() const;
    QString getStatut() const;
    int getNombreVues() const;
    int getNombreLikes() const;
    int getNombreDislikes() const;

    void setTitre(const QString& t);  
    void setStatut(const QString& s);
    void incrementerVues();
    void incrementerLikes();
    void incrementerDislikes();
    void incrementerCommentaires();
    void setContenu(const QString& c);


    bool create();
    static Article* read(int id);
    bool update();
    bool remove();
    static QList<Article*> listAll();

    void publier();
    void afficherInfos() const;
};

#endif // ARTICLE_H
