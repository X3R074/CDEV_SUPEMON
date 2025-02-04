#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAILLE_NOM 10

// Déclaration de la structure joueur
typedef struct { //struct joueur initialisée dans entity.h
    char nom[TAILLE_NOM];
} Joueur;

char choix; // Déclaration globale de la variable choix //pas de déclaration globale !! INTERDIT

// Fonction pour créer un nouveau joueur
Joueur créer_Nouveau_Joueur() {
    Joueur joueur;
    printf("Entrez le nom du joueur : ");
    scanf("%s", joueur.nom);  //a fix avec le reste pas opti 
    return joueur;
}

// Fonction pour afficher le menu Supémon
void afficher_menu_supemon(Joueur joueur) {
    printf("Bonjour %s\n", joueur.nom);
    printf("Bienvenue dans le monde de Supémon !\n\n");

    // Encadrement du menu
    printf("+--------------------------------+\n");
    printf("| Choisissez votre Supémon de départ : |\n");
    printf("|  1 - Supmander                 |\n");
    printf("|  2 - Supasaur                  |\n");
    printf("|  3 - Supirtle                  |\n");
    printf("+--------------------------------+\n");

    // Saisie de l'utilisateur
    printf("1, 2 ou 3 : ");
    scanf(" %c", &choix);

    // Vérification du choix
    switch (choix) {
        case '1':
            printf("Vous avez choisi Supmander !\n");
            break;
        case '2':
            printf("Vous avez choisi Supasaur !\n");
            break;
        case '3':
            printf("Vous avez choisi Supirtle !\n");
            break;
        default:
            printf("Choix invalide, veuillez relancer le jeu.\n"); //on va faire une boucle pour recommencer tant que choix invalide
            break;
    }
}

// Fonction pour afficher le menu de destination
void afficher_menu_destination() {
    printf("+-----------------------------------+\n");
    printf("| Où voulez-vous aller ?            |\n");
    printf("|  1 - Dans la nature               |\n");
    printf("|  2 - Dans la boutique             |\n");
    printf("|  3 - Au Centre Supémon            |\n");
    printf("|  4 - Quitter le jeu               |\n");
    printf("+-----------------------------------+\n");

    // Saisie utilisateur
    char choix_utilisateur;
    printf("1, 2, 3 ou 4 : ");
    scanf(" %c", &choix_utilisateur);

    // Traitement du choix
    switch (choix_utilisateur) {
        case '1':
            printf("Vous partez à l'aventure dans la nature !\n"); //pas forccement obligé de confirmer pour chaque 
            break;
        case '2':
            printf("Vous entrez dans la boutique.\n");
            break;
        case '3':
            printf("Vous allez au Centre Supémon.\n");
            break;
        case '4':
            printf("Vous quittez le jeu. À bientôt !\n");
            break;
        default:
            printf("Choix invalide, veuillez recommencer.\n");
            break;
    }
}

// Fonction pour afficher le combat Supémon
void afficher_combat_supemon(Joueur joueur) {
    // Affichage des statistiques du combat // pas d'afficxhage de stats à part les HP et doit être dynamique :/
    printf("Votre tour...\n\n");
    
    printf("%c (ennemi)\n", choix);
    printf("----------------------------\n");
    printf("HP: 10/10     Lvl: 1\n");
    printf("Atk: 1        Def: 1\n");
    printf("Acc: 2        Eva: 1\n");
    printf("----------------------------\n");
    
    printf("%c (%s)\n", choix, joueur.nom);
    printf("HP: 10/10     Lvl: 1\n");
    printf("Atk: 1        Def: 1\n");
    printf("Acc: 2        Eva: 1\n");
    printf("----------------------------\n\n");
    
    // Menu des actions
    printf("+-------------------------------+\n");
    printf("| Que voulez-vous faire ?       |\n");
    printf("|  1 - Attaque                  |\n");
    printf("|  2 - Changer de Supémon       |\n");
    printf("|  3 - Utiliser un objet        |\n");
    printf("|  4 - Capturer                 |\n");
    printf("|  5 - Fuir                     |\n");
    printf("+-------------------------------+\n");
    
    char choix_action;
    printf("1, 2, 3, 4 ou 5 : ");
    scanf(" %c", &choix_action); // %d pour un int le c ne sert a rien 
    
    // Menu des attaques si l'utilisateur choisit 1 //les actions doivent être dynamique en fonction de ce qu'a le pokemon 
    if (choix_action == '1') {
        printf("\n1 - Scratch\n");
        printf("2 - Grawl\n");
        printf("3 - Annuler\n");
        char choix_attaque; // ne peut pas être un char (pas opti)
        printf("1, 2 ou 3 : ");
        scanf(" %c", &choix_attaque);

        switch (choix_attaque) {//duu coup doit être dynamique et ""Supemon" utilise "attaque""
            case '1':
                printf("Vous avez utilisé Scratch !\n");
                break;
            case '2':
                printf("Vous avez utilisé Grawl !\n");
                break;
            case '3':
                printf("Retour au menu principal.\n");
                break;
            default:
                printf("Choix invalide.\n");
                break;
        }
    } else {
        printf("Action choisie : %c\n", choix_action);
    }
}

int main() {
    // Appel de la fonction pour créer un nouveau joueur //a ajouter charger ou sauvegrader avant 
    Joueur joueur = créer_Nouveau_Joueur();

    // Appel de la fonction pour afficher le menu Supemon
    afficher_menu_supemon(joueur);

    // Appel de la fonction pour afficher le menu de destination
    afficher_menu_destination();

    // Appel de la fonction principale
    afficher_combat_supemon(joueur);

    return 0;
}

