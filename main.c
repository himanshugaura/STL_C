#include <stdio.h>
#include "vector.h"

int main() {
    Vector *v = vector_init(sizeof(int));

    for (int i=1; i<=5; i++)
        vector_push(v, &i);

    printf("Vector contents: ");
    for (size_t i=0; i<vector_size(v); i++)
        printf("%d ", vector_val(v, int, i));
    printf("\n");

    int last;
    vector_pop(v, &last);
    printf("Popped: %d\n", last);

    vector_free(v);
    return 0;
}
