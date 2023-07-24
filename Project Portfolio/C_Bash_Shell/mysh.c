#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

#include "builtins.h"
#include "io_helpers.h"
#include "commands.h"
#include "variables.h"



int main(int argc, char* argv[]) {
    char *prompt = "mysh$ "; // TODO Step 1, Uncomment this.

    char input_buf[MAX_STR_LEN + 1];
    input_buf[MAX_STR_LEN] = '\0';
    char *token_arr[MAX_STR_LEN] = {NULL};

    //creating a head for the front of the linked list 
    var *front = malloc(sizeof(var));
    int num_vars = 0;

    while (1) {
        // Prompt and input tokenization

        // TODO Step 2:
        display_message(prompt);
        // Display the prompt via the display_message function.


        int ret = get_input(input_buf);
        if (input_buf[0] == '\0'){
            break;
        }

        size_t token_count = tokenize_input(input_buf, token_arr);

        // Clean exit
        if (token_count == -1){
            continue;
        }
        if (ret != -1 && (token_count == 0 || (strcmp("exit", token_arr[0]) == 0))) {
            break;
        }

        //replace variables in token_arr
        replace_variables(token_arr, front, token_count, &num_vars);

        //check input to see if it's too long

        // Command execution
        if (token_count >= 1) {
            int len_string = strlen(token_arr[0]);
            int equal_index = find_first_equal_char(token_arr[0], len_string);
            bn_ptr builtin_fn = check_builtin(token_arr[0]);
            if (builtin_fn != NULL) {
                ssize_t err = builtin_fn(token_arr);
                if (err == - 1) {
                    display_error("ERROR: Builtin failed: ", token_arr[0]);
                }
            } else if (equal_index != -1 && token_count == 1){
                char value[MAX_STR_LEN];
                char variable[equal_index + 1];
                int name_len;
                int value_len;

                strncpy(variable, token_arr[0], equal_index);
                strncpy(value, (token_arr[0] + equal_index + 1), len_string - equal_index + 1);

                variable[equal_index] = '\0';

                name_len = strlen(variable);
                value_len = strlen(value);

                if (value_len == 1 && value[0] == '='){
                    continue;
                }
                else if (value[0] == '$'){
                    replace_var_assign(front, value, &num_vars);
                }

                add_variables(front, variable, name_len + 1, value, value_len + 1, &num_vars);
            }
            else {
                display_error("ERROR: Unrecognized command: ", token_arr[0]);
            }
        }

    }

    if (num_vars == 0){
        free(front);
        return 0;
    }

    //num_vars >= 1
    while (front->next_var != NULL)
    {
        var * curr_node = front;
        var * prev_node = front;

        curr_node = curr_node->next_var;
        while (curr_node->next_var != NULL)
        {
            curr_node = curr_node->next_var;
            prev_node = prev_node->next_var;
        }
        free(curr_node->name);
        free(curr_node->value);
        free(curr_node);
        prev_node->next_var = NULL;
        free(prev_node->next_var);
    }
    free(front->name);
    free(front->value);
    free(front->next_var);
    free(front);
    
    return 0;
}
