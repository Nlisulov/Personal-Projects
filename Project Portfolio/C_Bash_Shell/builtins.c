
#include <string.h>
#include <stdio.h>
#include "builtins.h"
#include <stdlib.h>
#include "io_helpers.h"


#include <sys/types.h>
#include <sys/stat.h>
#include <stddef.h>   
#include <unistd.h>
#include <dirent.h>

char ADDED_SLASH[2] = "/";

// ====== Command execution =====

/* Return: index of builtin or -1 if cmd doesn't match a builtin
 */
bn_ptr check_builtin(const char *cmd) {
    ssize_t cmd_num = 0;
    while (cmd_num < BUILTINS_COUNT &&
           strncmp(BUILTINS[cmd_num], cmd, MAX_STR_LEN) != 0) {
        cmd_num += 1;
    }
    return BUILTINS_FN[cmd_num];
}

// ===== Builtins =====

/* Prereq: tokens is a NULL terminated sequence of strings.
 * Return 0 on success and -1 on error ... but there are no errors on echo. 
 */
ssize_t bn_echo(char **tokens) {
    ssize_t index = 1;
    if (tokens[index] != NULL) {
        // TODO:
        // Implement the echo command
        display_message(tokens[index]);
        index += 1;
    }
    while (tokens[index] != NULL) {
        // TODO:
        // Implement the echo command
        display_message(" ");
        display_message(tokens[index]);
        index += 1;
    }
    display_message("\n");

    return 0;
}




/* Prereq: tokens is a NULL terminated sequence of strings.
 * Return 0 on success and -1 on error ... but there are no errors on echo. 
 */
ssize_t bn_wc(char **tokens){
    int num_arg = num_arguments(tokens);
    int dirs;

    char old_path[MAX_STR_LEN]; 
    char new_path[MAX_STR_LEN];

    struct dirent *parentDir;
    DIR * parentDir;

    //getting the current directory
    char *result = getcwd(old_path, PATH_MAX);
    if (result == NULL){fprintf(stderr, "ERROR: Cannot open current working directory\n"); return -1;}

    //Error checking
    //1st Line: Too few arguments
    //2nd Line: Too many arguments
    if (num_arg == 1){fprintf(stderr, "ERROR: No input source provided\n"); return -1;}
    if (num_arg >= 3){fprintf(stderr, "ERROR: Too many arguments provided\n"); return -1;}

    //Have 2 arguments exactly


    return 0;
}





ssize_t bn_cat(char **tokens){
    int num_arg = num_arguments(tokens);
    char file_path[MAX_STR_LEN];

    if (num_arg == 1){fprintf(stderr, "ERROR: No input source provided\n"); return -1;}
    if (num_arg >= 3){fprintf(stderr, "ERROR: Too many arguments provided\n"); return -1;}

    //strcpy(file_path, tokens[num_arg-1]);

    return 0;
}

ssize_t bn_ls(char **tokens){
    int num_arg = num_arguments(tokens);
    char file_path[MAX_STR_LEN];

    if (num_arg == 1){fprintf(stderr, "ERROR: No input source provided\n"); return -1;}
    if (num_arg >= 3){fprintf(stderr, "ERROR: Too many arguments provided\n"); return -1;}

    //strcpy(file_path, tokens[1]);
    
    return 0;
}

ssize_t bn_cd(char **tokens){
    int num_arg = num_arguments(tokens);
    char file_path[MAX_STR_LEN];

    if (num_arg == 1){fprintf(stderr, "ERROR: No input source provided\n"); return -1;}
    if (num_arg >= 3){fprintf(stderr, "ERROR: Too many arguments provided\n"); return -1;}


    return 0;
}


// ==== developer functions ====

/*
Returns the number of characters before the first null-terminator is found
Precondition: char *string must be NULL terminated '\0'
*/

//counts number of input arguments
int num_arguments(char **tokens){
    int argc = 0;
    while (tokens[argc] != NULL){argc++;}
    return argc;
}

int numdirs_without_file(){
    int numdirs = 0;
    
    return numdirs;
}