#ifndef DISPLAY_H
#define DISPLAY_H

#include "entity.h"

// Fonctions pour les menus
int DisplayMainTitle();
int DisplayStarter(Player *mainUser);
int DisplayAdventure();

// Fonctions pour les combats
void DisplayCombatHeader();
void DisplayPlayerSupemonStats(Supemon *playerSupemon);
void DisplayEnemySupemonStats(Supemon *enemySupemon);
void DisplayCombatStatus(Player *mainUser, Supemon *enemy);
int DispalyActionsCombat();
int MoveCombat(Supemon *playerSupemon);
int changeSupemon(Player *mainUser);
int ItemUse();
int Capture();
int CaptureSuccess();
int CaptureFail();
int RunAway();
int RunAwaySuccess();
int RunAwayFail();
int Loose();

// Fonctions pour le magasin
int ShopInterface();
int buyingInterface();
int sellingInterface(Player *mainUser);

// Fonctions pour le centre Supémon
int SupemonCenterInterface(Player *mainUser);

// Fonctions pour quitter le jeu
int LeaveGame();

#endif