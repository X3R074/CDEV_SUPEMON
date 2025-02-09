#include <stdio.h>
#include <stdlib.h>
#include "header/entity.h"
extern Player mainUser;
extern Supemon Supedex;

int DisplayStarter() {
    int choice=0;
    printf("Hello %s\n", mainUser.name);
    printf("Welcome in Supemon World !\n\n");
do
{
    

    // Encadrement du menu
    printf("+--------------------------------+\n");
    printf("| Choose your starter Supémon  : |\n");
    printf("|  1 - Supmander                 |\n");
    printf("|  2 - Supasaur                  |\n");
    printf("|  3 - Supirtle                  |\n");
    printf("+--------------------------------+\n");

    // Saisie de l'utilisateur
    printf("1, 2 or 3 : ");
    scanf(" %d", &choice);

    // Vérification du choix
    switch (choice) {
        case 1:
            printf("You choosed the great Supmander !\n");
            return 1;
            break;
        case 2:
            printf("You choosed the shy Supasaur !\n");
            return 2;
            break;
        case 3:
            printf("You choosed the cute Supirtle !\n");
            return 3;
            break;
        default:
            choice ==0;
            printf("invalid choice, Please retype 1, 2 or 3.\n"); //on va faire une boucle pour recommencer tant que choix invalide
    }}
    while (choice ==0);
}


int DisplayAdventure() {
    int choice =0;
    do
    {
    
    printf("+-----------------------------------+\n");
    printf("|Where do you want to go?           |\n");
    printf("|  1 - Into the Wild                |\n");
    printf("|  2 - In the shop                  |\n");
    printf("|  3 - In the Supémon Center        |\n");
    printf("|  4 - Leave the Game               |\n");
    printf("+-----------------------------------+\n");

   
    printf("1, 2, 3 or 4 : ");
    scanf(" %d", &choice);
    
     
    

    // Traitement du choix
    switch (choice) {
        case 1:
            return 1;//nature
            break;
        case 2:
            return 2;//shop
            break;
        case 3:
            return 3; //supemon center
            break;
        case 4:
            return 4; //leave the game 
            break;
        default:
            printf("Choix invalide, veuillez recommencer.\n");
            choice=0;
            break;
    }
    } while (choice ==0);
}


// Fonction pour afficher le combat Supémon
void displayCombatStats() {
    // Affichage des statistiques du combat // pas d'afficxhage de stats à part les HP et doit être dynamique :/
    printf("Your turn...\n\n");
    
    printf("%s (enemy)\n", );
    printf("----------------------------\n");
    printf("HP: %d/%d     Lvl: %d\n");
    printf("Atk: %d        Def: %d\n");
    printf("Acc: %d        Eva: %d\n");
    printf("----------------------------\n");
    
    printf("%s (%s)\n", , mainUser.name);
    printf("HP: %d/%d     Lvl: %d\n");
    printf("Atk: %d        Def: %d\n");
    printf("Acc: %d       Eva: %d\n");
    printf("----------------------------\n\n");}



int DispalyActionsCombat() {

    int choice=0;

    do
    {
    
    printf("+-------------------------------+\n");
    printf("| What will you do?             |\n");
    printf("|  1 - Move                     |\n");
    printf("|  2 - Change Supémon           |\n");
    printf("|  3 - Use item                 |\n");
    printf("|  4 - Capture                  |\n");
    printf("|  5 - Run away                 |\n");
    printf("+-------------------------------+\n");
    printf("\n1, 2, 3, 4 ou 5 : ");
    scanf(" %d", &choice);  

    switch (choice){
    case 1:
        return 1;
        break;
    case 2:
        return 2;
        break;
    case 3:
        return 3;
        break;
    case 4:
        return 4;
        break;
    case 5:
        return 5;
        break;
    default:
        choice = 0;
        printf("Please enter a valid number\n");
    }
    } while (choice == 0);
}


int MoveCombat (){
    int choice =0;
    do {
    // Menu des attaques si l'utilisateur choisit 1 //les actions doivent être dynamique en fonction de ce qu'a le pokemon 
        printf("\n1 - %s\n");
        printf("2 - %s\n");
        printf("3 - Annuler\n");
        printf("\n1, 2 ou 3 : ");
        scanf(" %c", &choice);

        switch (choice) {//duu coup doit être dynamique et ""Supemon" utilise "attaque""
            case 1:
                printf("Your Supémon use %s !\n");
                break;
            case 2:
                printf("Your Supémon use %s !\n");
                break;
            case 3:
                return 3;
                break;
            default:
                choice ==0;
                printf("What did you choose ?\n");
        }
    
    } while (choice ==0);
}