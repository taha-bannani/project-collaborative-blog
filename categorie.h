#ifndef CATEGORIE_H
#define CATEGORIE_H

#include <string>
using namespace std;

class Categorie {

private:
    int idCategorie;
    string nom;
    string description;
    string tags;

public:

    Categorie();
    Categorie(int id, string n, string d, string t);

    int getIdCategorie() const;
    string getNom() const;
    string getDescription() const;
    string getTags() const;
    int getIdCategorie();
    string getNom();
    string getDescription();
    string getTags();

    void setIdCategorie(int id);
    void setNom(string n);
    void setDescription(string d);
    void setTags(string t);

    void saisir();
    void afficherInfos();
    void afficherResume();
    bool estValide()const ;
    bool estValide();
    void vider();
    bool comparer(Categorie c);
    string toString();


    static int rechercher(Categorie tab[], int n, int id);
    static void ajouter(Categorie tab[], int &n);
    static void supprimer(Categorie tab[], int &n, int id);
    static void modifier(Categorie tab[], int n, int id);


    void afficherInfos() const;

};

#endif
