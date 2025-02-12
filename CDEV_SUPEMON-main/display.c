#include <stdio.h>
#include <stdlib.h>
#include "entity.h"
#include "display.h"

// Fonctions pour les menus

/**
 * Affiche le menu principal et retourne le choix de l'utilisateur.
 */
int DisplayMainTitle() {
    int choice = 0;
    do {
        printf("+-----------------------------------+\n");
        printf("| Welcome to Supemon World          |\n");
        printf("|  1 - New Game                     |\n");
        printf("|  2 - Load Game                    |\n");
        printf("|  3 - Leave the Game               |\n");
        printf("+-----------------------------------+\n");
        printf("\n1, 2 or 3: ");
        scanf("%d", &choice);
        if (choice < 1 || choice > 3) {
            printf("Choix invalide, veuillez réessayer.\n");
        }
    } while (choice < 1 || choice > 3);
    return choice;
}

/**
 * Affiche le choix du starter et retourne le choix de l'utilisateur.
 */
int DisplayStarter(Player *mainUser) {
    int choice = 0;
    do {
        printf("Hello %s\n", mainUser->name);
        printf("Welcome to Supemon World!\n\n");
        printf("+--------------------------------+\n");
        printf("| Choose your starter Supémon  : |\n");
        printf("|  1 - Supmander                 |\n");
        printf("|  2 - Supasaur                  |\n");
        printf("|  3 - Supirtle                  |\n");
        printf("+--------------------------------+\n");
        printf("\n1, 2 or 3: ");
        scanf("%d", &choice);
        if (choice < 1 || choice > 3) {
            printf("Choix invalide, veuillez réessayer.\n");
        }
    } while (choice < 1 || choice > 3);
    return choice;
}

/**
 * Affiche le menu d'aventure et retourne le choix de l'utilisateur.
 */
int DisplayAdventure() {
    int choice = 0;
    do {
        printf("+-----------------------------------+\n");
        printf("| Where do you want to go?          |\n");
        printf("|  1 - Into the Wild                |\n");
        printf("|  2 - In the shop                  |\n");
        printf("|  3 - In the Supémon Center        |\n");
        printf("|  4 - Leave the Game               |\n");
        printf("+-----------------------------------+\n");
        printf("\n1, 2, 3 or 4: ");
        scanf("%d", &choice);
        if (choice < 1 || choice > 4) {
            printf("Choix invalide, veuillez réessayer.\n");
        }
    } while (choice < 1 || choice > 4);
    return choice;
}

// Fonctions pour les combats

/**
 * Affiche l'en-tête du combat.
 */
void DisplayCombatHeader() {
    printf("\n+-----------------------------------+\n");
    printf("|            COMBAT MODE           |\n");
    printf("+-----------------------------------+\n");
}

/**
 * Affiche les statistiques du Supémon du joueur.
 */
void DisplayPlayerSupemonStats(Supemon *playerSupemon) {
    printf("\n%s (Your Supémon)\n", playerSupemon->name);
    printf("----------------------------\n");
    printf("HP: %d/%d     Lvl: %d\n", playerSupemon->HP, playerSupemon->HP_max, playerSupemon->level);
    printf("Atk: %d        Def: %d\n", playerSupemon->atk, playerSupemon->def);
    printf("Acc: %d        Eva: %d\n", playerSupemon->acy, playerSupemon->evs);
    printf("----------------------------\n");
}

/**
 * Affiche les statistiques du Supémon ennemi.
 */
void DisplayEnemySupemonStats(Supemon *enemySupemon) {
    printf("\n%s (Enemy Supémon)\n", enemySupemon->name);
    printf("----------------------------\n");
    printf("HP: %d/%d     Lvl: %d\n", enemySupemon->HP, enemySupemon->HP_max, enemySupemon->level);
    printf("Atk: %d        Def: %d\n", enemySupemon->atk, enemySupemon->def);
    printf("Acc: %d        Eva: %d\n", enemySupemon->acy, enemySupemon->evs);
    printf("----------------------------\n");
}

/**
 * Affiche l'état actuel du combat.
 */
void DisplayCombatStatus(Player *mainUser, Supemon *enemy) {
    DisplayCombatHeader();
    DisplayPlayerSupemonStats(&mainUser->supemonList[mainUser->curSupemon]);
    DisplayEnemySupemonStats(enemy);
}

/**
 * Affiche les actions disponibles en combat et retourne le choix de l'utilisateur.
 */
int DispalyActionsCombat() {
    int choice = 0;
    do {
        printf("+-------------------------------+\n");
        printf("| What will you do?             |\n");
        printf("|  1 - Move                     |\n");
        printf("|  2 - Change Supémon           |\n");
        printf("|  3 - Use item                 |\n");
        printf("|  4 - Capture                  |\n");
        printf("|  5 - Run away                 |\n");
        printf("+-------------------------------+\n");
        printf("\n1, 2, 3, 4 or 5: ");
        scanf("%d", &choice);
        if (choice < 1 || choice > 5) {
            printf("Choix invalide, veuillez réessayer.\n");
        }
    } while (choice < 1 || choice > 5);
    return choice;
}

/**
 * Affiche les attaques disponibles et retourne le choix de l'utilisateur.
 */
int MoveCombat(Supemon *playerSupemon) {
    int choice = 0;
    do {
        printf("\n1 - %s\n", playerSupemon->selfCapa[0].name);
        printf("2 - %s\n", playerSupemon->selfCapa[1].name);
        printf("3 - Cancel\n");
        printf("\n1, 2 or 3: ");
        scanf("%d", &choice);
        if (choice < 1 || choice > 3) {
            printf("Choix invalide, veuillez réessayer.\n");
        }
    } while (choice < 1 || choice > 3);
    return choice;
}

// Fonctions pour le magasin

/**
 * Affiche l'interface du magasin et retourne le choix de l'utilisateur.
 */
int ShopInterface() {
    int choice = 0;
    do {
        printf("+-------------------------------+\n");
        printf("| Welcome to the Supéshop       |\n");
        printf("| What will you do?             |\n");
        printf("|  1 - Buy                      |\n");
        printf("|  2 - Sell                     |\n");
        printf("|  3 - Return to the game       |\n");
        printf("+-------------------------------+\n");
        printf("\n1, 2 or 3: ");
        scanf("%d", &choice);
        if (choice < 1 || choice > 3) {
            printf("Choix invalide, veuillez réessayer.\n");
        }
    } while (choice < 1 || choice > 3);
    return choice;
}

// Fonctions pour quitter le jeu

/**
 * Affiche l'interface pour quitter le jeu et retourne le choix de l'utilisateur.
 */
int LeaveGame() {
    int choice = 0;
    do {
        printf("+-------------------------------+\n");
        printf("| What will you do?             |\n");
        printf("|  1 - Leave and save           |\n");
        printf("|  2 - Leave without saving     |\n");
        printf("|  3 - Return to the game       |\n");
        printf("+-------------------------------+\n");
        printf("\n1, 2 or 3: ");
        scanf("%d", &choice);
        if (choice < 1 || choice > 3) {
            printf("Choix invalide, veuillez réessayer.\n");
        }
    } while (choice < 1 || choice > 3);
    return choice;
}