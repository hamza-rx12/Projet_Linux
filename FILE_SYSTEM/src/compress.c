#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void compress_file(const char *source_path, const char *dest_path) {
    FILE *source_file = fopen(source_path, "rb");
    if (!source_file) {
        perror("Error opening source file");
        exit(EXIT_FAILURE);
    }

    FILE *dest_file = fopen(dest_path, "wb");
    if (!dest_file) {
        perror("Error opening destination file");
        fclose(source_file);
        exit(EXIT_FAILURE);
    }

    int current_char = fgetc(source_file);
    int count = 1;

    while (current_char != EOF) {
        int next_char = fgetc(source_file);

        if (next_char == current_char) {
            count++;
        } else {
            fprintf(dest_file, "%d%c", count, current_char);
            count = 1;
            current_char = next_char;
        }
    }

    fclose(source_file);
    fclose(dest_file);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source_file> <dest_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *source_path = argv[1];
    const char *dest_path = argv[2];

    compress_file(source_path, dest_path);


    return EXIT_SUCCESS;
}

