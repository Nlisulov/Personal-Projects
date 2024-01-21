#include "variables.h"
#include <string.h>
#include <stdio.h>


void add_variables(var * variable_list, char *name, int name_len, char * value, int value_len, int * num_vars){
    var new_variable;

    if (*num_vars == 0){
        new_variable.name = malloc(sizeof(char)*name_len);
        new_variable.value = malloc(sizeof(char)*value_len);

        strncpy(new_variable.name, name, name_len);
        strncpy(new_variable.value, value, value_len);
        new_variable.next_var = NULL;

        *variable_list = new_variable;

        *num_vars = *num_vars + 1;
        return;
    }
    
    new_variable.name = malloc(sizeof(char)*name_len);
    new_variable.value = malloc(sizeof(char)*value_len);
    
    var * curr_node = variable_list;
    var * prev_node = variable_list;

    curr_node = curr_node->next_var;

    if (strncmp(prev_node->name, name, name_len) == 0){
        free(prev_node->value);
        free(new_variable.name);
        free(new_variable.value);
        prev_node->value = malloc(sizeof(char)*value_len);
        strncpy(prev_node->value, value, value_len);
        return;
    }

    while (curr_node != NULL)
    {
        if (strncmp(curr_node->name, name, name_len) == 0){
            free(new_variable.name);
            free(curr_node->value);
            free(new_variable.value);
            curr_node->value = malloc(sizeof(char)*value_len);
            strncpy(curr_node->value, value, value_len);
            return;
        }
        prev_node = prev_node->next_var;
        curr_node = curr_node->next_var;
    }


    prev_node->next_var = malloc(sizeof(var));

    new_variable.next_var = NULL;
    strncpy(new_variable.name, name, name_len);
    strncpy(new_variable.value, value, value_len);

    *(prev_node->next_var) = new_variable;

    *num_vars = *num_vars + 1;
    return;
}

void replace_variables(char ** input, var * variable_list, int token_count, int * num_var){
    if (*num_var == 0){
        return;
    }
    int index;
    for(index = 0; index < token_count; index++){
        int len_string = strlen(input[index]);
        int var_length;

        char new_input[token_count][MAX_STR_LEN];
        char * compare_token;

        var * curr_node = variable_list;
        
        if (len_string <= 1){
            continue;
        }
        else if (input[index][0] != '$'){
            continue;
        }

        compare_token = &(input[index][1]); 

        while (curr_node != NULL)
        {
            var_length = strlen(curr_node->value);

            if (strncmp(compare_token, curr_node->name, len_string + 1) == 0){
                strncpy(new_input[index], curr_node->value, var_length + 1);
                input[index] = new_input[index];
            }
            curr_node = curr_node->next_var;
        }
    }
}


void replace_var_assign(var * variable_list, char *name, int * num){
    if (*num == 0){
        return;
    }

    var * curr_node = variable_list;
    while (curr_node != NULL)
    {
        int name_length = strlen(curr_node->name);
        int value_length = strlen(curr_node->value);

        if (strncmp(&(name[1]), curr_node->name, name_length + 1) == 0){
            strncpy(name, curr_node->value, value_length + 1);
            return;
        }
        curr_node = curr_node->next_var;
    }
    

}


