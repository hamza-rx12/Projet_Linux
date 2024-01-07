#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>

int remove_user(const char *username) {
    // Check if the user exists
    struct passwd *existing_user = getpwnam(username);
    if (existing_user == NULL) {
        fprintf(stderr, "User '%s' does not exist.\n", username);
        return EXIT_FAILURE;
    }

    // Construct the command string
    char command[100];
    snprintf(command, sizeof(command), "sudo userdel -r %s", username);

    // Remove the user
    if (system(command) == 0) {
        printf("User '%s' removed successfully.\n", username);
        return EXIT_SUCCESS;
    } else {
        perror("Error removing user");
        return EXIT_FAILURE;
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <username1> <username2> ...\n", argv[0]);
        return EXIT_FAILURE;
    }

    for (int i = 1; i < argc; i++) {
        const char *username = argv[i];

        // Remove the user
        int result = remove_user(username);
        if (result != EXIT_SUCCESS) {
            fprintf(stderr, "Failed to remove user '%s'\n", username);
            return result;
        }
    }

    return EXIT_SUCCESS;
}

