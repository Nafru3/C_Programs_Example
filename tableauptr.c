#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL));
    int taille = 11;
    int tableau_int[taille];
    float tableau_float[taille];
    printf("Avant Modification\n");
    for(int i=0;i<taille;i++){
        *(tableau_int + i) = rand() % 101;
        printf("%i, ",*(tableau_int + i));
    }
    printf("\n");
    for(int i=0;i<taille;i++){
        *(tableau_float + i) = (float)(rand() % 101) + ((float)rand() / RAND_MAX);
        printf("%.2f, ",*(tableau_float + i));
    }
    printf("\n");
    printf("Après Modification\n");
    for(int i=0;i<taille;i++){
        if (i%2 == 0) {
            *(tableau_int + i) *= 3;
        }
        printf("%i, ",*(tableau_int + i));
    }
    printf("\n");
    for(int i=0;i<taille;i++){
        if (i%2 == 0) {
            *(tableau_float + i) *= 3;
        }
        printf("%.2f, ",*(tableau_float + i));
    }
    printf("\n");
    

}