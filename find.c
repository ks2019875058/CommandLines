#include <stdio.h>
#include <string.h>
#include <dirent.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "사용법: %s 파일명\n", argv[0]);
        return 1;
    }

    char *target_filename = argv[1];
    DIR *dir = opendir(".");
    if (dir == NULL) {
        perror("디렉터리 열기 오류");
        return 1;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, target_filename) == 0) {
            printf("파일 %s를 찾았습니다.\n", target_filename);
            break;
        }
    }

    closedir(dir);
    return 0;
}

