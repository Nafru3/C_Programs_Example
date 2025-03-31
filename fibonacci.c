#include <stdio.h>
#include <stdlib.h>

int main(int argv, char** argc) {
    int nbr_utilisateur = atoi(argc[1]);
    int Un2 = 0;
    int Un1 = 1;
    int Un = 1;
    while (Un < nbr_utilisateur)
    {
        Un1 = Un;
        Un = Un1+Un2;
        Un2 = Un1;
        printf("%d\n",Un);
    }
    
}