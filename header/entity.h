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
    char name [15];
    int cost;
    int power;
    int effect; //1 vie 2 experience ?
    int number;
} Objects;


typedef struct {
    char name [10];
    int target; //1 me 2 enemy
    int howMuch;
    int effect; //1 damage, 2 attaque, 3 defense, 4 evasion, 5 accuracy, 6 HP; 
} capacities;



#endif