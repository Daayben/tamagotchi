#ifndef TAMAGOTCHI_H
#define TAMAGOTCHI_H

#include <iostream>
#include <string>

class Tamagotchi
{
private:
    std::string nom;
    int faim;
    int sante;
    int bonheur;
    bool estVivant;

public:
    Tamagotchi(std::string nom);
    std::string getNom() const;
    void nourrir();
    void jouer();
    void soigner();
    void statut() const;
    bool estEnVie() const;
    void miseAJour();
};

#endif