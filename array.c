#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <signal.h>

#include "array.h"

#define ARRAY_INITIAL_CAPACITY 256
#define ARRAY_INITIAL_MAX_CAPACITY 1024

Array *array_init(size_t pointer_size)
{
    Array *array = malloc(sizeof(Array));

    if (array == NULL)
    {
        return NULL;
    }

    void **items = malloc(pointer_size * ARRAY_INITIAL_CAPACITY);

    if (items == NULL)
    {
        free(array);
        array = NULL;
        return NULL;
    }

    array->items = items;
    array->pointer_size = pointer_size;
    array->capacity = ARRAY_INITIAL_CAPACITY;
    array->length = 0;
    array->max_capacity = ARRAY_INITIAL_MAX_CAPACITY;

    return array;
}

int array_append(Array *array, void *item)
{
    if (array == NULL)
    {
        return 1;
    }

    if (array->items == NULL)
    {
        return 1;
    }

    size_t new_length = array->length + 1;

    size_t array_memory_in_use = array->pointer_size * array->capacity;

    size_t array_memory_required = array->pointer_size * new_length;

    if (new_length > array->max_capacity)
    {
        return 2;
    }
    if (array_memory_required > array_memory_in_use)
    {
        void **realloc_result = realloc(array->items, array_memory_required);

        if (realloc_result == NULL)
        {
            return 1;
        }

        void **new_items = realloc_result;

        size_t index_for_item = new_length - 1;

        new_items[index_for_item] = item;

        array->items = new_items;
        array->length = new_length;
        array->capacity = array_memory_required / array->pointer_size;

        return 0;
    }
    else
    {
        void **new_items = array->items;

        size_t index_for_item = new_length - 1;

        new_items[index_for_item] = item;

        array->length = new_length;

        return 0;
    }
}

int array_set_at(Array *array, void *item, size_t at)
{
    if (array = NULL)
    {
        return 1;
    }

    if (array->items == NULL)
    {
        return 1;
    }

    if (at > array->length - 1)
    {
        return 1;
    }

    array->items[at] = item;
}

void *array_at(Array *array, size_t at)
{
    if (array == NULL)
    {
        return NULL;
    }

    if (array->items == NULL)
    {
        return NULL;
    }

    if (array->length < at)
    {
        return NULL;
    }

    return array->items[at];
}

void array_free(Array *array)
{
    if (array == NULL)
    {
        return;
    }

    if (array->items != NULL)
    {
        free(array->items);
        array->items = NULL;
    }

    free(array);
    array = NULL;
}
