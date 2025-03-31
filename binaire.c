#include <stdio.h>

int main(void){
    int nombre = 101;
    //On trouve la taille de la liste : 
    int taille = 0;
    int n = nombre;
    while (n >0)
    {
        n /= 2;
        taille += 1;
    }
    printf("%i\n",taille);
    
    char nombre_binaire[taille+1];

    n = nombre;
    for (int i = 0; i<taille; i++)
    {
        if (n%2) {
            nombre_binaire[taille-i-1] = '1';
        } else {
            nombre_binaire[taille-i-1] = '0';
        }
        nombre_binaire[taille] = '\0';
        n /= 2;

    }
    printf("Nombre Binaire : %s\n",nombre_binaire);
}