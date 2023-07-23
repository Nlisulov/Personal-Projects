/*
Made by Nathan Lisulov

Expecting users to comply with prompts with code otherwise functionality can't be ensured.
Security not kept in mind while designing this as it is a simple program not designed for
industry use
*/


#include "dynamic_linkedL.h"
#include <stdlib.h>
#include <stdio.h>


//  creates the lList recursively
void create_linkedL_recursive(int counter, int total_nodes, lList * cur_node){

    if(cur_node == NULL){
        return;
    }

    lList *next_node;
    
    printf("\nPlease enter an integer for node #%d:     \n", counter);
    scanf("%d", &(cur_node->value));
    printf("counter: %d     total_nodes: %d", counter, total_nodes);

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

//  creates the lList through the process of a loop
void create_linkedL_loop(int counter, int total_nodes, lList * node){
    
    lList * cur_node = node;

    while(counter <= total_nodes){
        printf("\nPlease enter an integer for node #%d:     \n", counter);
        scanf("%d", &(cur_node->value));

        if (counter < total_nodes){
            cur_node->next = malloc(sizeof(lList));
            cur_node = cur_node->next;
        }
        else{
            cur_node->next = NULL;
        }
        

        counter++;
    }
}

//  prints out tabs in order to facilitate pretty print
void print_tabs(int num_tabs){
    int count = 0;
    while(count < num_tabs){
        printf("\t");
        count++;
    }
}

/*
    pretty printing the entire linked list in order for the user to see the entire
    dynamically allocated list in a easy to see format
*/
void pretty_print(lList * linked_list){
    lList * cur_node = linked_list;
    int counter = 0;
    printf("\n\n");
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


/*
    Clearing the dynamically allocated linked list 
*/
void clear_up_lList(lList * head){
    lList * prev_node = head;
    lList * curr_node = head->next;

    while(prev_node->next != NULL){
        
        prev_node = head;
        curr_node = head->next;


        while(curr_node->next != NULL){
            prev_node = curr_node;
            curr_node = curr_node->next;
            printf("prev_node:      %d, cur_node:       %d\n\n", prev_node->value, curr_node->value);
        }
        printf("curr_node->next pointer:        %p\n\n", curr_node->next);

        
        free(prev_node->next);
        prev_node->next = NULL;
        prev_node = head;
    }

    free(head);
    head = NULL;
}

int main(int argc, char * argv[]){
    lList * head;
    lList * orig_h;

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


    head = malloc(sizeof(lList));
    printf("head_pointer: %p\n\n\n", &head);


    create_linkedL_loop(1, num_nodes, head);
    pretty_print(head);
    printf("\n\n\nhead value: %d, head_pointer: %p\n", head->value, &head);
    clear_up_lList(head);
}