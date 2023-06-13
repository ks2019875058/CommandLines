#include <stdio.h>
#include <unistd.h>

int main() {
    char *username;
    username = getlogin();

    if (username == NULL) {
        perror("유저 정보를 찾을 수 없음");
        return 1;
    }

    printf("%s\n", username);
    return 0;
}
