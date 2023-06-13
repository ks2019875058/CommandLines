#include <stdio.h>
#include <stdlib.h>

int compare_files(FILE *fp1, FILE *fp2);

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("사용 방법: cmp file1 file2\n");
        return 1;
    }

    FILE *fp1 = fopen(argv[1], "r");
    FILE *fp2 = fopen(argv[2], "r");

    if (!fp1 || !fp2) {
        printf("파일을 열지 못했습니다.\n");
        return 1;
    }

    int comparison_result = compare_files(fp1, fp2);
    fclose(fp1);
    fclose(fp2);

    if (comparison_result == 0) {
        printf("두 파일은 동일합니다.\n");
    } else {
        printf("두 파일은 다릅니다.\n");
    }

    return 0;
}

int compare_files(FILE *fp1, FILE *fp2) {
    int ch1, ch2;

    do {
        ch1 = fgetc(fp1);
        ch2 = fgetc(fp2);

        if (ch1 == EOF || ch2 == EOF) {
            break;
        }
    } while (ch1 == ch2);

    return ch1 - ch2;
}

