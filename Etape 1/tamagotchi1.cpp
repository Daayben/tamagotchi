#include <iostream>
#include <string>
#include <thread>
#include <chrono>

class Tamagotchi
{
private:
    std::string nom;
    int faim;
    int sante;
    int bonheur;
    bool estVivant;

public:
    Tamagotchi(std::string nom) : nom(nom), faim(50), sante(100), bonheur(50), estVivant(true) {}

    std::string getNom() const
    {
        return nom;
    }

    void nourrir()
    {
        if (!estVivant)
            return;

        if (faim < 90)
        {
            faim += 10;
            bonheur += 5;
            std::cout << nom << " a ete nourri." << std::endl;
        }
        else
        {
            std::cout << nom << " n'a pas faim." << std::endl;
        }
    }

    void jouer()
    {
        if (!estVivant)
            return;

        if (bonheur < 90)
        {
            bonheur += 10;
            std::cout << nom << " joue et est heureux." << std::endl;
        }
        else
        {
            std::cout << nom << " est deja tres heureux." << std::endl;
        }
    }

    void soigner()
    {
        if (!estVivant)
            return;

        if (sante < 90)
        {
            sante += 10;
            std::cout << nom << " a ete soigne." << std::endl;
        }
        else
        {
            std::cout << nom << " est en pleine forme." << std::endl;
        }
    }

    void statut()
    {
        if (!estVivant)
        {
            std::cout << nom << " est mort." << std::endl;
            return;
        }

        std::cout << "Statut de " << nom << ":" << std::endl;
        std::cout << "Faim: " << faim << std::endl;
        std::cout << "Sante: " << sante << std::endl;
        std::cout << "Bonheur: " << bonheur << std::endl;
    }

    bool estEnVie() const
    {
        return estVivant;
    }

    void miseAJour()
    {
        if (!estVivant)
            return;

        faim -= 5;
        bonheur -= 5;
        sante -= 5;
        if (faim <= 0 || sante <= 0 || bonheur <= 0)
        {
            estVivant = false;
            std::cout << nom << " est mort." << std::endl;
            return;
        }
    }
};

void jouerTamagotchi()
{
    std::string nomTamagotchi;
    std::cout << "Entrez le nom de votre Tamagotchi : ";
    std::getline(std::cin, nomTamagotchi);

    Tamagotchi tamagotchi(nomTamagotchi);
    int choix;

    while (tamagotchi.estEnVie())
    {
        std::cout << "----- Menu de " << tamagotchi.getNom() << " -----\n";
        std::cout << "1. Nourrir " << tamagotchi.getNom() << "\n";
        std::cout << "2. Jouer avec " << tamagotchi.getNom() << "\n";
        std::cout << "3. Soigner " << tamagotchi.getNom() << "\n";
        std::cout << "4. Voir le statut de " << tamagotchi.getNom() << "\n";
        std::cout << "5. Quitter\n";
        std::cout << "Choisissez une action : ";
        std::cin >> choix;
        std::cin.ignore(); // Pour gérer le flux d'entrée après la saisie d'un nombre

        switch (choix)
        {
        case 1:
            tamagotchi.nourrir();
            break;
        case 2:
            tamagotchi.jouer();
            break;
        case 3:
            tamagotchi.soigner();
            break;
        case 4:
            tamagotchi.statut();
            std::cout << "Appuyez sur une touche pour continuer..." << std::endl;
            std::cin.get(); // Attend une saisie de l'utilisateur
            break;
        case 5:
            std::cout << "Au revoir!\n";
            return;
        default:
            std::cout << "Choix invalide. Veuillez recommencer.\n";
        }

        // Mise à jour et effacement de l'écran après la pause
        tamagotchi.miseAJour();

#ifdef _WIN32
        system("cls");
#else
        system("clear");
#endif
    }

    std::cout << tamagotchi.getNom() << " a vecu une belle vie. ";
}

int main()
{
    char recommencer;
    do
    {
        jouerTamagotchi();
        std::cout << "Voulez-vous recommencer ? (y/n) ";
        std::cin >> recommencer;
        std::cin.ignore();
    } while (recommencer == 'y' || recommencer == 'Y');

    std::cout << "Merci d'avoir joué. À bientôt !" << std::endl;
    return 0;
}
