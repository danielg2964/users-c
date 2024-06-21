typedef struct User
{
    int id;
    char *name;
    char *last_name;
} User;

User *user_init(int id, char *name, char *last_name);
int user_print(User *user);
void user_free(User *user);
