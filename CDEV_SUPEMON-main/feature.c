/*#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include "feature.h"
#include "entity.h"

//extern Player mainUser;
//extern Supemon Supedex;


void initJoueur (Player *mainUser){
printf("Enter your name : ");  
scanf("%s", mainUser->name);
}

void Save (Player *mainUser){
    FILE *file = NULL;
    file = fopen("save.txt", "wb");
    if (Save != NULL)
    {
        fprintf(file, "%s\n", mainUser->name);
        fprintf(file, "%d\n", mainUser->Supcoins);
        fprintf(file, "%s\n", mainUser->supemonList);
        fprintf(file, "%s\n", mainUser->curSupemon);
        fprintf(file, "%s\n", mainUser->objectList);
        fclose(file);
    }
}


void Load (Player *mainUser){
    FILE *file = NULL;
    file = fopen("save.txt", "rb");
    if (file != NULL)
    {
        fscanf(file, "%s\n", mainUser->name);
        fscanf(file, "%d\n", mainUser->Supcoins);
        fscanf(file, "%s\n", mainUser->supemonList);
        fscanf(file, "%s\n", mainUser->curSupemon);
        fscanf(file, "%s\n", mainUser->objectList);
        fclose(file);
    }
}




void Heal (int quantityHp, int i, Player *mainUser){
    mainUser->supemonList[i].HP += quantityHp;
    if (mainUser->supemonList[i].HP > mainUser->supemonList[i].HP_max)
    {
        mainUser->supemonList[i].HP = mainUser->supemonList[i].HP_max;
    }

  
}

// shop 
void Buy (int itemSelected, Player *mainUser){
    if (mainUser->Supcoins >= mainUser->objectList[itemSelected].cost)
    {
        mainUser->objectList[itemSelected].number += 1;
        mainUser->Supcoins -= mainUser->objectList[itemSelected].cost;
    }
    else
    {
        printf("Errr... I think you can't afford it...\n");
    }
    
}

//sell an object 
void Sell (int itemSelected, Player *mainUser){
    if (mainUser->objectList[itemSelected].number > 0)
    {
        mainUser->objectList[itemSelected].number -= 1;
        mainUser->Supcoins += (mainUser->objectList[itemSelected].cost / 2);
    }
    else
    {
        printf("Do you think i'm dumb... \nyou do not have this object\n");
    }

}



void RandomSupemon (Supemon Supedex[]){
    srand(time(NULL));
    int random = rand() % 3;
    Supemon Enemy = Supedex[random];
}

void SupemonCenter (Player *mainUser){
    for (int i = 0; i < 6; i++)
    {
        Heal (mainUser->supemonList[i].HP_max, i, mainUser);
    };
}

void LevelUp (Player *mainUser){
    Supemon currentSupemon = mainUser->supemonList[mainUser->curSupemon];
    int expReq = 500;
    while (currentSupemon.experience >= expReq){    
    if (currentSupemon.level > 1)
    {
        int expReq = 500+(1000*(currentSupemon.level-1));
    }
    
        currentSupemon.level += 1;
        currentSupemon.experience = 0;
        currentSupemon.HP_max = capacityUp(currentSupemon.HP_max);
        currentSupemon.HP = currentSupemon.HP_max;
        currentSupemon.atk = capacityUp(currentSupemon.atk);
        currentSupemon.def = capacityUp(currentSupemon.def);
        currentSupemon.acy = capacityUp(currentSupemon.acy);
        currentSupemon.evs = capacityUp(currentSupemon.evs);
        currentSupemon.speed = capacityUp(currentSupemon.speed); ;
    }
}


int capacityUp (int value){
    float valuetmp = 0;
    valuetmp = value*1.3;
    if (valuetmp == floor(valuetmp))
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
    
    
    value = valuetmp;
    
    return value;
}*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "feature.h"
#include "entity.h"

// Fonctions pour l'initialisation et la sauvegarde

/**
 * Initialise le joueur en demandant son nom.
 */
void initJoueur(Player *mainUser) {
    printf("Enter your name: ");
    scanf("%s", mainUser->name);
  
}

/**
  Sauvegarde les données du joueur dans un fichier.
 */
void Save(Player *mainUser) {
    FILE *file = fopen("save.txt", "wb");
    if (file != NULL) {
        fprintf(file, "%s\n", mainUser->name);
        fprintf(file, "%d\n", mainUser->Supcoins);
        for (int i = 0; i < 6; i++) {
            fprintf(file, "%s %d %d %d %d %d %d %d %d %d %d\n",
                    mainUser->supemonList[i].name,
                    mainUser->supemonList[i].level,
                    mainUser->supemonList[i].experience,
                    mainUser->supemonList[i].HP,
                    mainUser->supemonList[i].HP_max,
                    mainUser->supemonList[i].atk,
                    mainUser->supemonList[i].def,
                    mainUser->supemonList[i].evs,
                    mainUser->supemonList[i].acy,
                    mainUser->supemonList[i].speed);
        }
        fclose(file);
        printf("Game saved successfully!\n");
    } else {
        printf("Error: Could not save the game.\n");
    }
}

/**
 * Charge les données du joueur depuis un fichier.
 */
void Load(Player *mainUser) {
    FILE *file = fopen("save.txt", "rb");
    if (file != NULL) {
        fscanf(file, "%s\n", mainUser->name);
        fscanf(file, "%d\n", &mainUser->Supcoins);
        for (int i = 0; i < 6; i++) {
            fscanf(file, "%s %d %d %d %d %d %d %d %d %d %d\n",
                   mainUser->supemonList[i].name,
                   &mainUser->supemonList[i].level,
                   &mainUser->supemonList[i].experience,
                   &mainUser->supemonList[i].HP,
                   &mainUser->supemonList[i].HP_max,
                   &mainUser->supemonList[i].atk,
                   &mainUser->supemonList[i].def,
                   &mainUser->supemonList[i].evs,
                   &mainUser->supemonList[i].acy,
                   &mainUser->supemonList[i].speed);
        }
        fclose(file);
        printf("Game loaded successfully!\n");
    } else {
        printf("Error: Could not load the game.\n");
    }
}

// Fonctions pour les combats

/**
 * Génère un Supemon ennemi aléatoire.
 */
void RandomSupemon(Supemon *Supedex) {
    srand(time(NULL));
    int random = rand() % 3;
    Supemon Enemy = Supedex[random];
}

/**
 * Calcule les dégâts infligés par une attaque.
 */
int CalculateDamage(Supemon *attacker, Supemon *defender, capacities *move) {
    int damage = (attacker->atk * move->howMuch) / defender->def;
    if (damage != floor(damage)) {
        srand(time(NULL));
        int random = rand() % 2;
        if (random == 0) {
            damage = floor(damage);
        } else {
            damage = ceil(damage);
        }
    }
    return damage;
}

/**
 * Applique les effets d'une capacité (attaque, soin, etc.).
 */
void ApplyMoveEffects(Supemon *target, capacities *move) {
    switch (move->effect) {
        case 2: // Augmenter l'attaque
            target->atk += move->howMuch;
            break;
        case 3: // Augmenter la défense
            target->def += move->howMuch;
            break;
        case 4: // Augmenter l'évasion
            target->evs += move->howMuch;
            break;
        case 5: // Augmenter la précision
            target->acy += move->howMuch;
            break;
        case 6: // Soigner
            target->HP += move->howMuch;
            if (target->HP > target->HP_max) {
                target->HP = target->HP_max;
            }
            break;
        default:
            break;
    }
}

/**
 * Vérifie si une attaque touche.
 */
int CheckIfMoveHits(Supemon *attacker, Supemon *defender, capacities *move) {
    float hitRate = (float)attacker->acy / (attacker->acy + defender->evs);
    float random = (float)rand() / RAND_MAX;
    return random <= hitRate;
}

/**
 * Effectue une attaque.
 */
void PerformAttack(Supemon *attacker, Supemon *defender, capacities *move) {
    if (CheckIfMoveHits(attacker, defender, move)) {
        int damage = CalculateDamage(attacker, defender, move);
        defender->HP -= damage;
        if (defender->HP < 0) {
            defender->HP = 0;
        }
        ApplyMoveEffects(defender, move);
        printf("%s used %s! It dealt %d damage.\n", attacker->name, move->name, damage);
    } else {
        printf("%s used %s, but it missed!\n", attacker->name, move->name);
    }
}

/**
 * Gère le déroulement d'un combat.
 */
void HandleCombat(Player *mainUser, Supemon *enemy) {
    int Capture();
void CaptureSuccess();
void CaptureFail();
int RunAway();
void RunAwaySuccess();
void RunAwayFail();
void changeSupemon(Player *mainUser);
void ItemUse();
int DispalyActionsCombat();
int MoveCombat(Supemon *supemon);

    while (mainUser->supemonList[mainUser->curSupemon].HP > 0 && enemy->HP > 0) {
        // Tour du joueur
        int combatChoice = DispalyActionsCombat();
        switch (combatChoice) {
            case 1: { // Attaquer
                int moveChoice = MoveCombat(&mainUser->supemonList[mainUser->curSupemon]);
                if (moveChoice != 3) { // Si le joueur ne choisit pas "Annuler"
                    PerformAttack(&mainUser->supemonList[mainUser->curSupemon], enemy, &mainUser->supemonList[mainUser->curSupemon].selfCapa[moveChoice - 1]);
                }
                break;
            }
            case 2: // Changer de Supemon
                changeSupemon(mainUser);
                break;
            case 3: // Utiliser un objet
                ItemUse();
                break;
            case 4: { // Capturer
                if (Capture()) {
                    CaptureSuccess();
                    return; // Fin du combat si capture réussie
                } else {
                    CaptureFail();
                }
                break;
            }
            case 5: { // Fuir
                if (RunAway()) {
                    RunAwaySuccess();
                    return; // Fin du combat si fuite réussie
                } else {
                    RunAwayFail();
                }
                break;
            }
            default:
                printf("Invalid choice.\n");
                break;
        }

        // Vérifier si l'ennemi est K.O.
        if (enemy->HP <= 0) {
            printf("You defeated the enemy %s!\n", enemy->name);
            break;
        }

        // Tour de l'ennemi
        int enemyMove = rand() % 2; // L'ennemi choisit une attaque aléatoire
        PerformAttack(enemy, &mainUser->supemonList[mainUser->curSupemon], &enemy->selfCapa[enemyMove]);

        // Vérifier si le joueur est K.O.
        if (mainUser->supemonList[mainUser->curSupemon].HP <= 0) {
            printf("Your %s has been defeated!\n", mainUser->supemonList[mainUser->curSupemon].name);
            break;
        }
    }
}

// Fonctions pour les objets

/**
 * Achète un objet.
 */
void Buy(int itemSelected, Player *mainUser) {
    if (mainUser->Supcoins >= mainUser->objectList[itemSelected].cost) {
        mainUser->objectList[itemSelected].number += 1;
        mainUser->Supcoins -= mainUser->objectList[itemSelected].cost;
        printf("You bought a %s!\n", mainUser->objectList[itemSelected].name);
    } else {
        printf("Errr... I think you can't afford it...\n");
    }
}

/**
 * Vend un objet.
 */
void Sell(int itemSelected, Player *mainUser) {
    if (mainUser->objectList[itemSelected].number > 0) {
        mainUser->objectList[itemSelected].number -= 1;
        mainUser->Supcoins += (mainUser->objectList[itemSelected].cost / 2);
        printf("You sold a %s!\n", mainUser->objectList[itemSelected].name);
    } else {
        printf("Do you think i'm dumb... \nyou do not have this object.\n");
    }
}

/**
 * Soigne un Supemon.
 */
void Heal(int quantityHp, int i, Player *mainUser) {
    mainUser->supemonList[i].HP += quantityHp;
    if (mainUser->supemonList[i].HP > mainUser->supemonList[i].HP_max) {
        mainUser->supemonList[i].HP = mainUser->supemonList[i].HP_max;
    }
    printf("%s has been healed!\n", mainUser->supemonList[i].name);
}

// Fonctions pour le centre Supemon

/**
 * Soigne tous les Supemons du joueur.
 */
void SupemonCenter(Player *mainUser) {
    for (int i = 0; i < 6; i++) {
        Heal(mainUser->supemonList[i].HP_max, i, mainUser);
    }
}

// Fonctions pour les niveaux et l'expérience

/**
 * Fait monter de niveau un Supemon.
 */
void LevelUp(Player *mainUser) {
    Supemon *currentSupemon = &mainUser->supemonList[mainUser->curSupemon];
    int expReq = 500 + (1000 * (currentSupemon->level - 1));
    if (currentSupemon->experience >= expReq) {
        currentSupemon->level += 1;
        currentSupemon->experience = 0;
        currentSupemon->HP_max = capacityUp(currentSupemon->HP_max);
        currentSupemon->HP = currentSupemon->HP_max;
        currentSupemon->atk = capacityUp(currentSupemon->atk);
        currentSupemon->def = capacityUp(currentSupemon->def);
        currentSupemon->acy = capacityUp(currentSupemon->acy);
        currentSupemon->evs = capacityUp(currentSupemon->evs);
        currentSupemon->speed = capacityUp(currentSupemon->speed);
        printf("%s has leveled up to level %d!\n", currentSupemon->name, currentSupemon->level);
    }
}

/**
 * Augmente une statistique de 30 % avec une chance d'arrondir.
 */
int capacityUp(int value) {
    float valuetmp = value * 1.3;
    if (valuetmp != floor(valuetmp)) {
        srand(time(NULL));
        int random = rand() % 2;
        if (random == 0) {
            value = floor(valuetmp);
        } else {
            value = ceil(valuetmp);
        }
    } else {
        value = valuetmp;
    }
    return value;
}
