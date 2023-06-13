#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int ask_confirmation = 0;

    if (argc == 4 && strcmp(argv[1], "-o") == 0) {
        ask_confirmation = 1;
    } else if (argc != 3) {
        printf("사용법: %s [OPTIONS] 이전_파일명 새_파일명\n", argv[0]);
        printf("Options:\n  -o\t변경 확인 후 이름 변경\n");
        return 1;
    }

    if (ask_confirmation) {
        printf("'%s'를 '%s'(으)로 변경하시겠습니까? (y/n): ", argv[2], argv[3]);
        int answer = getchar();

        if (answer == 'y' || answer == 'Y') {
            if (rename(argv[2], argv[3]) != 0) {
                perror("파일 이름 변경 오류");
                return 1;
            }
            printf("%s를 %s로 변경했습니다.\n", argv[2], argv[3]);
        } else {
            printf("파일 이름 변경이 취소되었습니다.\n");
        }
    } else {
        if (rename(argv[1], argv[2]) != 0) {
            perror("파일 이름 변경 오류");
            return 1;
        }
        printf("%s를 %s로 변경했습니다.\n", argv[1], argv[2]);
    }

    return 0;
}

