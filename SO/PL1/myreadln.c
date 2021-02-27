#include "readln.h"

int main(int argc, char* argv[]) {
    char* line = malloc(sizeof(char) * 16);
    int fd = open("test.txt", O_RDONLY);

    ssize_t readbytes = readln2(fd, line, 16);

    printf("%s\n%ld bytes lidos\n", line, readbytes);
    
    return 0;
}