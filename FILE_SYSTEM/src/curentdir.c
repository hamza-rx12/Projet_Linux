#include <stdio.h>
#include <unistd.h>

void afficherCheminRepertoireCourant() {
    char repertoireCourant[4096];  
    if (getcwd(repertoireCourant, sizeof(repertoireCourant)) != NULL) {
        printf("%s\n", repertoireCourant);
    } else {
        perror("Erreur lors de l'obtention du répertoire courant");
    }
}

int main() {
    afficherCheminRepertoireCourant();
    return 0;
}
