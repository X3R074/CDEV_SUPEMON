#ifndef FEATURE_H
#define FEATURE_H

void initJoueur (Player *mainUser);
void Save (Player *mainUser);
void Load (Player *mainUser);
void Heal (int quantityHp, int i, Player *mainUser);
void Buy (int itemSelected, Player *mainUser);
void Sell (int itemSelected, Player *mainUser);
void RandomSupémon (Supemon Supedex[]);
void SupemonCenter (Player *mainUser);
void LevelUp (Player *mainUser);




#endif