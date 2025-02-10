#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header/display.h"
#include "header/entity.h"
#include "header/feature.h"

extern Player mainUser;
extern Supemon Supedex;

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
    int rep = DisplayMainTitle();
    if (rep == 1 ) {
        initJoueur();
        int Supchoice = DisplayStarter();
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
        Load();
    }
    else {
        return 0;
    }

    DisplayAdventure();





    return 0;
}

