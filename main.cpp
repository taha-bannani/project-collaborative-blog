#include <iostream>
#include <QString>
#include <QCoreApplication>
#include <QDate>
#include <QDebug>

#include "Auteur.h"
#include "UtilisateurDAO.h"
#include "database.h"

void afficherMenu()
{
    std::cout << "\n===== MENU CRUD UTILISATEUR =====\n";
    std::cout << "1. INSERT Auteur\n";
    std::cout << "2. FIND Auteur by ID\n";
    std::cout << "3. LIST All Utilisateurs\n";
    std::cout << "4. UPDATE Auteur\n";
    std::cout << "5. DELETE Utilisateur\n";
    std::cout << "0. EXIT\n";
    std::cout << "Choice: ";
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    Database db;
    if (!db.connect()) {
        qDebug() << "DB connection failed";
        return -1;
    }

    int choice = -1;

    while (choice != 0) {
        afficherMenu();
        std::cin >> choice;
        std::cin.ignore();


        if (choice == 1) {
            int id;
            std::string nom, email, mdp, bio;

            std::cout << "ID: ";
            std::cin >> id;
            std::cin.ignore();

            std::cout << "Nom: ";
            std::getline(std::cin, nom);

            std::cout << "Email: ";
            std::getline(std::cin, email);

            std::cout << "Mot de passe: ";
            std::getline(std::cin, mdp);

            std::cout << "Bio: ";
            std::getline(std::cin, bio);

            Auteur auteur(
                id,
                QString::fromStdString(nom),
                QString::fromStdString(email),
                QString::fromStdString(mdp),
                QDate::currentDate(),
                "",
                QString::fromStdString(bio)
                );

            if (UtilisateurDAO::insert(auteur)) {
                std::cout << "Auteur inserted successfully\n";
            } else {
                std::cout << "Insert failed\n";
            }
        }

        else if (choice == 2) {
            int id;
            std::cout << "ID to search: ";
            std::cin >> id;

            Utilisateur* u = UtilisateurDAO::findById(id);
            if (u) {
                u->afficherInfos();
                delete u;
            } else {
                std::cout << "Utilisateur not found\n";
            }
        }

        //afficher dakchi
        else if (choice == 3) {
            QList<Utilisateur*> list = UtilisateurDAO::listAll();
            for (Utilisateur* u : list) {
                u->afficherInfos();
                delete u;
            }
            if (list.isEmpty()) {
                std::cout << " No utilisateurs found\n";
            }
        }

  //la update
        // else if (choice == 4) {
        //     int id;
        //     std::string nom, email;

        //     std::cout << "ID to update: ";
        //     std::cin >> id;
        //     std::cin.ignore();

        //     std::cout << "New Nom: ";
        //     std::getline(std::cin, nom);

        //     std::cout << "New Email: ";
        //     std::getline(std::cin, email);

        //     Auteur auteur;
        //     auteur.setId_Utilisateur(id);
        //     auteur.setNom(QString::fromStdString(nom));
        //     auteur.setEmail(QString::fromStdString(email));

        //     if (UtilisateurDAO::update(auteur)) {
        //         std::cout << "Update successful\n";
        //     } else {
        //         std::cout << " Update failed\n";
        //     }
        // }


        else if (choice == 5) {
            int id;
            std::cout << "ID to delete: ";
            std::cin >> id;

            if (UtilisateurDAO::remove(id)) {
                std::cout << "Utilisateur deleted\n";
            } else {
                std::cout << "Delete failed\n";
            }
        }
    }

    std::cout << "aki 3awn rbi\n";
    return 0;
}
