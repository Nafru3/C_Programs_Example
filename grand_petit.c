/*
Nom du fichier : grand_petit.c
Objectif : Générer un tableau d'entiers aléatoires et trouver les valeurs maximum et minimum
Auteurs : Raphaël BERGER & Nathan FRUME
Date : 16/09/2024
Description :
Ce programme génère un tableau de 100 entiers aléatoires (compris entre 1 et 1000),
et détermine les valeurs maximum et minimum présentes dans ce tableau.
TO DO : rien
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void) {
    const int TAILLE = 100; 
    int tableau[TAILLE];
    
    srand(time(NULL)); 
    
    // Remplissage du tableau avec des entiers aléatoires compris entre 1 et 1000
    for (int i = 0; i < TAILLE; i++) {
        *(tableau + i) = rand() % 1000 + 1;
        printf("%d ", tableau[i]); // Affichage des valeurs générées
    }
    printf("\n");

    int max = tableau[0]; // Initialisation du maximum avec la première valeur
    int min = tableau[0]; // Initialisation du minimum avec la première valeur

    // Parcours du tableau pour déterminer les valeurs max et min
    for (int i = 1; i < TAILLE; i++) {
        if (tableau[i] > max) {
            max = tableau[i];
        }
        if (tableau[i] < min) {
            min = tableau[i];
        }
    }

    // Affichage des résultats
    printf("Le maximum est %d\n", max);
    printf("Le minimum est %d\n", min);
    return 0;
}
