#ifndef ENTITY_H
#define ENTITY_H

typedef struct  
{
    char name[10];
    int level;
    int experience;
    int HP;
    int HP_max;
    int atk;
    int atk_base;
    int def;
    int def_base;
    int evs;
    int evs_base;
    int acy;
    int acy_base;
    int speed;
    //list of move
} Supemon;


typedef struct 
{
    char name [10];
    Supemon supemonList[6];
    int curSupemon;
    int Supcoins;
    Objects objectList [3];
} Player;


typedef struct {
    char name [10];
    int cost;
    int power;
    int effect; //1 vie 2 experience ?
    int number;
} Objects;



#endif