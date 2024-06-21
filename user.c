#include <stdio.h>
#include <stdlib.h>
#include "user.h"

User *user_init(int id, char *name, char *last_name)
{
    User *user = malloc(sizeof(User));

    if (user == NULL)
    {
        return NULL;
    }

    user->id = id;
    user->name = name;
    user->last_name = last_name;

    return user;
}

int user_print(User *user)
{
    if (user == NULL)
    {
        return 1;
    }

    printf("\n---<Printing User>---\n");
    printf("Id: %d\n", user->id);
    printf("Name: %s\n", user->name);
    printf("Last Name: %s\n", user->last_name);

    return 0;
}

void user_free(User *user)
{
    if (user == NULL)
    {
        return;
    }

    free(user);
    user = NULL;
}
