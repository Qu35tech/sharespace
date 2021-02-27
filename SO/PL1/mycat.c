#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#define buffersize 1024

int main(int argc, char* argv[]) {
    char *buffer = malloc(sizeof(char) * buffersize);

    ssize_t fsize = read(0, buffer, buffersize);
    write(1, buffer, fsize);
    printf("%ld bytes lidos\n", fsize);

    free(buffer);

    return 0;
}