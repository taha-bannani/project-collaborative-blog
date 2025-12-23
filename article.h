#ifndef ARTICLE_H
#define ARTICLE_H

#include <QString>
#include <QDate>
#include <QObject>

class Article
{


private:
    QString titre;
    QString contenu;
    QDate datePublication;
    QString imageCouverture;
    int idAuteur; // FK vers Auteur

public:
    // Constructor
    Article();
    Article(const QString &titre,
            const QString &contenu,
            const QDate &datePublication,
            const QString &imageCouverture,
            int idAuteur);

    // Getters
    QString getTitre() const;
    QString getContenu() const;
    QDate getDatePublication() const;
    QString getImageCouverture() const;
    int getIdAuteur() const;

    // Setters
    void setTitre(const QString &titre);
    void setContenu(const QString &contenu);
    void setDatePublication(const QDate &date);
    void setImageCouverture(const QString &image);
    void setIdAuteur(int idAuteur);

    // CRUD
    void publier();
    void consulter() const;
    void modifier(const QString &nouveauContenu);
    void supprimer();
    static QList<Article> rechercher(const QString &motCle);
};

#endif // ARTICLE_H
