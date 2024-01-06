#include "tamagotchi.h"

// Constructeur
Tamagotchi::Tamagotchi(std::string nomInit)
    : nom(nomInit), faim(50), sante(100), bonheur(50), estVivant(true) {}

// Retourne le nom du Tamagotchi
std::string Tamagotchi::getNom() const
{
    return nom;
}

// Nourrir le Tamagotchi
void Tamagotchi::nourrir()
{
    if (!estVivant)
        return;

    faim += 10;
    bonheur += 5;
    // Vérifiez que faim et bonheur ne dépassent pas leurs valeurs maximales
    faim = (faim > 100) ? 100 : faim;
    bonheur = (bonheur > 100) ? 100 : bonheur;

    std::cout << nom << " est nourri." << std::endl;
}

// Faire jouer le Tamagotchi
void Tamagotchi::jouer()
{
    if (!estVivant)
        return;

    bonheur += 10;
    // Vérifiez que bonheur ne dépasse pas sa valeur maximale
    bonheur = (bonheur > 100) ? 100 : bonheur;

    std::cout << nom << " joue et est heureux." << std::endl;
}

// Soigner le Tamagotchi
void Tamagotchi::soigner()
{
    if (!estVivant)
        return;

    sante += 10;
    // Vérifiez que sante ne dépasse pas sa valeur maximale
    sante = (sante > 100) ? 100 : sante;

    std::cout << nom << " se sent mieux !." << std::endl;
}

// Afficher le statut du Tamagotchi
void Tamagotchi::statut() const
{
    if (!estVivant)
    {
        std::cout << nom << " est mort." << std::endl;
        return;
    }

    std::cout << "Statut de " << nom << " :" << std::endl;
    std::cout << "Faim: " << faim << std::endl;
    std::cout << "Sante: " << sante << std::endl;
    std::cout << "Bonheur: " << bonheur << std::endl;
}

// Vérifier si le Tamagotchi est en vie
bool Tamagotchi::estEnVie() const
{
    return estVivant;
}

// Mise à jour de l'état du Tamagotchi
void Tamagotchi::miseAJour()
{
    if (!estVivant)
        return;

    faim -= 5;
    bonheur -= 5;
    sante -= 5;

    // Vérifiez si le Tamagotchi est mort
    if (faim <= 0 || sante <= 0 || bonheur <= 0)
    {
        estVivant = false;
        std::cout << nom << " est mort." << std::endl;
    }
}
