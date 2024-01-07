#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <username1> <username2> ...\n", argv[0]);
        return EXIT_FAILURE;
    }

    for (int i = 1; i < argc; i++) {
        const char *username = argv[i];

        // Check if the user already exists
        struct passwd *existing_user = getpwnam(username);
        if (existing_user != NULL) {
            fprintf(stderr, "User '%s' already exists.\n", username);
            continue;  // Move on to the next user
        }

        // Construct the command string
        char command[100];
        snprintf(command, sizeof(command), "sudo useradd -m -s /bin/bash %s", username);

        // Create the user
        if (system(command) == 0) {
            printf("User '%s' created successfully.\n", username);
        } else {
            perror("Error creating user");
            return EXIT_FAILURE;
        }
    }

    return EXIT_SUCCESS;
}

