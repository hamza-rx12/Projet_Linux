#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

void createFile(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file != NULL) {
        fclose(file);
    } else {
        perror(filename);
        exit(EXIT_FAILURE);
    }
}

void createDirectory(const char *dirname) {
    if (mkdir(dirname, 0777) == 0) {
    } else {
        perror(dirname);
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char *argv[]) {
    int i;

    if (argc < 3) {
        fprintf(stderr, "Usage: %s -d|-f <name1> <name2> ... <nameN>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    for (i = 2; i < argc; i++) {
        if (argv[1][0] == '-' && (argv[1][1] == 'd' || argv[1][1] == 'f')) {
            if (argv[1][1] == 'd') {
                createDirectory(argv[i]);
            } else if (argv[1][1] == 'f') {
                createFile(argv[i]);
            }
        } else {
            fprintf(stderr, "Usage: %s -d|-f <name1> <name2> ... <nameN>\n", argv[0]);
            exit(EXIT_FAILURE);
        }
    }

    return 0;
}

