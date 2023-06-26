#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    for(int i = 0; i < 10; i++){
        printf("integer j  : %d\n", i);
        printf("left shift : j >> 1: %d\n", i >> 1);
        printf("right shift: 1 << j: %d\n", 1 << i);
        printf("\n\n");
    }
}