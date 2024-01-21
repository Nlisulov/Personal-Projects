#ifndef __BUILTINS_H__
#define __BUILTINS_H__

#define HOME_DIR "/student/lisulovn"

#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>       
#include <unistd.h>
#include <fcntl.h>



/* Type for builtin handling functions
 * Input: Array of tokens
 * Return: >=0 on success and -1 on error
 */
typedef ssize_t (*bn_ptr)(char **);

ssize_t bn_echo(char **tokens);

ssize_t bn_ls(char **tokens);

ssize_t bn_cd(char **tokens);

ssize_t bn_cat(char **tokens);

ssize_t bn_wc(char **tokens);

/* Return: index of builtin or -1 if cmd doesn't match a builtin
 */
bn_ptr check_builtin(const char *cmd);


//Developer Functions
int my_strlen(char *string);

int num_arguments(char **tokens);

int num_directories(char *file_string, int is_file);

void get_directory_names(int num_dirs, int r_a, char **dir_tokens, char *file_path);

int compare_homedir(char *compare_path, int length_s);



/* BUILTINS and BUILTINS_FN are parallel arrays of length BUILTINS_COUNT
 */
static const char * const BUILTINS[] = {"wc", "cat", "cd", "ls", "echo"};
static const bn_ptr BUILTINS_FN[] = {bn_wc, bn_cat, bn_cd ,bn_ls, bn_echo, NULL};    // Extra null element for 'non-builtin'
static const size_t BUILTINS_COUNT = sizeof(BUILTINS) / sizeof(char *);

#endif
