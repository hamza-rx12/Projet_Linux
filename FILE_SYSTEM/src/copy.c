#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 4096

int copyFile(const char *source_path, const char *destination_path) {
    FILE *source_file, *destination_file;
    char buffer[BUFFER_SIZE];
    size_t bytesRead;

    // Open the source file for reading
    source_file = fopen(source_path, "rb");
    if (source_file == NULL) {
        perror("Error opening source file");
        return 1; // Failure
    }

    // Open the destination file for writing
    destination_file = fopen(destination_path, "wb");
    if (destination_file == NULL) {
        perror("Error opening destination file");
        fclose(source_file);
        return 1; // Failure
    }

    // Copy content from source to destination
    while ((bytesRead = fread(buffer, 1, sizeof(buffer), source_file)) > 0) {
        fwrite(buffer, 1, bytesRead, destination_file);
    }

    // Close the files
    fclose(source_file);
    fclose(destination_file);

    return 0; // Success
}

int main(int argc, char *argv[]) {
    // Verify the number of arguments
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source_file> <destination_file>\n", argv[0]);
        return 1; // Failure
    }

    // Call the copyFile function with the provided source and destination paths
    int result = copyFile(argv[1], argv[2]);

    return result; // Return the result of the operation
}

