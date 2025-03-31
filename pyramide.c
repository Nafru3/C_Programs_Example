/*
Nom du fichier : pyramide.c
Objectif : Génération d'une pyramide de nombres.
Auteurs : Raphaël BERGER & Nathan FRUME
Date de création : 16/09/2024
Description : Ce programme génère une pyramide de nombres centrée.
TO DO : rien
*/ 
#include <stdio.h>

int main(void){
    int n = 5; // Hauteur de la pyramide
    int nombre_espace_totale = n-1; 

    // Boucle externe qui gère chaque ligne de la pyramide
    for (int i = 0; i < n; i++) {
        int nombre_a_afficher = 1; 
        int nombre_espace_ligne = nombre_espace_totale; 

        // Boucle interne qui gère l'affichage des espaces et des nombres sur chaque ligne
        for (int j = 0; j < 2 * n; j++) {
            if (nombre_espace_ligne != 0) {
                // Affiche les espaces jusqu'à ce que `nombre_espace_ligne` atteigne 0
                printf(" ");
                nombre_espace_ligne--;
            } else {
                // Affiche les nombres, d'abord croissants, puis décroissants
                printf("%i", nombre_a_afficher);
                if (j < n - 1) {
                    nombre_a_afficher++; 
                } else {
                    nombre_a_afficher--; 
                    if (nombre_a_afficher == 0) {
                        break; // Arrête l'affichage des nombres lorsque le dernier nombre est affiché
                    }
                }
            }
        }

        nombre_espace_totale--;
        printf("\n"); // Passe à la ligne suivante
    }

    return 0;
}
