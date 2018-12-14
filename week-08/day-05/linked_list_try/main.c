#include <stdio.h>
#include "linked_list.h"
#include <stdlib.h>


int main() {
    node_t* head = NULL;
    head = malloc(sizeof(node_t));
    head->value = 192;
    node_t* node1 = malloc(sizeof(node_t));
    head->next = node1;
    node1->value = 168;
    node_t* node2 = malloc(sizeof(node_t));
    node1->next = node2;
    node2->value = 1;
    node2->next = NULL;
    insert_after(&head, node1, 0);
    push_back_list(&head, 6);
    add_to_beginning_list(&head, 9);




    node_t* p = head;
    while(p != NULL){
        printf("%d.", p->value);
        p = p->next;
    }
    printf("\nSize of list: %d\n", get_list_size(&head));
    //printf("number of deleted nodes: %d\n", deleted);
    return 0;
}