#ifndef STACK_H
#define STACK_H

#include "vector.h"

typedef struct {
    Vector *vec;
} Stack;

Stack* stack_init(size_t elem_size);
void stack_free(Stack *stack);

int stack_push(Stack *stack, void *elem);
int stack_pop(Stack *stack, void *out_elem);
void* stack_top(Stack *stack);
size_t stack_size(Stack *stack);
int stack_empty(Stack *stack);

#endif
