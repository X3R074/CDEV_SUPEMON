#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header/display.h"
#include "header/entity.h"
#include "header/feature.h"



// Déclaration de la structure joueur



// Fonction pour créer un nouveau joueur
Joueur créer_Nouveau_Joueur() {
    Joueur joueur;
    printf("Entrez le nom du joueur : ");
    scanf("%s", joueur.nom);  //a fix avec le reste pas opti 
    return joueur;
}



int main() {


    return 0;
}

