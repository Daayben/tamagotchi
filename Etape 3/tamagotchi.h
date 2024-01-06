#define TAMAGOTCHI_H

#include <iostream>
#include <string>
#include <algorithm> // Ajout pour utiliser std::min et std::max

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
    void jouer();
    void manger();
    void dormir();
    void laver();
    void soigner();
    void statut() const;
    bool estEnVie() const;
    void miseAJour();
};