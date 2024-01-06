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

class GestionnaireSauvegarde
{
public:
    static void sauvegarderTamagotchi(Tamagotchi &tamagotchi);
    static Tamagotchi chargerTamagotchi();
};

class Tamagotchi
{
private:
    std::string nom;
    std::string cheminSauvegarde;
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
    void setFaim(int nouvelleFaim) { faim = nouvelleFaim; }
    void setSante(int nouvelleSante) { sante = nouvelleSante; }
    void setBonheur(int nouveauBonheur) { bonheur = nouveauBonheur; }
    void setAge(int nouvelAge) { age = nouvelAge; }
    void setCheminSauvegarde(const std::string &chemin) { cheminSauvegarde = chemin; }
    int getFaim() const { return faim; }
    int getBonheur() const { return bonheur; }
    int getSante() const { return sante; }
    int getAge() const { return age; }
};

#endif // TAMAGOTCHI_H
