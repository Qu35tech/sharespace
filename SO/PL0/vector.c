#include "vector.h"

Vector create(int size) {
    Vector v = malloc(sizeof(struct vector) + size*4);
    v->vsize = size;
    return v;
}

void fill(Vector vector, int size, int value) {
    for (int i=0; i<size; i++) {
        vector->v[i] = value;
    }
}

int find(Vector vector, int size, int value) {
    for (int i=0; i<size; i++) {
        if (vector->v[i]==value) return i;
    }
    return -1;
}