#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>

int nown(const char *user, const char *group, const char *file_path) {
    struct stat file_stat;
    struct passwd *user_info;
    struct group *group_info;
    uid_t uid;
    gid_t gid;

    // Get file information
    if (stat(file_path, &file_stat) != 0) {
        perror("Error getting file information");
        return -1;
    }

    // Get user information
    if ((user_info = getpwnam(user)) != NULL) {
        uid = user_info->pw_uid;
    } else {
        fprintf(stderr, "Error: User '%s' not found.\n", user);
        return -1;
    }

    // Get group information
    if ((group_info = getgrnam(group)) != NULL) {
        gid = group_info->gr_gid;
    } else {
        fprintf(stderr, "Error: Group '%s' not found.\n", group);
        return -1;
    }

    // Change file ownership
    if (chown(file_path, uid, gid) != 0) {
        perror("Error changing file ownership");
        return -1;
    }

    printf("Ownership of '%s' changed to user: %s, group: %s\n", file_path, user, group);

    return 0;
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <user> <group> <file_path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *user = argv[1];
    const char *group = argv[2];
    const char *file_path = argv[3];

    if (nown(user, group, file_path) != 0) {
        fprintf(stderr, "Failed to change ownership.\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

