#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("사용 방법: cp 원본파일 대상파일\n");
        return 1;
    }

    FILE *src_file = fopen(argv[1], "r");
    FILE *dst_file = fopen(argv[2], "w");

    if (!src_file || !dst_file) {
        printf("파일을 열지 못했습니다.\n");
        return 1;
    }

    int ch;
    while ((ch = fgetc(src_file)) != EOF) {
        fputc(ch, dst_file);
    }

    fclose(src_file);
    fclose(dst_file);

    return 0;
}

