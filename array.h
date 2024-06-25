#pragma once

typedef struct array_t
{
    size_t capacity;
    size_t max_capacity;
    size_t pointer_size;
    size_t length;
    void **items;
} Array;

Array *array_init(size_t pointer_size);
int array_append(Array *array, void *item);
int array_set_at(Array *array, void *item, size_t at);
void *array_at(Array *array, size_t at);
void array_free(Array *array);
