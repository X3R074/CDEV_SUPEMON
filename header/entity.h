#ifndef ENTITY_H
#define ENTITY_H

typedef struct 
{
    int id;
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
    int Supemon [6];
    int cur_Supemon;
    int Supcoins;
    //pointeur dynamique sur une liste d'objets
} Player;



#endif