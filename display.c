#include <stdio.h>
#include <stdlib.h>
#include "header/entity.h"
#include "header/display.h"


//extern Player mainUser;
//extern Supemon Supedex;

int DisplayMainTitle (){
    int choice =0;
    do
    {
    
    printf("+-----------------------------------+\n");
    printf("| Welcome to Supemon World          |\n");
    printf("|  1 - New Game                     |\n");
    printf("|  2 - Load Game                    |\n");
    printf("|  3 - Leave the Game               |\n");
    printf("+-----------------------------------+\n");
    printf("\n1, 2 or 3: ");
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
    default:
        choice = 0;
        printf("Please enter a valid number\n");
    }
    } while (choice == 0);
}




int DisplayStarter(Player mainUser) {
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



// COMBATS
void displayCombatStats(Player mainUser, Supemon Supedex) {

    printf("Your turn...\n\n");
    
    printf("%s (enemy)\n", Supedex.name);//pas sur de ce que je dois mettre ici
    printf("----------------------------\n");
    printf("HP: %d/%d     Lvl: %d\n");
    printf("Atk: %d        Def: %d\n");
    printf("Acc: %d        Eva: %d\n");
    printf("----------------------------\n");

    Supemon currentSupemon = mainUser.supemonList[mainUser.curSupemon];
    
    printf("%s (%s)\n", currentSupemon.name, mainUser.name);
    printf("HP: %d/%d     Lvl: %d\n", currentSupemon.HP, currentSupemon.HP_max, currentSupemon.level);
    printf("Atk: %d        Def: %d\n", currentSupemon.atk, currentSupemon.def);
    printf("Acc: %d       Eva: %d\n", currentSupemon.acy, currentSupemon.evs);
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
    printf("\n1, 2, 3, 4 or 5 : ");
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


int MoveCombat (Supemon Supedex) {
    int choice =0;
    do {
    // Menu des attaques si l'utilisateur choisit 1 //les actions doivent être dynamique en fonction de ce qu'a le pokemon 
        printf("\n1 - %s\n", Supedex.selfCapa[0].name);
        printf("2 - %s\n", Supedex.selfCapa[1].name);
        printf("3 - Cancel\n");
        printf("\n1, 2 or 3 : ");
        scanf(" %c", &choice);

        switch (choice) {//duu coup doit être dynamique et ""Supemon" utilise "attaque""
            case 1:
                printf("Your Supémon use %s !\n", Supedex.selfCapa[0].name);
                break;
            case 2:
                printf("Your Supémon use %s !\n", Supedex.selfCapa[1].name);
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

// change supemon 
int changeSupemon (Player mainUser) {
    int choice =0;

    do
    {
    printf("+-----------------------------------+\n");
    printf("| Your current Supémon is %s        |\n", mainUser.supemonList[mainUser.curSupemon].name);
    printf("| Which Supémon do you want to use? |\n");
    printf("|  1 - %s                           |\n", mainUser.supemonList[0].name);
    printf("|  2 - %s                           |\n", mainUser.supemonList[1].name);
    printf("|  3 - %s                           |\n", mainUser.supemonList[2].name);
    printf("|  4 - %s                           |\n", mainUser.supemonList[3].name);
    printf("|  5 - %s                           |\n", mainUser.supemonList[4].name);
    printf("|  6 - %s                           |\n", mainUser.supemonList[5].name);
    printf("|  0 - Cancel                       |\n");
    printf("+-----------------------------------+\n");
    printf("\n1, 2, 3, 4, 5, 6 or 0: ");
    scanf(" %d", &choice);

    switch (choice)
   {
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
    case 6:
        return 6;
        break;
    case 0:
        return 0;
        break;
    default:
        choice = 0;
        printf("Please enter a valid number\n");
    }
    } while (choice == 0);
   

}

//use item
int ItemUse () {
    int choice =0;

    
    printf("+-----------------------------------+\n");
    printf("| Which object do you want to use?  |\n");
    printf("|  1 - Potion                       |\n");
    printf("|  2 - Super Potion                 |\n");
    printf("|  0 - Cancel                       |\n");
    printf("+-----------------------------------+\n");
    printf("\n1 or 0: ");
    scanf(" %d", &choice);
    if (choice == 1) {
        return 1;
    }
    else {
        return 0;
    }
    
}

//capture 
int Capture () {
    int choice =0;

    
    printf("+--------------------------------------+\n");
    printf("|                                      |\n");
    printf("| You are trying to capture the Supémon|\n");
    printf("|                                      |\n");
    printf("+--------------------------------------+\n");
    printf("\n1 or 0: ");
    scanf(" %d", &choice);
    if (choice == 1) {
        return 1;
    }
    else {
        return 0;
    }
    
}



// capture success
int CaptureSuccess () {
    
    printf("+--------------------------------------+\n");
    printf("|                                      |\n");
    printf("| This Supémon is your new bestfriend  |\n");
    printf("|                                      |\n");
    printf("+--------------------------------------+\n");
}
//caputre fail 
int CaptureFail () {
    
    printf("+-----------------------------------------------+\n");
    printf("|                                               |\n");
    printf("| Oh no, the supémon doesn't want to be yours   |\n");
    printf("|                                               |\n");
    printf("+-----------------------------------------------+\n");
}




// run away

int RunAway () {
    
    printf("+--------------------------------------+\n");
    printf("|                                      |\n");
    printf("| You are trying to run away           |\n");
    printf("|                                      |\n");
    printf("+--------------------------------------+\n");
}


//run away success
int RunAwaySuccess () {
    
    printf("+--------------------------------------+\n");
    printf("|                                      |\n");
    printf("| Ooof we are safe                     |\n");
    printf("|                                      |\n");
    printf("+--------------------------------------+\n");
}

//run away fail
int RunAwayFail () {
    
    printf("+--------------------------------------------------+\n");
    printf("|                                                  |\n");
    printf("| Your enemy doens't want you to flee              |\n");
    printf("|                                                  |\n");
    printf("+--------------------------------------------------+\n");
}

// SHOP
int ShopInterface () {
    int choice =0;
    do
    {
    
    printf("+-------------------------------+\n");
    printf("| Welcome to the Supéshop       |\n");
    printf("| What will you do?             |\n");
    printf("|  1 - Buy                      |\n");
    printf("|  2 - Sell                     |\n");
    printf("|  3 - Return to the game       |\n");
    printf("+-------------------------------+\n");
    printf("\n1, 2 or 3: ");
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
    default:
        choice = 0;
        printf("Please enter a valid number\n");
    }
    } while (choice == 0);
}

int buyingInterface() {
    int choice =0;
    
    printf("+--------------------------------+\n");
    printf("| What will you buy?             |\n");
    printf("|  1 - Buy a Potion              |\n");
    printf("|  2 - Buy a Super Potion        |\n");
    printf("|  3 - Buy a Rare Candy          |\n");
    printf("|  0 or else to quit             |\n");
    printf("+--------------------------------+\n");
    printf("\n1, 2 or 3: ");
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
    default:
        return 0;

    }
}

int sellingInterface(Player mainUser) {
    int choice =0;
    
    printf("+--------------------------------+\n");
    printf("| Your inventory :               |\n");
    printf("| 1.Potion               %d items|\n", mainUser.objectList[0].number);
    printf("| 2.Super Potion         %d items|\n", mainUser.objectList[1].number);
    printf("| 3.Rare Candy           %d items|\n", mainUser.objectList[2].number);
    printf("|  What do you want to sell      |\n");
    printf("|  1, 2 or 3 (0 or else to quit) |\n");
    printf("+--------------------------------+\n");
    printf("\n1, 2 or 3: ");
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
    default:
        return 0;

    }
}

// SUPEMON CENTER

int SupemonCenterInterface(Player mainUser) {
    int choice =0;
    
    printf("+-------------------------------------+\n");
    printf("| Welcome to the Supémon Center       |\n");
    printf("|  1 - %s                    HP: %d/%d|\n", mainUser.supemonList[0].name, mainUser.supemonList[0].HP, mainUser.supemonList[0].HP_max);
    printf("|  2 - %s                    HP: %d/%d|\n", mainUser.supemonList[1].name, mainUser.supemonList[1].HP, mainUser.supemonList[1].HP_max);
    printf("|  3 - %s                    HP: %d/%d|\n", mainUser.supemonList[2].name, mainUser.supemonList[2].HP, mainUser.supemonList[2].HP_max);
    printf("|  4 - %s                    HP: %d/%d|\n", mainUser.supemonList[3].name, mainUser.supemonList[3].HP, mainUser.supemonList[3].HP_max);
    printf("|  5 - %s                    HP: %d/%d|\n", mainUser.supemonList[4].name, mainUser.supemonList[4].HP, mainUser.supemonList[4].HP_max);
    printf("|  6 - %s                    HP: %d/%d|\n", mainUser.supemonList[5].name, mainUser.supemonList[5].HP, mainUser.supemonList[5].HP_max);
    printf("|  Do you want to heal your Supémon ? |\n");
    printf("+-------------------------------------+\n");
    printf("\n yes(1) or no(0): ");
    scanf(" %d", &choice);  
    if (choice == 1) {
        return 1;
    }
    else {
        return 0;
    }
}


// LEAVE THE GAME


int LeaveGame() {

    int choice=0;

    do
    {
    
    printf("+-------------------------------+\n");
    printf("| What will you do?             |\n");
    printf("|  1 - Leave and save           |\n");
    printf("|  2 - Leave without saving     |\n");
    printf("|  3 - Rurn to theet game       |\n");
    printf("+-------------------------------+\n");
    printf("\n1, 2, or 3: ");
    scanf(" %d", &choice);  
    switch (choice){
    case 1:
        printf("Game will be saved and exited.\n");
        return 1;
        break;
    case 2:
        printf("Game will be exited without saving.\n");
        return 2;
        break;
    case 3:
        return 3;
        break;
    default:
        choice = 0;
        printf("Please enter a valid number\n");
    }
    } while (choice == 0);
}