#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
time_t current_time;
struct tm *time_info;
char time_result[100];

current_time = time(NULL);
time_info = localtime(&current_time);

int opt;
char format[25] = "";
while ((opt = getopt(argc, argv, "ymdh")) != -1) {
    switch (opt) {
        case 'y':
            strcat(format, "%Y ");
            break;
        case 'm':
            strcat(format, "%m ");
            break;
        case 'd':
            strcat(format, "%d ");
            break;
        case 'h':
            strcat(format, "%H:%M:%S");
            break;
        default:
            printf("사용법: %s [-y] [-m] [-d] [-h]\n", argv[0]);
            return 1;
    }
}

strftime(time_result, sizeof(time_result), format, time_info);
printf("%s\n", time_result);

return 0;
}
