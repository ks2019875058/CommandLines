#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "사용법: %s 디렉토리명\n", argv[0]);
        return 1;
    }

    if (rmdir(argv[1]) != 0) {
        perror("디렉토리 제거 오류");
        return 1;
    }

    printf("디렉토리를 제거했습니다: %s\n", argv[1]);
    return 0;
}

