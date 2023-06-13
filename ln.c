#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc < 3 || argc > 4) {
        printf("사용법: %s [-s] <원본> <대상>\n", argv[0]);
        return 1;
    }
    
    int symbolic = 0;
    const char *source;
    const char *target;
    
    if (argc == 4) {
        if (strcmp(argv[1], "-s") != 0) {
            printf("알 수 없는 옵션 '%s'\n", argv[1]);
            return 1;
        }
        symbolic = 1;
        source = argv[2];
        target = argv[3];
    } else {
        source = argv[1];
        target = argv[2];
    }

    int result;
    
    if (symbolic) {
        result = symlink(source, target);
    } else {
        result = link(source, target);
    }

    if (result == -1) {
        perror("링크 생성 오류");
        return 1;
    }

    return 0;
}

