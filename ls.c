#include <stdio.h>
#include <dirent.h>
#include <stdbool.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    bool print_inode = false;
    bool print_all = false;
    int opt;

    while ((opt = getopt(argc, argv, "ia")) != -1) {
        switch (opt) {
            case 'i':
                print_inode = true;
                break;
            case 'a':
                print_all = true;
                break;
            default:
                fprintf(stderr, "Usage: %s [-i] [-a]\n", argv[0]);
                return 1;
        }
    }

    DIR *dir;
    struct dirent *entry;

    dir = opendir(".");
    if (dir == NULL) {
        perror("opendir");
        return 1;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (!print_all && entry->d_name[0] == '.') {
            continue;
        }

        if (print_inode) {
            printf("%lu ", (unsigned long)entry->d_ino);
        }

        printf("%s\n", entry->d_name);
    }

    closedir(dir);
    return 0;
}

