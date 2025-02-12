#ifndef FEATURE_H
#define FEATURE_H

#include "entity.h"

// Fonctions pour l'initialisation et la sauvegarde
void initJoueur(Player *mainUser);
void Save(Player *mainUser);
void Load(Player *mainUser);

// Fonctions pour les combats
void RandomSupemon(Supemon *Supedex);
int CalculateDamage(Supemon *attacker, Supemon *defender, capacities *move);
void ApplyMoveEffects(Supemon *target, capacities *move);
int CheckIfMoveHits(Supemon *attacker, Supemon *defender, capacities *move);
void PerformAttack(Supemon *attacker, Supemon *defender, capacities *move);
void HandleCombat(Player *mainUser, Supemon *enemy);

// Fonctions pour les objets
void Buy(int itemSelected, Player *mainUser);
void Sell(int itemSelected, Player *mainUser);
void Heal(int quantityHp, int i, Player *mainUser);

// Fonctions pour le centre Supemon
void SupemonCenter(Player *mainUser);

// Fonctions pour les niveaux et l'expérience
void LevelUp(Player *mainUser);
int capacityUp(int value);

#endif