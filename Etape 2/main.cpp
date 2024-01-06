#include "tamagotchi.h"

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