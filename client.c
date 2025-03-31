/*
Nom du fichier : client.c
Objectif : Implémentation du client avec la gestion de l'envoit du message, calcul et du calcul de la moyenne
Auteurs : John Samuel & Raphaël BERGER & Nathan FRUME
Date : 14/10/2024
*/

#include <dirent.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include "client.h"

char* write_and_read(int socketfd, char* message) { // Fonction qui est appelée plusieurs fois à chaque fois que l'on écrit au serveur
  char data[1024]; 
  char* data_to_return = malloc(1024); // On ne pas return directement data donc on passe par data_to_return
  int write_status = write(socketfd, message, strlen(message));
  if (write_status < 0)
  {
    perror("Erreur d'écriture");
    free(data_to_return);
    return "Error";
  }

  // Réinitialisation de l'ensemble des données
  memset(data, 0, sizeof(data));


  // Lit les données de la socket
  int read_status = read(socketfd, data, sizeof(data));
  if (read_status < 0)
  {
    perror("Erreur de lecture");
    free(data_to_return);
    return "Error";
  }
  
  strcpy(data_to_return, data);
  return data_to_return; // Ne pas oublier de faire un free après
}


char* envoie_operateur_numeros(int socketfd, char op, int num1, int num2) {
  char calcul[1024];
  sprintf(calcul, "calcul : %c %d %d", op, num1, num2); 

  char* data = write_and_read(socketfd, calcul); // 
  // Affiche le message reçu du client
  if (strcmp(data, "Error") == 0) {
    return "Error";
  }
  
  return data; // Succès
}


/**
 * Fonction pour envoyer et recevoir un message depuis un client connecté à la socket.
 *
 * @param socketfd Le descripteur de la socket utilisée pour la communication.
 * @return 0 en cas de succès, -1 en cas d'erreur.
 */
int envoie_recois_message(int socketfd)
{
  char data[1024];

  // Réinitialisation de l'ensemble des données
  memset(data, 0, sizeof(data));

  // Demande à l'utilisateur d'entrer un message
  char message[1024];
  printf("Votre message (max 1000 caractères): ");
  fgets(message, sizeof(message), stdin);

  if (strncmp(message,"calcul :",8) == 0) { // Gère le cas du calcul
    char op;
    int num1;
    int num2; 
    
    sscanf(message,"calcul : %c %d %d", &op, &num1, &num2); // Exemple de message : "calcul : + 5 50"
    char* resultat = envoie_operateur_numeros(socketfd, op, num1, num2); // Par exemple : resultat = "resultat : 55"

    if (strcmp(resultat, "Error") == 0) {
      return -1;
    }

    printf("Le résultat du %s\n", resultat);
    free(resultat);

  } else if(strncmp(message,"message :",9) == 0) { // Gère le cas du message

  // Construit le message avec une étiquette "message: "
  char* data = write_and_read(socketfd, message);

  if (strcmp(data, "Error") == 0) {
    return -1;
  }

  // Affiche le message reçu du client
  printf("Message reçu: %s\n", data);
  free(data);

  return 0; // Succès

  } else if (strncmp(message,"moyenne :",9) == 0) { // Gère le cas de la moyenne
    char numero_etudiant[10]; // message = "moyenne : etudiant5"
    sscanf(message,"moyenne : etudiant%s", numero_etudiant);
    char lien[25] = "../etudiant/";
    strcat(lien, numero_etudiant); // Création du lien pour accéder aux notes 

    DIR *dirp = opendir(lien); 
    if (dirp == NULL) {
      return -1;
    }

    int somme = 0;
    int diviseur = 0;
    struct dirent * ent;
    
    while(1) {
        ent = readdir(dirp);
        if (ent == NULL) {
            break;
        }
        if (strcmp(ent->d_name, "..") != 0 && strcmp(ent->d_name, ".") != 0) { // On prend uniquement les fichiers txt qui nous intéressent
          diviseur++;
          char content[10];
          char nom_fichier[30];

          // Création du lien pour pointer vers les fichiers txt
          strcpy(nom_fichier, lien);
          strcat(nom_fichier, "/");
          strcat(nom_fichier, ent->d_name);

          int fichier = open(nom_fichier, O_RDONLY);
          int size = read(fichier, content, 10); // On récupère la note dans content

          char* data =  envoie_operateur_numeros(socketfd, '+', somme, atoi(content)); // On fait à chaque passage dans la boucle la somme

          if (strcmp(data, "Error") == 0) {
            return -1;
          }
          
          sscanf(data,"calcul : %d", &somme); // Permet de récupérer la somme
          free(data);
          close(fichier);
        }
      
    }
    closedir(dirp);
    
    if (diviseur == 0) { // Impossible de diviser par 0
      perror("Il n'y a aucune note");
      return -1;
    } else {

      char* data = envoie_operateur_numeros(socketfd, '/', somme, diviseur); // On calcul la moyenne

      if (strcmp(data, "Error") == 0) {
        return -1;
      }

      char moyenne[2024];

      sscanf(data,"calcul : %s", moyenne); // Permet de récupérer la moyenne
      free(data);
      printf("La moyenne est : %s\n", moyenne);
    }
    return 0;
  }
  
}

int main()
{
  int socketfd;

  struct sockaddr_in server_addr;

  /*
   * Creation d'une socket
   */
  socketfd = socket(AF_INET, SOCK_STREAM, 0);
  if (socketfd < 0)
  {
    perror("socket");
    exit(EXIT_FAILURE);
  }

  // détails du serveur (adresse et port)
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(PORT);
  server_addr.sin_addr.s_addr = INADDR_ANY;

  // demande de connection au serveur
  int connect_status = connect(socketfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
  if (connect_status < 0)
  {
    perror("connection serveur");
    exit(EXIT_FAILURE);
  }

  while (1)
  {
    // appeler la fonction pour envoyer un message au serveur
    envoie_recois_message(socketfd);
  }

  close(socketfd);
}
