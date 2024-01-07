#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

void deleteFile(const char *filename) {
    if (remove(filename) == 0) {
    } else {
        perror(filename);
        exit(EXIT_FAILURE);
    }
}

void deleteDirectory(const char *dirname) {
    if (rmdir(dirname) == 0) {
    } else {
        perror(dirname);
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char *argv[]) {
    int opt;

    if (argc < 3) {
        fprintf(stderr, "Usage: %s -d|-f <name1> <name2> ... <nameN>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    opt = getopt(argc, argv, "df:");

    switch (opt) {
        case 'd':
            for (int i = optind ; i < argc; i++) {  // Décaler l'indice initial
                deleteDirectory(argv[i]);
            }
            break;
        case 'f':
            for (int i = optind -1; i < argc; i++) {  // Décaler l'indice initial
                deleteFile(argv[i]);
            }
            break;
        default:
            fprintf(stderr, "Usage: %s -d|-f <name1> <name2> ... <nameN>\n", argv[0]);
            exit(EXIT_FAILURE);
    }

    return 0;
}

