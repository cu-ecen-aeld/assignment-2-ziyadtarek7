#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        syslog(LOG_ERR, "Invalid number of arguments");
        printf("Invalid number of arguments\n");
        exit(EXIT_FAILURE);
    }

    openlog("writer", LOG_PID | LOG_CONS, LOG_USER);

    const char *string = argv[2];
    const char *file = argv[1];

    FILE *fp = fopen(file, "w");
    if (fp == NULL) {
        syslog(LOG_ERR, "Failed to open file: %s", file);
        printf("Failed to open file: %s\n", file);
        exit(EXIT_FAILURE);
    }

    int result = fprintf(fp, "%s", string);
    if (result < 0) {
        syslog(LOG_ERR, "Failed to write to file: %s", file);
        printf("Failed to write to file: %s\n", file);
        exit(EXIT_FAILURE);
    }

    fclose(fp);

    syslog(LOG_DEBUG, "Writing %s to %s", string, file);
    printf("Writing %s to %s\n", string, file);

    closelog();

    return 0;
}