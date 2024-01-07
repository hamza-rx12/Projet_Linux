#include <stdio.h>



// Fonction pour déplacer ou renommer un fichier

int moveFile(const char *ancien_nom, const char *nouveau_nom) {

    // Utilisez la fonction rename pour renommer ou déplacer le fichier

    if (rename(ancien_nom, nouveau_nom) == 0) {

        return 0; // Succès

    } else {

        perror("Erreur lors du renommage ou du déplacement du fichier");

        return 1; // Échec

    }

}



int main(int argc, char *argv[]) {

    // Vérifiez le nombre d'arguments

    if (argc != 3) {

        fprintf(stderr, "Usage: %s <ancien_nom> <nouveau_nom>\n", argv[0]);

        return 1; // Échec

    }



    // Appelez la fonction moveFile avec les arguments fournis

    int resultat = moveFile(argv[1], argv[2]);



    return resultat; // Retournez le résultat de l'opération

} 
