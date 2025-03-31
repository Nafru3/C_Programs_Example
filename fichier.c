#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

void lire_fichier(char* nom_de_fichier) {
    char content[1000];
    int fichier = open(nom_de_fichier,O_RDONLY);
    int size = read(fichier, content, 1000);
    for (int i = 0; i < size; i ++) {
        printf("%c", content[i]);
    }
    close(fichier);
}

void ecrire_dans_fichier(char* nom_de_fichier, char* message) {
    int fichier = open (nom_de_fichier, O_CREAT|O_WRONLY, S_IRUSR|S_IWUSR);
    int size = write(fichier, message, strlen(message));
    close(fichier);
}