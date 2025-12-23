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
    // Constructors
    Categorie();
    Categorie(int id, string n, string d, string t);

    // Getters
<<<<<<< HEAD
    int getIdCategorie() const;
    string getNom() const;
    string getDescription() const;
    string getTags() const;
=======
    int getIdCategorie();
    string getNom();
    string getDescription();
    string getTags();
>>>>>>> 83403929ce121ce417630a984ae9fd2c9ad199d3

    // Setters
    void setIdCategorie(int id);
    void setNom(string n);
    void setDescription(string d);
    void setTags(string t);

    // Methods
    void saisir();
    void afficher();
    void afficherResume();
<<<<<<< HEAD
    bool estValide()const ;
=======
    bool estValide();
    void vider();
    bool comparer(Categorie c);
>>>>>>> 83403929ce121ce417630a984ae9fd2c9ad199d3
    string toString();

    // Static methods
    static int rechercher(Categorie tab[], int n, int id);
    static void ajouter(Categorie tab[], int &n);
    static void supprimer(Categorie tab[], int &n, int id);
    static void modifier(Categorie tab[], int n, int id);
};

#endif
