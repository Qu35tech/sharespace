#include "readln.h"

ssize_t readln(int fd, char *line, size_t size) {
    ssize_t counter=0;
    char *buffer = malloc(sizeof(char));
    int i=0;

    //lê e copia para a linha o último carater aka o '\n'
    while (buffer[0]!='\n' && i<size)
    {
        read(fd, buffer, sizeof(char));
        line[i]=buffer[0];
        counter+=sizeof(char);
        i++;
    }
    
    return counter;
}

ssize_t readln2(int fd, char *line, size_t size) {
    ssize_t counter=0;
    char *buffer = malloc(sizeof(char) * size);

    //não contabiliza o '\n' no counter nem o inclui na linha
    read(fd, buffer, size);

    for(int i=0; buffer[i]!='\n' && i<size; i++, counter+=sizeof(char)) line[i]=buffer[i];
    
    return counter;
}