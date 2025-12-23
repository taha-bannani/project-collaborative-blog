#ifndef ADMINISTRATEURDAO_H
#define ADMINISTRATEURDAO_H

class AdministrateurDAO
{
public:
    static bool supprimerUtilisateur(int id);
    static bool desactiverUtilisateur(int id);
};

#endif // ADMINISTRATEURDAO_H
