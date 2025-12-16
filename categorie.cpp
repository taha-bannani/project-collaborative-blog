#include "categorie.h"
#include <iostream>
using namespace std;

// Constructors
Categorie::Categorie() {
    idCategorie = 0;
}

Categorie::Categorie(int id, string n, string d, string t) {
    idCategorie = id;
    nom = n;
    description = d;
    tags = t;
}

// Getters
int Categorie::getIdCategorie() { return idCategorie; }
string Categorie::getNom() { return nom; }
string Categorie::getDescription() { return description; }
string Categorie::getTags() { return tags; }

// Setters
void Categorie::setIdCategorie(int id) { idCategorie = id; }
void Categorie::setNom(string n) { nom = n; }
void Categorie::setDescription(string d) { description = d; }
void Categorie::setTags(string t) { tags = t; }

// Other methods
void Categorie::saisir() {
    cout << "ID Categorie: ";
    cin >> idCategorie;
    cin.ignore();

    cout << "Nom: ";
    getline(cin, nom);

    cout << "Description: ";
    getline(cin, description);

    cout << "Tags: ";
    getline(cin, tags);
}

void Categorie::afficher() {
    cout << "\n----- CATEGORIE -----\n";
    cout << "ID: " << idCategorie << endl;
    cout << "Nom: " << nom << endl;
    cout << "Description: " << description << endl;
    cout << "Tags: " << tags << endl;
}

void Categorie::afficherResume() {
    cout << idCategorie << " | " << nom << endl;
}

bool Categorie::estValide() {
    return idCategorie > 0 && !nom.empty();
}

void Categorie::vider() {
    idCategorie = 0;
    nom = "";
    description = "";
    tags = "";
}

bool Categorie::comparer(Categorie c) {
    return idCategorie == c.idCategorie;
}

string Categorie::toString() {
    return nom + " (" + tags + ")";
}

// Static methods
int Categorie::rechercher(Categorie tab[], int n, int id) {
    for(int i = 0; i < n; i++) {
        if(tab[i].idCategorie == id)
            return i;
    }
    return -1;
}

void Categorie::ajouter(Categorie tab[], int &n) {
    Categorie c;
    c.saisir();

    if(!c.estValide()) {
        cout << "Categorie invalide.\n";
        return;
    }

    tab[n] = c;
    n++;
    cout << "Categorie ajoutée avec succès.\n";
}

void Categorie::supprimer(Categorie tab[], int &n, int id) {
    int pos = rechercher(tab, n, id);
    if(pos == -1) {
        cout << "Categorie introuvable.\n";
        return;
    }

    for(int i = pos; i < n - 1; i++)
        tab[i] = tab[i + 1];

    n--;
    cout << "Categorie supprimée avec succès.\n";
}

void Categorie::modifier(Categorie tab[], int n, int id) {
    int pos = rechercher(tab, n, id);
    if(pos == -1) {
        cout << "Categorie introuvable.\n";
        return;
    }

    cout << "Nouvelles informations :\n";
    tab[pos].saisir();

    if(!tab[pos].estValide()) {
        cout << "Données invalides.\n";
        return;
    }

    cout << "Categorie modifiée avec succès.\n";
}
