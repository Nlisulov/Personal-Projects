#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define LENGTH 255

int main(int argc, char **argv){

    if (argc != 2){
        printf("USAGE: {name of executable} {string of filepath}\n");
        return 1;
    }

    
    int tokens = 0;
    int token_len;
    int len_fp = strlen(argv[1]);

    char *n_token;
    char *fp_tokens[LENGTH];
    char *fp;

    strncpy(fp, argv[1], len_fp + 1);
    fp = strtok(fp, "/");

    while(fp != NULL){
        token_len = strlen(fp);
        printf("fp_tokens[%d]: %s, %d\n", tokens, fp, token_len);

        fp_tokens[tokens] = fp;
        tokens++;
        fp= strtok(NULL, "/");
    }
    printf("tokens: %d\n\n", tokens);
    
}