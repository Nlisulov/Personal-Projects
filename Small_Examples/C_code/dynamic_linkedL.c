/*
Made by Nathan Lisulov

Expecting users to comply with prompts with code otherwise functionality can't be ensured.
Security not kept in mind while designing this as it is a simple program not designed for
industry use
*/


#include "dynamic_linkedL.h"
#include <stdlib.h>
#include <stdio.h>


//create 
void create_linkedL_recursive(int counter, int total_nodes, lList * cur_node){

    if(cur_node == NULL){
        return;
    }

    lList *next_node;
    
    printf("\nPlease enter an integer for node #%d:     \n", counter);
    scanf("%d", &(cur_node->value));

    if(counter < total_nodes){
        next_node = malloc(sizeof(lList));
        cur_node->next = next_node;
        create_linkedL_recursive(counter + 1, total_nodes, next_node);
    }
    else{
        next_node = NULL;
        cur_node->next = next_node;
        create_linkedL_recursive(counter + 1, total_nodes, next_node);
        printf("\n\n\n");
    }

}

void create_linkedL_loop(int counter, int total_nodes, lList * node){
    return;
}

void print_tabs(int num_tabs){
    int count = 0;
    while(count < num_tabs){
        printf("\t");
        count++;
    }
}

void pretty_print(lList * linked_list){
    lList * cur_node = linked_list;
    int counter = 0;

    while(cur_node != NULL){
        print_tabs(counter);
        printf("%d\n" ,cur_node->value);

        print_tabs(counter);
        printf("|\n");

        print_tabs(counter);
        printf("---->\n");
        
        counter++;
        cur_node = cur_node->next;
    }
    print_tabs(counter);
    printf("NULL\n");

}

void clear_up_lList(){
    return;
}

int main(int argc, char * argv[]){
    lList first;

    int num_nodes;
    char flag = 0;
    char counter = 0;
    
    do{
        if (flag == 1){
            printf("Please enter in a number greater than or equal to one\n");
            flag = 0;
        }

        printf("Enter the number of codes in the linked list:       ");
        scanf("%d", &num_nodes);
        printf("\n\n\n");

        if (num_nodes <= 0){
            flag = 1;
            counter++;
        }

    } while(num_nodes <= 0 && counter < MAX_ATTEMPTS);

    if (counter == 4){
        printf("Thank you for using this program. Have a nice day\n\n");
        return 0;
    }


    lList * head = malloc(sizeof(lList));

    create_linkedL_recursive(1, num_nodes, head);
    pretty_print(head);
}