#include <stdio.h>
#include <stdlib.h>
#include "user.h"
#include "user.h"

User *user_init(int id, char *name, char *last_name, User *parent)
{
    User *user = malloc(sizeof(User));

    if (user == NULL)
    {
        return NULL;
    }

    Array *array = array_init(sizeof(User *));

    if (array == NULL)
    {
        free(user);
        user = NULL;
        return NULL;
    }

    user->id = id;
    user->name = name;
    user->last_name = last_name;
    user->childs = array;
    user->parent = parent;

    return user;
}

int user_print(User *user)
{
    if (user == NULL)
    {
        return 1;
    }

    printf("\n---<Printing  User>---\n");
    printf("Id: %d\n", user->id);
    printf("Name: %s\n", user->name);
    printf("Last Name: %s\n", user->last_name);
    if (user->parent != NULL && user != user->parent)
    {
        printf("User No. %d parent:", user->id);
        user_print(user->parent);
    }

    return 0;
}

void user_free(User *user)
{
    if (user == NULL)
    {
        return;
    }

    if (user->childs != NULL && user->childs->length > 0)
    {
        Array *childs = user->childs;

        for (int i = 0; i < childs->length; i++)
        {
            User *child = array_at(user->childs, i);

            free(child);
            child = NULL;
        }
    }

    free(user);
    user = NULL;
}

int user_add_child(User *parent, User *child)
{
    return array_append(parent->childs, child);
}
