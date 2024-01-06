#include "tamagotchi.h"

Tamagotchi::Tamagotchi(std::string nomInit)
    : nom(nomInit), faim(50), sante(100), bonheur(50), estVivant(true) {}

std::string Tamagotchi::getNom() const
{
    return nom;
}

void Tamagotchi::manger()
{
    if (!estVivant)
        return;

    faim = std::max(0, faim - 10);
    bonheur = std::min(100, bonheur + 5);
    sante = std::min(100, sante + 5);
}

void Tamagotchi::jouer()
{
    if (!estVivant)
        return;

    bonheur = std::min(100, bonheur + 10);
    std::cout << nom << " joue et est heureux." << std::endl;
}

void Tamagotchi::soigner()
{
    if (!estVivant)
        return;

    sante = std::min(100, sante + 10);
    std::cout << nom << " se sent mieux !" << std::endl;
}

void Tamagotchi::dormir()
{
    if (!estVivant)
        return;

    sante = std::min(100, sante + 10);
    std::cout << nom << " dort et récupère." << std::endl;
}

void Tamagotchi::laver()
{
    if (!estVivant)
        return;

    bonheur = std::min(100, bonheur + 5);
    std::cout << nom << " est propre et content." << std::endl;
}

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

bool Tamagotchi::estEnVie() const
{
    return estVivant;
}

void Tamagotchi::miseAJour()
{
    if (!estVivant)
        return;

    faim = std::max(0, faim - 5);
    bonheur = std::max(0, bonheur - 5);
    sante = std::max(0, sante - 5);

    if (faim <= 0 || sante <= 0 || bonheur <= 0)
    {
        estVivant = false;
        std::cout << nom << " est mort." << std::endl;
    }
}
