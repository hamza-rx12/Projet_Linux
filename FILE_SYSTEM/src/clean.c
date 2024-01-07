#include <stdio.h>

void clear_screen() {
    printf("\033[H\033[J"); 
}

int main() {
    printf("Contenu avant le nettoyage.\n");

    // Appel de la fonction pour effacer l'écran
    clear_screen();


    return 0;
}

