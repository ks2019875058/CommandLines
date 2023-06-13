#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    int mode;
    int result;

    if (argc != 3) {
        printf("Usage: %s <permissions in octal> <file_name>\n", argv[0]);
        return 1;
    }

    mode = (int)strtol(argv[1], NULL, 8); 
    result = chmod(argv[2], mode);

    if (result != 0) {
        perror("chmod 오류 발생");
        return 1;
    }

    printf("권한이 변경되었습니다.\n");
    return 0;
}

