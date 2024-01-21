#include <stdlib.h>

#define MAX_STR_LEN 64

typedef struct linked_variables{
    char *name;
    char *value;
    struct linked_variables * next_var;
}var;

void add_variables(var * variable_list, char *name, int name_len, char * value, int value_len, int * num_vars);

void replace_variables(char ** input, var * variable_list, int token_count, int * num_var);

void replace_var_assign(var * variable_list, char *name, int * num);