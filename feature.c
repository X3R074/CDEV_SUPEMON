#include <stdlib.h>
#include <stdio.h>
#include "header/feature.h"
#include "header/entity.h"
#include <time.h>
#include <math.h>

//extern Player mainUser;
//extern Supemon Supedex;


void initJoueur (Player mainUser){
printf("Enter your name : ");  
scanf("%s", &mainUser.name);
}

void Save (Player mainUser){
    FILE *file = NULL;
    file = fopen("save.txt", "wb");
    if (Save != NULL)
    {
        fprintf(file, "%s\n", mainUser.name);
        fprintf(file, "%d\n", mainUser.Supcoins);
        fprintf(file, "%s\n", mainUser.supemonList);
        fprintf(file, "%s\n", mainUser.curSupemon);
        fprintf(file, "%s\n", mainUser.objectList);
        fclose(file);
    }
}


void Load (Player mainUser){
    FILE *file = NULL;
    file = fopen("save.txt", "rb");
    if (file != NULL)
    {
        fscanf(file, "%s\n", mainUser.name);
        fscanf(file, "%d\n", mainUser.Supcoins);
        fscanf(file, "%s\n", mainUser.supemonList);
        fscanf(file, "%s\n", mainUser.curSupemon);
        fscanf(file, "%s\n", mainUser.objectList);
        fclose(file);
    }
}




void Heal (int quantityHp, int i, Player mainUser){
    mainUser.supemonList[i].HP += quantityHp;
    if (mainUser.supemonList[i].HP > mainUser.supemonList[i].HP_max)
    {
        mainUser.supemonList[i].HP = mainUser.supemonList[i].HP_max;
    }

  
}

// shop 
void Buy (int itemSelected, Player mainUser){
    if (mainUser.Supcoins >= mainUser.objectList[itemSelected].cost)
    {
        mainUser.objectList[itemSelected].number += 1;
        mainUser.Supcoins -= mainUser.objectList[itemSelected].cost;
    }
    else
    {
        printf("Errr... I think you can't afford it...\n");
    }
    
}

//sell an object 
void Sell (int itemSelected, Player mainUser){
    if (mainUser.objectList[itemSelected].number > 0)
    {
        mainUser.objectList[itemSelected].number -= 1;
        mainUser.Supcoins += (mainUser.objectList[itemSelected].cost / 2);
    }
    else
    {
        printf("Do you think i'm dumb... \nyou do not have this object\n");
    }

}



void RandomSupémon (Supemon Supedex[]){
    srand(time(NULL));
    int random = rand() % 3;
    Supemon Enemy = Supedex[random];
}

void SupemonCenter (Player mainUser){
    for (int i = 0; i < 6; i++)
    {
        Heal (mainUser.supemonList[i].HP_max,i, mainUser);
    };
}

void LevelUp (Player mainUser){
    Supemon currentSupemon = mainUser.supemonList[mainUser.curSupemon];
    if (currentSupemon.level ==1){ // réparer en focntion des consignes
        if (currentSupemon.experience >= 500)
        {
            currentSupemon.level += 1;
            currentSupemon.experience = 0;
            currentSupemon.HP_max += 5;
            currentSupemon.HP = currentSupemon.HP_max;
            currentSupemon.atk += 1;
            currentSupemon.def += 1;
            currentSupemon.acy += 1;
            currentSupemon.evs += 1;
            currentSupemon.speed += 1;
        };
    } else { int exp = currentSupemon.experience - 500;
        if (exp%1000 == 0)
        {
            currentSupemon.level += 1;
            capacityUp(currentSupemon.atk);
            currentSupemon.HP_max += 5;
            currentSupemon.HP = currentSupemon.HP_max;
            currentSupemon.atk += 1;
            currentSupemon.def += 1;
            currentSupemon.acy += 1;
            currentSupemon.evs += 1;
            currentSupemon.speed += 1;
        };

    }
    }
 

/*
int capacityUp (int value){
    float valuetmp = 0;
    valuetmp = value*1.3;
    if ((valuetmp % 1) != 0)
    {
    srand(time(NULL));
    int random = rand() % 2;
    if (random == 0){
        value = floor(valuetmp);
    } else {
        value = ceil(valuetmp);
    }
    }
        //one chance on two to increase the value by 1
    }
    
    value = valuetmp;
    
    return value;
}
*/
/*
float augmenter_stat(float stat) {
float nouvelle_stat = stat * 1.30;  // Augmentation de 30 %// Gérer l'arrondi aléatoire si ce n'est pas un nombre entierif (nouvelle_stat != (int)nouvelle_stat) {
        srand(time(NULL));  // Initialisation de la graine aléatoire// 50 % pour arrondir vers le bas, 50 % pour arrondir vers le hautif (rand() % 2 == 0) {
            nouvelle_stat = floor(nouvelle_stat);  // Arrondi vers le bas
        } else {
            nouvelle_stat = ceil(nouvelle_stat);   // Arrondi vers le haut
        }
    }
 
    return nouvelle_stat*/