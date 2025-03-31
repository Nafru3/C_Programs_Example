/*
Nom du fichier : recherche_dichotomique.c
Objectif : Tri d'un tableau et recherche dichotomique d'un entier
Auteurs : Raphaël BERGER & Nathan FRUME
Date : 16/09/2024
Description :
Ce programme génère un tableau d'entiers aléatoires, le trie par ordre croissant,
puis effectue une recherche dichotomique pour vérifier si un entier donné est présent.
TO DO : rien
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void) {
    const int TAILLE = 8; 
    int tableau[TAILLE];
    
    srand(time(NULL)); 
    
    // Génération du tableau avec des valeurs aléatoires entre -500 et 500
    printf("Tableau non trié : ");
    for (int i = 0; i < TAILLE; i++) {
        *(tableau + i) = rand() % 1001 - 500;
        printf("%d ", tableau[i]);
    }

    // Tri à bulles pour mettre les valeurs du tableau en ordre croissant
    int temp;
    for (int i = TAILLE - 1; i >= 1; i--) {
        for (int j = 0; j <= i - 1; j++) {
            if (tableau[j+1] < tableau[j]) {
                temp = tableau[j+1];
                tableau[j+1] = tableau[j];
                tableau[j] = temp;
            }
        }
    }

    // Affichage du tableau trié
    printf("\nTableau trié : ");
    for (int i = 0; i < TAILLE; i++) {
        printf("%d ", tableau[i]);
    }
    printf("\n");

    // Recherche dichotomique
    int a = 0;
    int b = TAILLE;

    // Saisie de la valeur à rechercher
    int a_trouver;
    scanf("%i", &a_trouver);

    // Boucle de recherche dichotomique
    while (1) {
        printf("Valeur de tableau[(a + b) / 2] : %i\n", tableau[(a + b) / 2]);
        printf("Valeur de a_trouver : %i\n", a_trouver);

        // Réduction de l'intervalle de recherche
        if (tableau[(a + b) / 2] < a_trouver) {
            a = (a + b) / 2;
        } else {
            b = (a + b) / 2;
        }

        printf("Valeur de a : %i\n", a);
        printf("Valeur de b : %i\n", b);

        // Vérification si la valeur est trouvée
        if (tableau[(a + b) / 2] == a_trouver) {
            printf("Résultat : entier présent\n");
            break;
        }

        // Si l'intervalle devient trop petit, la valeur est absente
        if (b <= a + 1) {
            printf("Résultat : entier absent\n");
            break;
        }
    }
    return 0;
}
