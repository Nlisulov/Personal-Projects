#include <stdio.h>
#include <string.h>


#define LENGTH 255

int main(int argc, char **argv){

    if (argc != 2){
        printf("USAGE: {name of executable} {string of filepath}\n");
        return 1;
    }

    int tokens = 0;
    char *fp = strtok(argv[1], "/");
    char *fp_tokens[LENGTH];
    char *str_vale;

    while(fp != NULL){
         printf("fp_tokens[tokens]: %s, %d\n", fp, (int) strlen(fp));
        fp_tokens[tokens] = fp;
        tokens++;
        fp = strtok(NULL, "/");
    }
    
    return 0;
}