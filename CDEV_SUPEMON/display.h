#ifndef DISPLAY_H
#define DISPLAY_H

#include "entity.h"


int DisplayMainTitle();
int DisplayStarter(Player *mainUser);
int DisplayAdventure();
void displayCombatStats(Player *mainUser, Supemon *Supedex);
int DispalyActionsCombat();
int MoveCombat (Supemon *Supedex);
int changeSupemon (Player *mainUser);
int ItemUse ();
int Capture();
int CaptureSuccess();
int CaptureFail();
int RunAway();
int RunAwaySuccess();
int RunAwayFail();
int Loose();
int ShopInterface();
int buyingInterface();
int sellingInterface( Player *mainUser);
int SupemonCenterInterface(Player *mainUser);
int LeaveGame();


#endif