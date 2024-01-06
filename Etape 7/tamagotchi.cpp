#include "tamagotchi.h"
#include <random>

Tamagotchi::Tamagotchi(std::string nomInit)
    : nom(nomInit), faim(50), sante(100), bonheur(50), age(0), estVivant(true), etat(EtatTamagotchi::Heureux) {}

std::string Tamagotchi::getNom() const
{
    return nom;
}

void Tamagotchi::manger()
{
    if (!estVivant)
        return;

    faim = std::min(100, faim + 10);
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

void Tamagotchi::vieillir()
{
    age++; // Simplement incrémenter l'âge
}

void Tamagotchi::passerLeTemps()
{
    // Diminuez la faim et le bonheur à chaque appel de cette méthode
    faim = std::max(0, faim - 10);
    bonheur = std::max(0, bonheur - 10);

    // Assurez-vous que le Tamagotchi est toujours en vie après le passage du temps
    if (faim == 0 || bonheur == 0)
    {
        estVivant = false;
    }
}

void Tamagotchi::evenementsAleatoires()
{
    static std::default_random_engine engine(static_cast<unsigned int>(time(nullptr)));
    static std::uniform_int_distribution<int> distribution(1, 100);
    int chance = distribution(engine);

    // Disons que vous avez 10% de chance d'un événement positif et 10% de chance d'un événement négatif
    if (chance <= 10)
    {
        // Événement positif: Augmente le bonheur ou la santé
        bonheur = std::min(100, bonheur + 20);
        std::cout << "Votre Tamagotchi a trouvé un jouet !" << std::endl;
    }
    else if (chance >= 90)
    {
        // Événement négatif: Diminue la santé
        sante = std::max(0, sante - 20);
        std::cout << "Votre Tamagotchi est malade !" << std::endl;
    }
}
void Tamagotchi::definirEtat()
{
    if (faim > 70)
    {
        etat = EtatTamagotchi::Affame;
    }
    else if (sante < 30)
    {
        etat = EtatTamagotchi::Malade;
    }
    else if (bonheur < 20)
    {
        etat = EtatTamagotchi::Triste;
    }
    else
    {
        etat = EtatTamagotchi::Heureux;
    }

    if (!estVivant)
    {
        etat = EtatTamagotchi::Mort;
    }
}

void Tamagotchi::reagirEtatCritique()
{
    if (etat == EtatTamagotchi::Affame || etat == EtatTamagotchi::Malade)
    {
        sante -= 10;
        std::cout << "Votre Tamagotchi souffre !" << std::endl;
    }
}

bool Tamagotchi::verifierFinJeu()
{
    return etat == EtatTamagotchi::Mort;
}

void Tamagotchi::evenementsAleatoiresEtat()
{
    // Créer un moteur de génération de nombres aléatoires
    static std::default_random_engine engine(static_cast<unsigned int>(time(nullptr)));
    static std::uniform_int_distribution<int> distribution(1, 100);
    int chance = distribution(engine);

    // Événements basés sur l'état actuel du Tamagotchi
    switch (etat)
    {
    case EtatTamagotchi::Heureux:
        if (chance <= 10)
        {
            bonheur += 10; // Augmenter le bonheur si le Tamagotchi est déjà heureux
            std::cout << nom << " est très heureux aujourd'hui !" << std::endl;
        }
        break;
    case EtatTamagotchi::Affame:
        if (chance <= 10)
        {
            faim -= 10; // Trouver de la nourriture par chance
            std::cout << nom << " a trouvé de la nourriture !" << std::endl;
        }
        break;
    case EtatTamagotchi::Malade:
        if (chance <= 10)
        {
            sante += 10; // Amélioration de la santé
            std::cout << nom << " se sent un peu mieux !" << std::endl;
        }
        break;
    // Vous pouvez ajouter plus de cas pour d'autres états si nécessaire
    default:
        // Aucun événement particulier pour les autres états
        break;
    }
}
