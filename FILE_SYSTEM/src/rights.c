#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

int convertir_permissions(const char *permissions) {
    int resultat = 0;

    while (*permissions) {
        switch (*permissions) {
            case 'r':
                resultat |= S_IRUSR;
                break;
            case 'w':
                resultat |= S_IWUSR;
                break;
            case 'x':
                resultat |= S_IXUSR;
                break;
            default:
                fprintf(stderr, "Caractère de permission non valide : %c\n", *permissions);
                exit(EXIT_FAILURE);
        }
        permissions++;
    }

    return resultat;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <permissions> <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *permissions = argv[1];
    const char *filename = argv[2];

    mode_t nouvelles_permissions = convertir_permissions(permissions);

    if (chmod(filename, nouvelles_permissions) == 0) {
    } else {
        perror(filename);
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

