#include <stdio.h>
#include "vector.h"
#include "stack.h"

int main() {
    // ----------------- VECTOR DEMO -----------------
    Vector *v = vector_init(sizeof(char));

    vector_push(v, &(char){'A'});
    vector_push(v, &(char){'B'});
    vector_push(v, &(char){'C'});
    vector_push(v, &(char){'D'});

    printf("Vector contents: ");
    for (size_t i = 0; i < vector_size(v); i++)
        printf("%c ", vector_val(v, char, i));
    printf("\n");

    char last;
    vector_pop(v, &last);
    printf("Vector popped: %c\n", last);

    vector_free(v);

    // ----------------- STACK DEMO -----------------
    Stack *s = stack_init(sizeof(char));

    stack_push(s, &(char){'X'});
    stack_push(s, &(char){'Y'});
    stack_push(s, &(char){'Z'});

    printf("Stack contents (top to bottom): ");
    while (!stack_empty(s)) {
        char top = *(char*)stack_top(s);
        printf("%c ", top);
        stack_pop(s, &top);             
    }
    printf("\n");

    stack_free(s);

    return 0;
}
