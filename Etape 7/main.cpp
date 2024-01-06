#include "tamagotchi.h"
#include <limits>
#include <iostream>

std::string etatToStr(EtatTamagotchi etat)
{
    switch (etat)
    {
    case EtatTamagotchi::Heureux:
        return "Heureux";
    case EtatTamagotchi::Affame:
        return "Affame";
    case EtatTamagotchi::Malade:
        return "Malade";
    case EtatTamagotchi::Sale:
        return "Sale";
    case EtatTamagotchi::Triste:
        return "Triste";
    case EtatTamagotchi::Mort:
        return "Mort";
    default:
        return "Inconnu";
    }
}
void jouerTamagotchi()
{
    int jour = 0; // Compteur de jours
    std::string nomTamagotchi;
    std::cout << "Entrez le nom de votre Tamagotchi : ";
    std::getline(std::cin, nomTamagotchi);

    Tamagotchi tamagotchi(nomTamagotchi);
    int choix;
    bool continuerJeu = true; // Variable de contrôle pour continuer le jeu

    while (tamagotchi.estEnVie() && continuerJeu)
    {
        jour++; // Incrémente le jour
        std::cout << "Jour " << jour << std::endl;

        for (int actions = 0; actions < 3; actions++)
        {
            std::cout << " " << std::endl;
            std::cout << "Actions restantes ce jour : " << 3 - actions << std::endl;
            std::cout << "----- Menu de " << tamagotchi.getNom() << " -----\n";
            std::cout << "1. Nourrir " << tamagotchi.getNom() << "\n";
            std::cout << "2. Jouer avec " << tamagotchi.getNom() << "\n";
            std::cout << "3. Soigner " << tamagotchi.getNom() << "\n";
            std::cout << "4. Faire dormir " << tamagotchi.getNom() << "\n";
            std::cout << "5. Laver " << tamagotchi.getNom() << "\n";
            std::cout << "6. Quitter\n";

            bool choixValide = false;
            do
            {
                {
                    std::cout << "Choisissez une action : ";
                    if (!(std::cin >> choix))
                    {
                        std::cin.clear();                                                   // Réinitialise l'état d'erreur de std::cin
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore le reste de la ligne
                        std::cout << "Entrée invalide. Veuillez entrer un numero entre 1 et 6." << std::endl;
                    }
                    else if (choix < 1 || choix > 6)
                    {
                        std::cout << "Choix invalide. Veuillez entrer un numero entre 1 et 6." << std::endl;
                        // Ici, nous devons nettoyer le flux d'entrée pour les prochaines itérations
                        std::cin.clear();                                                   // Réinitialise l'état d'erreur de std::cin
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore le reste de la ligne
                    }
                    else
                    {
                        choixValide = true;
                    }
                    tamagotchi.definirEtat();
                    tamagotchi.reagirEtatCritique();
                    if (tamagotchi.verifierFinJeu())
                    {
                        std::cout << "Votre Tamagotchi est mort de " << etatToStr(tamagotchi.getEtat()) << "." << std::endl;
                        break;
                    }
                    tamagotchi.evenementsAleatoiresEtat();
                }
            }

            while (!choixValide);

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
            } // Mise à jour et effacement de l'écran après la pause
            tamagotchi.miseAJour();
        }

        // Gestion du passage du temps quotidien, vieillissement, faim et bonheur
        tamagotchi.vieillir();
        tamagotchi.passerLeTemps();

        tamagotchi.definirEtat();
        tamagotchi.reagirEtatCritique();
        if (tamagotchi.verifierFinJeu())
        {
            std::cout << tamagotchi.getNom() << " est mort." << std::endl;
            break;
        }
        tamagotchi.evenementsAleatoiresEtat();

        if (!tamagotchi.estEnVie())
        {
            std::cout << tamagotchi.getNom() << " a vécu une belle vie." << std::endl;
        }
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
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } while (recommencer == 'y' || recommencer == 'Y');

    std::cout << "Merci d'avoir joué. À bientôt !" << std::endl;
    return 0;
}