#include <stdio.h>
#include <unistd.h>

int main() {
	char buf[1024];
	if (getcwd(buf, sizeof(buf)) != NULL) {
		printf("현재 작업중인 디렉토리: %s\n", buf);
	}
	else {
		perror("getcwd() error");
		return 1;
	}
	return 0;
}

