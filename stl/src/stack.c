#include "stack.h"

Stack* stack_init(size_t elem_size) {
    Stack *stack = malloc(sizeof(Stack));
    if (!stack) return NULL;
    stack->vec = vector_init(elem_size);
    if (!stack->vec) {
        free(stack);
        return NULL;
    }
    return stack;
}

void stack_free(Stack *stack) {
    if (!stack) return;
    vector_free(stack->vec);
    free(stack);
}

int stack_push(Stack *stack, void *elem) {
    if (!stack) return 0;
    return vector_push(stack->vec, elem);
}

int stack_pop(Stack *stack, void *out_elem) {
    if (!stack) return 0;
    return vector_pop(stack->vec, out_elem);
}

void* stack_top(Stack *stack) {
    if (!stack || vector_size(stack->vec) == 0) return NULL;
    return vector_at(stack->vec, vector_size(stack->vec) - 1);
}

size_t stack_size(Stack *stack) {
    if (!stack) return 0;
    return vector_size(stack->vec);
}

int stack_empty(Stack *stack) {
    return stack_size(stack) == 0;
}
