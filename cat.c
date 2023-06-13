#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    bool count_lines = false;
    bool count_chars = false;
    bool count_find_chars = false;
    char find_char = '\0';
    int opt;

    while ((opt = getopt(argc, argv, "cnf:")) != -1) {
        switch (opt) {
            case 'c':
                count_chars = true;
                break;
            case 'n':
                count_lines = true;
                break;
            case 'f':
                count_find_chars = true;
                find_char = optarg[0];
                break;
            default:
                fprintf(stderr, "사용법: %s [-c] [-n] [-f '알파벳'] 파일이름\n", argv[0]);
                return 1;
        }
    }

    if (optind >= argc) {
        fprintf(stderr, "옵션 입력 후 파일이름이 필요합니다.\n");
        return 1;
    }

    const char *filename = argv[optind];
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("fopen");
        return 1;
    }

    int c;
    int line_count = 1;
    int char_count = 0;
    int find_char_count = 0;

    if (count_lines) {
        printf("\033[32;1m%6d\033[0m ", line_count++);
    }

    while ((c = fgetc(file)) != EOF) {
        printf("%c", c);

        if (count_chars) {
            char_count++;
        }

        if (count_find_chars && c == find_char) {
            find_char_count++;
        }

        if (count_lines && c == '\n') {
            printf("\033[32;1m%6d\033[0m ", line_count++);
        }
    }

    fclose(file);
    putchar('\n');

    if (count_chars) {
        printf("문자 개수: %d\n", char_count);
    }
    if (count_find_chars) {
        printf("특정 문자 '%c' 개수: %d\n", find_char, find_char_count);
    }

    return 0;
}

