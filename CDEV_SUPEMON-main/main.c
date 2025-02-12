#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "display.h"
#include "entity.h"
#include "feature.h"



int main() {
    Player mainUser;
    Supemon enemy;
    int choix;
    Supemon *Supedex [3];

    // Initialisation du générateur de nombres aléatoires
    srand(time(NULL));

    // Affichage du menu principal
    int rep = DisplayMainTitle();
    if (rep == 1) { // Nouvelle partie
        initJoueur(&mainUser);
        int Supchoice = DisplayStarter(&mainUser);
        switch (Supchoice) {
            case 1:
                mainUser.supemonList[0] = *Supedex[0]; // Supmander
                break;
            case 2:
                mainUser.supemonList[0] = *Supedex[1]; // Supasaur
                break;
            case 3:
                mainUser.supemonList[0] = *Supedex[2]; // Supirtle
                break;
            default:
                printf("Choix invalide.\n");
                return 1; // Quitter le programme en cas d'erreur
        }
        mainUser.curSupemon = 0; // Le premier Supémon est choisi par défaut
    } else if (rep == 2) { // Charger une partie
        Load(&mainUser);
        printf("Partie chargée avec succès !\n");
    } else { // Quitter le jeu
        printf("Fin du programme.\n");
        return 0;
    }

    // Menu d'aventure
    while (1) {
        int MainMenu = DisplayAdventure();
        switch (MainMenu) {
            case 1: { // Combat
                RandomSupemon(*Supedex); // Génère un Supémon ennemi aléatoire
                enemy = *Supedex[rand() % 3]; // Sélectionne un Supémon ennemi
                enemy.HP = enemy.HP_max; // Réinitialise les HP de l'ennemi

                // Gestion du combat
                while (1) {
                    DisplayCombatStatus(&mainUser, &enemy); // Affiche les stats en combat
                    int combatChoice = DispalyActionsCombat();

                    switch (combatChoice) {
                        case 1: { // Attaquer
                            int moveChoice = MoveCombat(&mainUser.supemonList[mainUser.curSupemon]);
                            if (moveChoice != 3) { // Si le joueur ne choisit pas "Annuler"
                                PerformAttack(&mainUser.supemonList[mainUser.curSupemon], &enemy, 
                                             &mainUser.supemonList[mainUser.curSupemon].selfCapa[moveChoice - 1]);
                            }
                            break;
                        }
                        case 2: // Changer de Supémon
                            changeSupemon(&mainUser);
                            break;
                        case 3: // Utiliser un objet
                            ItemUse();
                            break;
                        case 4: { // Capturer
                            if (Capture()) {
                                CaptureSuccess();
                                break; // Fin du combat si capture réussie
                            } else {
                                CaptureFail();
                            }
                            break;
                        }
                        case 5: { // Fuir
                            if (RunAway()) {
                                RunAwaySuccess();
                                break; // Fin du combat si fuite réussie
                            } else {
                                RunAwayFail();
                            }
                            break;
                        }
                        default:
                            printf("Choix invalide.\n");
                            break;
                    }

                    // Vérifier si l'ennemi est K.O.
                    if (enemy.HP <= 0) {
                        printf("Vous avez vaincu l'ennemi %s !\n", enemy.name);
                        break;
                    }

                    // Tour de l'ennemi
                    int enemyMove = rand() % 2; // L'ennemi choisit une attaque aléatoire
                    PerformAttack(&enemy, &mainUser.supemonList[mainUser.curSupemon], &enemy.selfCapa[enemyMove]);

                    // Vérifier si le joueur est K.O.
                    if (mainUser.supemonList[mainUser.curSupemon].HP <= 0) {
                        printf("Votre %s a été vaincu !\n", mainUser.supemonList[mainUser.curSupemon].name);
                        break;
                    }
                }
                break;
            }

            case 2: { // Magasin
                int shopChoice = ShopInterface();
                if (shopChoice == 1) { // Acheter
                    int itemChoice = buyingInterface();
                    if (itemChoice != 0) {
                        Buy(itemChoice, &mainUser);
                    }
                } else if (shopChoice == 2) { // Vendre
                    int itemChoice = sellingInterface(&mainUser);
                    if (itemChoice != 0) {
                        Sell(itemChoice, &mainUser);
                    }
                }
                break;
            }

            case 3: { // Centre Supémon
                int centerChoice = SupemonCenterInterface(&mainUser);
                if (centerChoice == 1) {
                    SupemonCenter(&mainUser);
                    printf("Vos Supémons ont été soignés !\n");
                }
                break;
            }

            case 4: { // Quitter le jeu
                int leaveChoice = LeaveGame();
                if (leaveChoice == 1) { // Sauvegarder et quitter
                    Save(&mainUser);
                    printf("Partie sauvegardée et quittée.\n");
                    return 0;
                } else if (leaveChoice == 2) { // Quitter sans sauvegarder
                    printf("Partie quittée sans sauvegarder.\n");
                    return 0;
                }
                break;
            }

            default:
                printf("Choix invalide, réessayez.\n");
                break;
        }
    }

    return 0;
}