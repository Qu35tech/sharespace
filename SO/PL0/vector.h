#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct vector
{
    int vsize;
    int v[];
} *Vector;

Vector create(int size);

void fill(Vector vector, int size, int value);

int find(Vector vector, int size, int value);