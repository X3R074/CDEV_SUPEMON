#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "display.h"
#include "entity.h"
#include "feature.h"



// Déclaration de la structure joueur



// Fonction pour créer un nouveau joueur
/*Joueur créer_Nouveau_Joueur() {
    Joueur joueur;
    printf("Entrez le nom du joueur : ");
    scanf("%s", joueur.nom);  //a fix avec le reste pas opti 
    return joueur;
}

*/

int main() {
    Player mainUser;
    Supemon Supedex[3];
    int rep = DisplayMainTitle();
    if (rep == 1 ) {
        initJoueur(&mainUser);
        int Supchoice = DisplayStarter(&mainUser);
        if (Supchoice == 1) {
            mainUser.supemonList[0] = Supedex[0]; //gérer comment on ajoute un supemon
        }
        else if (Supchoice == 2) {
            mainUser.supemonList[0] = Supedex[1];
        }
        else if (Supchoice == 3)
        {
            mainUser.supemonList[0] = Supedex[2];
        }
        
    }
    else if (rep == 2) {
        Load(&mainUser);
    }
    else {
        return 0;
        free(mainUser.supemonList);
    }

    int MainMenu=DisplayAdventure();
    if (MainMenu == 1) {
        //nature
    }
    else if (MainMenu == 2) {
        //shop
    }
    else if (MainMenu == 3) {
        //supemon center
    }
    else if (MainMenu == 4) {
        //leave the game
    }




    free(mainUser.supemonList);
    return 0;
}



//cd "/home/gwen/Documents/SUPINFOB1/CDEV/projet/CDEV_SUPEMON" ; if ($?) { gcc main.c display/display.c structures/structures.c features/features.c -o main } ; if ($?) { .\main }