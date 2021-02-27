#include "vector.h"

int main() {
    int size = 10;
    Vector v = create(size);
    fill(v, size, 1);
    int i = find(v, size, 1);
    printf("%d\n", i);
    return 0;
}