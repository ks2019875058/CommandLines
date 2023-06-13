#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("사용법: %s 디렉토리_이름\n", argv[0]);
        return 1;
    }

    char command[256];
    sprintf(command, "mkdir \"%s\"", argv[1]);
    int result = system(command);

    return result == 0 ? 0 : 1;
}

