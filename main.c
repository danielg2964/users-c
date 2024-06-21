#include <stdio.h>
#include <stdlib.h>

#include "array.h"
#include "user.h"

#define USER_COUNT 20

int main()
{
    Array *array = array_init(sizeof(User *));

    if (array == NULL)
    {
        printf("Cannot allocate memory for array\n");
        return 1;
    }

    for (int i = 0; i < USER_COUNT; i++)
    {
        User *user = user_init(i, "Name", "Last Name");

        if (user == NULL)
        {
            printf("Cannot allocate memory for user No. %d\n", i);
            continue;
        }

        int append_result = array_append(array, user);

        if (append_result != 0)
        {
            printf("Cannot append user No. %d to array\n", i);
            user_free(user);
            user = NULL;
        }

        int print_result = user_print(array_at(array, i));

        if (print_result != 0)
        {
            printf("Cannot print user %d\n", i);
        }
    }

    for (int i = 0; i < array->length; i++)
    {
        User *user = array_at(array, i);

        user_free(user);
        user = NULL;
    }

    array_free(array);
    array = NULL;
    return 0;
}