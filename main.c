#include <stdio.h>
#include <stdlib.h>

#include "array.h"
#include "user.h"

#define USER_COUNT 1025

int main()
{
    User *parent = user_init(0, "Name", "Last Name", NULL);

    if (parent == NULL)
    {
        printf("Cannot create parent user\n");
        return 1;
    }

    parent->parent = parent;

    Array *array = parent->childs;

    for (int i = 0; i < USER_COUNT; i++)
    {
        User *user = user_init(i, "Name", "Last Name", parent);

        if (user == NULL)
        {
            printf("Cannot allocate memory for user No. %d\n", i);
            continue;
        }

        int append_result = array_append(array, user);

        if (append_result == 2)
        {
            printf("Max capacity has been reached!\n");
            printf("Capacity: %d struct Users\n", array->capacity);
        }
        else if (append_result != 0)
        {
            printf("Cannot append user No. %d to array\n", i);
            user_free(user);
            user = NULL;
            continue;
        }

        user_print(user);
    }

    user_free(parent);
    parent = NULL;
    return 0;
}