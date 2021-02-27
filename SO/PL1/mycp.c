#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#define buffersize 20

int main(int argc, char * argv []) {
    int fdsource = open(argv[1],  O_RDONLY);
    int fddest = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC , 0600);

    char *buffer = malloc(sizeof(char) * buffersize);


    ssize_t fsize = read(fdsource, buffer, buffersize);
    write(fddest, buffer, fsize);
    printf("%ld bytes lidos\n", fsize);

    close(fdsource);
    close(fddest);
    free(buffer);

    return 0;
}