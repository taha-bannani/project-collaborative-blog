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
    int getIdCategorie() const;
    string getNom() const;
    string getDescription() const;
    string getTags() const;

    // Setters
    void setIdCategorie(int id);
    void setNom(string n);
    void setDescription(string d);
    void setTags(string t);

    // Methods
    void saisir();
    void afficher();
    void afficherResume();
    bool estValide()const ;
    string toString();

    // Static methods
    static int rechercher(Categorie tab[], int n, int id);
    static void ajouter(Categorie tab[], int &n);
    static void supprimer(Categorie tab[], int &n, int id);
    static void modifier(Categorie tab[], int n, int id);
};

#endif
