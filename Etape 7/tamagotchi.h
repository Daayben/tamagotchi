#ifndef TAMAGOTCHI_H
#define TAMAGOTCHI_H

#include <iostream>
#include <string>
#include <algorithm> // Ajout pour utiliser std::min et std::max

enum class EtatTamagotchi
{
    Heureux,
    Affame,
    Malade,
    Sale,
    Triste,
    Mort
};

class Tamagotchi
{
private:
    std::string nom;
    int faim;
    int sante;
    int bonheur;
    int age;
    bool estVivant;
    EtatTamagotchi etat;

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
    void vieillir();
    void passerLeTemps();
    void evenementsAleatoires();
    void definirEtat();
    void reagirEtatCritique();
    bool verifierFinJeu();
    void evenementsAleatoiresEtat();
    EtatTamagotchi getEtat() const { return etat; }
};

#endif // TAMAGOTCHI_H
