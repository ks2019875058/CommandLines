#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("사용법: %s [-o] 파일명\n", argv[0]);
        return 1;
    }

    int opt;
    int ask_to_delete = 0;
    while ((opt = getopt(argc, argv, "o")) != -1) {
        if (opt == 'o') {
            ask_to_delete = 1;
        } else {
            printf("사용법: %s [-o] 파일명\n", argv[0]);
            return 1;
        }
    }

    if (optind >= argc) {
        printf("사용법: %s [-o] 파일명\n", argv[0]);
        return 1;
    }
    const char *file_name = argv[optind];

    if (ask_to_delete) {
        char answer;
        printf("삭제할까요? [Y/N]: ");
        scanf(" %c", &answer);

        if (answer != 'Y' && answer != 'y') {
            printf("삭제하지 않습니다.\n");
            return 1;
        }
    }

    char command[256];
    sprintf(command, "rm \"%s\"", file_name);
    int result = system(command);

    return result == 0 ? 0 : 1;
}

