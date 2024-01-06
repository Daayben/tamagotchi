#include "tamagotchi.h"

void jouerTamagotchi()
{
    std::string nomTamagotchi;
    std::cout << "Entrez le nom de votre Tamagotchi : ";
    std::getline(std::cin, nomTamagotchi);

    Tamagotchi tamagotchi(nomTamagotchi);
    int choix;
    bool continuerJeu = true; // Variable de contrôle pour continuer le jeu

    while (tamagotchi.estEnVie() && continuerJeu) // Modification de la condition de la boucle
    {

        std::cout << "----- Menu de " << tamagotchi.getNom() << " -----\n";
        std::cout << "1. Nourrir " << tamagotchi.getNom() << "\n";
        std::cout << "2. Jouer avec " << tamagotchi.getNom() << "\n";
        std::cout << "3. Soigner " << tamagotchi.getNom() << "\n";
        std::cout << "4. Faire dormir " << tamagotchi.getNom() << "\n";
        std::cout << "5. Laver " << tamagotchi.getNom() << "\n";
        std::cout << "6. Quitter\n";
        std::cout << "Choisissez une action : ";
        std::cin >> choix;
        std::cin.ignore(); // Pour gérer le flux d'entrée après la saisie d'un nombre

        switch (choix)
        {
        case 1:
            tamagotchi.manger();
            tamagotchi.statut();
            break;
        case 2:
            tamagotchi.jouer();
            tamagotchi.statut();
            break;
        case 3:
            tamagotchi.soigner();
            tamagotchi.statut();
            break;
        case 4:
            tamagotchi.dormir();
            tamagotchi.statut();
            break;
        case 5:
            tamagotchi.laver();
            tamagotchi.statut();
            break;
        case 6:
            continuerJeu = false; // Mettre continuerJeu à false pour quitter le jeu
            break;

        default:
            std::cout << "Choix invalide. Veuillez recommencer.\n";
        }
        // Mise à jour et effacement de l'écran après la pause
        tamagotchi.miseAJour();
    }

    if (!tamagotchi.estEnVie())
    {
        std::cout << tamagotchi.getNom() << " a vécu une belle vie." << std::endl;
    }
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