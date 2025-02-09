#include <stdlib.h>
#include <stdio.h>
#include "header/feature.h"
#include "header/entity.h"
#include <time.h>

extern Player mainUser;
extern Supemon Supedex;

void initJoueur (){
    
scanf("%s", &mainUser.name);
}

void Save (){
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


void Load (){
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




void Heal (quantityHp, i){
    mainUser.supemonList[i].HP += quantityHp;
    if (mainUser.supemonList[i].HP > mainUser.supemonList[i].HP_max)
    {
        mainUser.supemonList[i].HP = mainUser.supemonList[i].HP_max;
    }

  
}


//sell an object 
void Sell (int i){
    mainUser.Supcoins += mainUser.objectList[i].cost;
    mainUser.objectList[i].number -= 1;
}


void RandomSupémon (){
    srand(time(NULL));
    int random = rand() % 3;
    Supemon Enemy = Supedex[random];
    

}