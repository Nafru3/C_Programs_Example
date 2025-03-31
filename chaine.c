#include <stdio.h>

int main(int argc, char** argv) {
    int taille = 0;
    char element = 'a';
    
    while (element != '\0') {
        taille++;
        element = argv[1][taille];

        
    }
    char string_de_copie[taille+1];
    printf("La taille est %d\n",taille);
    for (int i = 0; i < taille; i++) {
        string_de_copie[i] = argv[1][i];
    }
    string_de_copie[taille] = '\0';
    printf("La copie est %s\n",string_de_copie);

    if (argc == 3) {
        int taille2 = 0;
        element = 'a';
        while (element != '\0') {
            taille2++;
            element = argv[2][taille2];
        }

        char long_string[taille + taille2 + 2];
        for (int i = 0; i < taille + 1; i++) {
            long_string[i] = argv[1][i];
        }
        long_string[taille] = ' ';
        for (int i = 0; i < taille2; i++) {
            long_string[i + taille+1] = argv[2][i];
        }
        long_string[taille + taille2 + 1] = '\0';
        printf("La concaténation est : %s\n",long_string);



    }
    

    
}