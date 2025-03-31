/*
Nom du fichier : chercher2.c
Objectif : Recherche d'une phrase dans un tableau de chaînes de caractères
Auteurs : Raphaël BERGER & Nathan FRUME
Date : 16/09/2024
Description :
Ce programme permet à l'utilisateur de saisir une phrase et cherche cette phrase
dans un tableau de phrases prédéfinies. 
TO DO : rien
*/

#include <stdio.h>

int main() {
    // Déclaration d'un tableau de chaînes de caractères
    char *tableau[10] = { "Bonjour, comment ça va ?",
                        "Le temps est magnifique aujourd'hui.",
                        "C'est une belle journée.",
                        "La programmation en C est amusante.",
                        "Les tableaux en C sont puissants.",
                        "Les pointeurs en C peuvent être déroutants.",
                        "Il fait beau dehors.",
                        "La recherche dans un tableau est intéressante.",
                        "Les structures de données sont importantes.",
                        "Programmer en C, c'est génial."};

    int const taille_max = 100; 
    char phrase_a_chercher[taille_max]; 
    printf("Quelle est la phrase à chercher ? ");
    fgets(phrase_a_chercher, taille_max, stdin); // On utilise fgets car l'utilisateur va renseigner des espaces

    // Suppression du saut de ligne à la fin de la saisie
    for (int i = 0; i < taille_max; i++) {
        if (phrase_a_chercher[i] == '\n') {
            phrase_a_chercher[i] = '\0'; // Remplacement du saut de ligne par un caractère nul
            break;
        }
    }

    // Recherche de la phrase dans le tableau
    for (int i = 0; i < 10; i++) {
        int j = 0;
        while (tableau[i][j] != '\0' && phrase_a_chercher[j] != '\0') {
            if (tableau[i][j] != phrase_a_chercher[j]) {
                break; // Sortie de la boucle si les caractères ne correspondent pas
            }
            j++;
        }
        // Vérification si la phrase complète a été trouvée
        if (tableau[i][j] == '\0' && phrase_a_chercher[j] == '\0') {
            printf("Phrase trouvée !\n");
            return 0; // Sortie du programme si la phrase est trouvée
        }
    }
    printf("Phrase non trouvée\n"); // Message si la phrase n'est pas trouvée
    return 0;
}
