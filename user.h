#pragma once
#include "array.h"

typedef struct user_t
{
    int id;
    char *name;
    char *last_name;
    struct user_t *parent;
    Array *childs;
} User;

User *user_init(int id, char *name, char *last_name, User *parent);
int user_print(User *user);
void user_free(User *user);
int user_add_child(User *parent, User *child);
