#include <stdio.h>
#include <time.h>
#include <utime.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    if (argc <= 1) {
        printf("사용 방법: touch 파일이름\n");
        return 1;
    }

    const char *filename = argv[1];
    
    struct utimbuf new_time;
    new_time.actime = time(NULL);
    new_time.modtime = time(NULL); 

    if (utime(filename, &new_time) < 0) {
        perror("파일 시간 업데이트 실패");
        return 1;
    }

    return 0;
}


