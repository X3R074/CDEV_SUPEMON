# CDEV_SUPEMON


 
1 - Introduction

SUPINFO World CLI Gaming asks you to develop a CLI (console) version of Pokémon in C, called Supémon.

It has to be realized by groups of maximum 2 students in 3 weeks, and is mostly based on what you have seen during this course but some parts may need a little research to complete. One and only one group of 3 is allowed if and only if the class has an odd number of students and all other groups have 2 members.

You are obviously not allowed to copy or adapt an existing code, or share information with other groups.

Failure to comply with the above instructions or the delivery rules will result in a grade of 0.
If you do not know, first shame on you, and then check out this link.


2 - Implementations

2.1 - Program launch

You must allow the player to enter a name and offer him/her a Supémon.

Otherwise, the player must be able to load a backup file.



2.2 - Out-of-combat actions

    Into the wild: launch a fight against a random Supémon.
    Shop: allows the player to buy or sell items.
        In buying mode, display all items list with their description and price. Allows to buy a specific item.
        In selling mode, display all player's items with their selling price. Allows to sell a specific item.
    Supémon Center: displays all player's Supémons and asks to heal them (without any charge).
    Leave the game: with or without saving progress.



2.3 - Player

The player has:

    A name.
    A list of Supémons.
    A selected Supémon (fighting).
    Supcoins to buy items.
    A list of items.

 
2.4 - Supémons

The Supémons have:

    A name.
    Level (starting from 1).
    Experience (starting from 0).
    HP and Max HP (current [not reset between fights] and maximum health points).
    Attack and Base Attack (current and base [start of the fight] Attack): the higher the Attack, the more damage Supémon does per offensive move.
    Defense and Base Defense (current and base [start of the fight] Defense): the higher the Defense, the less damage Supémon takes per offensive move.
    Evasion and Base Evasion (current and base [start of the fight] Evasion): the higher the Evasion, the more Supémon can dodge an offensive move.
    Accuracy and Base Accuracy (current and base [start of the fight] Accuracy): the higher the Accuracy, the less Supémon can miss an offensive move.
    Speed: used to determine the playing order.
    A list of moves.

You will implement (at least) these 3 Supémons (here are displayed level 1 statistics):

    Supmander:
        HP: 10
        Attack: 1
        Defense: 1
        Evasion: 1
        Accuracy: 2
        Speed: 1
        Moves:
            Scratch (deals 3 damage)
            Grawl (gives 1 Attack)
    Supasaur:
        HP: 9
        Attack: 1
        Defense: 1
        Evasion: 3
        Accuracy: 2
        Speed: 2
        Moves:
            Pound (deals 2 damage)
            Foliage (gives 1 Evasion)
    Supirtle:
        HP: 11
        Attack: 1
        Defense: 2
        Evasion: 2
        Accuracy: 1
        Speed: 2
        Moves:
            Pound (deals 2 damage)
            Shell (gives 1 Defense)

Moves can deal damage to another Supémon or increase/decrease Supémon statistics (self or enemy).
Offensive moves damage are modified by both launcher Attack and target Defense: Launcher_Attack x Damage / Target_Defense. If the result is not an integer: 50% chance to round up, 50% to round down.
Offensive moves can be dodged, the success rate is: Launcher_Accuracy / (Launcher_Accuracy + Target_Evasion) + 0.1. ex: 2 / (2 + 2) + 0.1 = 60% success rate.

2.5 - Battle

When you go into the wild, you launch a turn-by-turn fight against a random Supémon. The player selected Supémon will be summoned, the enemy's level must be the same as that of this Supémon (statistics are calculated proportionally).

The Supémon with the highest Speed with start, if both have the same amount it is random.

During a turn, the player can:

    Move: will display Supémon moves list to select one. 1 move per turn.
    Change Supémon: will display player's Supémons list and will allow to change. Skips the player's turn.
    Use an item: will allow the player to select an owned item and will apply its effect on the targeted Supémon. 1 item per turn, maximum 4 per battle.
    Run away: will try to end the fight but can fail, using Player_Speed / (Player_Speed + Enemy_Speed) success rate.
    Capture: will try to capture the enemy Supémon. If the action succeeds, it will add a clone of the enemy Supémon in the player's Supémons list and will win the fight. It uses the (Enemy_MaxHP - Enemy_HP) / Enemy_MaxHP - 0.5 formula. ex: (10 - 3) / 10 - 0.5 = 20% success rate.

During the enemy's turn, it randomly selects an attack from the Supémon attack pool.

The battle ends when a Supémon has 0 or less HP. If the player loses, no reward is given. If the player wins, he/she is rewarded with 100 to 500 Supcoins usable in the shop, and the current player's Supémon wins between 100 to 500 times the enemy level in experience.



2.6 - Items

In the shop, the player can buy items. You will implement (at least) these 3 items:

    Potion: +5 HP (100 Supcoins).
    Super potion: +10 HP (300 Supcoins).
    Rare candy: adds a level to the Supémon (700 Supcoins).

The selling price is the purchase price divided by 2.


2.7 - Experience and level

Supémons can gain levels (but not evolve). Each time a Supémon gains a level, it must increase all its statistics by 30%. For each statistic, if the value is not an integer: 50% chance to round up, 50% to round down.

To go from level 1 to level 2, you need 500 experience points. Each level requires an additional 1,000 points.


2.8 - Save

You will implement a backup file containing the player's data: name, list of Supémons and their data/statistics, items, Supcoins.


3 - Delivery

Your rendering will be a ZIP containing your source codes, a user documentation and a technical documentation explaining your choices and/or implementation choices/details.

You will show your work and give a live demonstration during the oral sessions. Your PowerPoint presentation will illustrate the technical aspects.

 
4 - Grading scale

    Display and graphic rendering: 15 points
    User input management: 5 points
    Supémons (statistics, experience, level): 10 points
    Battle (attack, dodge, capture, win/lose, items, change Supémon): 25 points
    Supémon Center: 5 points
    Shop (buy and sell items): 15 points
    Player (Supcoins, Supémons list, name): 10 points
    At least 3 Supémons and 3 items: 5 points
    Backup file: 10 points

This scale takes into consideration the quality of your code, your documentation and your ability to produce a stable and resilient game.