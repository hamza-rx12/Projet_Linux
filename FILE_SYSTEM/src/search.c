#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>  // Inclure la bibliothèque pour getcwd

void trouverFichiers(const char *debutNom) {
    DIR *dir;
    struct dirent *entree;

    // Obtenir le répertoire courant
    char repertoireCourant[PATH_MAX];
    if (getcwd(repertoireCourant, sizeof(repertoireCourant)) == NULL) {
        perror("Erreur lors de l'obtention du répertoire courant");
        return;
    }

    // Ouvrir le répertoire
    dir = opendir(repertoireCourant);
    if (dir == NULL) {
        perror("Erreur lors de l'ouverture du répertoire");
        return;
    }

    // Lire les entrées du répertoire
    while ((entree = readdir(dir)) != NULL) {
        // Vérifier si le nom de l'entrée commence par la chaîne spécifiée
        if (strncmp(entree->d_name, debutNom, strlen(debutNom)) == 0) {
            printf("%s\n", entree->d_name);
        }
    }

    // Fermer le répertoire
    closedir(dir);
}

int main(int argc, char *argv[]) {
    // Vérifier que le nombre d'arguments est correct
    if (argc != 2) {
        fprintf(stderr, "Usage : %s <début-du-nom>\n", argv[0]);
        return 1;  // Code d'erreur
    }
    trouverFichiers(argv[1]);

    return 0;  
}
