#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024

int main(int argc, char *argv[]) {

	FILE *file1, *file2;
	char line1[MAX_LINE_SIZE], line2[MAX_LINE_SIZE];
	int lineno = 1;

	if (argc != 3) {
		fprintf(stderr, "사용법: %s 파일1 파일2\n", argv[0]);
		return 1;
	}
	
	file1 = fopen(argv[1], "r");
	
	if (file1 == NULL) {
		perror("파일1 열기 오류");
		return 1;
	}
	
	file2 = fopen(argv[2], "r");
	
	if (file2 == NULL) {

		perror("파일2 열기 오류");
		fclose(file1);
		return 1;
									    }

	while (fgets(line1, MAX_LINE_SIZE, file1) && fgets(line2, MAX_LINE_SIZE, file2)) {
		if (strcmp(line1, line2) != 0) {
			printf("%s(%d): %s", argv[1], lineno, line1);
			printf("%s(%d): %s", argv[2], lineno, line2);
		}
		lineno++;
	}
	fclose(file1);
	fclose(file2);
	return 0;
}
