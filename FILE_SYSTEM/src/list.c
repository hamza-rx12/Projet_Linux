#include <stdio.h>
#include <dirent.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    DIR *dir;
    struct dirent *entry;

    // Ouvrir le répertoire
    if ((dir = opendir(argv[1])) == NULL) {
        perror("Erreur lors de l'ouverture du répertoire");
        return 1;
    }

    // Lire et afficher les entrées du répertoire
    while ((entry = readdir(dir)) != NULL) {
        printf("%s\n", entry->d_name);
    }

    // Fermer le répertoire
    closedir(dir);

    return 0;
}

