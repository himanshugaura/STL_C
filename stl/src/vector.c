#include "vector.h"

Vector* vector_init(size_t elem_size) {
    Vector *vec = malloc(sizeof(Vector));
    if (!vec) return NULL;
    vec->data = NULL;
    vec->elem_size = elem_size;
    vec->size = 0;
    vec->capacity = 0;
    return vec;
}

void vector_free(Vector *vec) {
    if (!vec) return;
    free(vec->data);
    free(vec);
}

size_t vector_size(Vector *vec) { return vec ? vec->size : 0; }
size_t vector_capacity(Vector *vec) { return vec ? vec->capacity : 0; }

static int vector_reserve(Vector *vec, size_t new_cap) {
    if (!vec) return 0;
    if (new_cap <= vec->capacity) return 1;
    void *new_data = realloc(vec->data, new_cap * vec->elem_size);
    if (!new_data) return 0;
    vec->data = new_data;
    vec->capacity = new_cap;
    return 1;
}

int vector_push(Vector *vec, void *elem) {
    if (!vec) return 0;
    if (vec->size == vec->capacity) {
        size_t new_cap = vec->capacity ? vec->capacity*2 : 4;
        if (!vector_reserve(vec, new_cap)) return 0;
    }
    memcpy((char*)vec->data + vec->size*vec->elem_size, elem, vec->elem_size);
    vec->size++;
    return 1;
}

int vector_pop(Vector *vec, void *out_elem) {
    if (!vec || vec->size == 0) return 0;
    vec->size--;
    if (out_elem)
        memcpy(out_elem, (char*)vec->data + vec->size*vec->elem_size, vec->elem_size);
    return 1;
}

void vector_clear(Vector *vec) { if(vec) vec->size = 0; }

void* vector_at(Vector *vec, size_t index) {
    if (!vec || index >= vec->size) return NULL;
    return (char*)vec->data + index*vec->elem_size;
}
