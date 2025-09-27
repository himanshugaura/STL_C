#ifndef VECTOR_H
#define VECTOR_H

#include <stddef.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    void *data;
    size_t elem_size;
    size_t size;
    size_t capacity;
} Vector;

Vector* vector_init(size_t elem_size);
void vector_free(Vector *vec);

int vector_push(Vector *vec, void *elem);
int vector_pop(Vector *vec, void *out_elem);
void vector_clear(Vector *vec);

void* vector_at(Vector *vec, size_t index);
size_t vector_size(Vector *vec);
size_t vector_capacity(Vector *vec);

#define vector_val(vec, type, index) (*(type*)vector_at(vec, index))

#endif
