/*
Nom du fichier : tri.c
Objectif : Tri d'un tableau d'entiers aléatoires
Auteurs : Raphaël BERGER & Nathan FRUME
Date : 16/09/2024
Description :
Ce programme génère un tableau d'entiers aléatoires, puis le trie par ordre croissant
en utilisant l'algorithme de tri à bulles.
TO DO : rien
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void) {
    const int TAILLE = 100; 
    int tableau[TAILLE]; 
    srand(time(NULL)); 

    // Génération et affichage du tableau avec des valeurs aléatoires entre -500 et 500
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
                // Échange des éléments si nécessaire
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
    return 0;
}
