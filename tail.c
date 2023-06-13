#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    FILE *file;
    char line[1024];
    int count = 0;
    int max_lines = 10;
    int total_lines = 0;
    int current_line = 0;

    if (argc < 2 || (argc == 2 && strcmp(argv[1], "-o") == 0)) {
        printf("사용법: %s [-o <출력_줄_수>] <파일_이름>\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "-o") == 0) {
        if (argc >= 3) {
            max_lines = atoi(argv[2]);
            argc -= 2;
            argv += 2;
        }
        else {
            printf("오류: -o 옵션에 인자가 누락되었습니다\n");
            return 1;
        }
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("파일 열기 중 오류 발생");
        return 1;
    }

    while (fgets(line, sizeof(line), file)) {
        total_lines++;
    }

    fseek(file, 0, SEEK_SET);

    while (current_line < (total_lines - max_lines) && fgets(line, sizeof(line), file)) {
        current_line++;
    }

    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }

    fclose(file);
    return 0;
}

