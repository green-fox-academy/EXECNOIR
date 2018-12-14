//
// Created by EXEC_NOIR on 12/14/2018.
//

#include "linked_list.h"
#include <stdlib.h>
#include <stdio.h>

void push_back_list(node_t** head, int value)
{
    node_t* node = malloc(sizeof(node_t));
    node->value = value;
    node->next = NULL;

    if(*head == NULL){
        *head = node;
    }else{
        node_t* p = *head;
        while(p->next != NULL){
            p = p->next;
        }

        p->next = node;
    }


}
void add_to_beginning_list(node_t** head, int value)
{
    node_t* node = malloc(sizeof(node_t));
    if(*head == NULL){
        node->value = value;
        node->next = NULL;
        *head = node;
    }else
        {
        node->next = (*head)->next;
        node->value = (*head)->value;
        (*head)->value = value;
        (*head)->next = node;

        }



}

void insert_after(node_t** head, node_t* node, int value)
{
    node_t* newnode = malloc(sizeof(node_t));
    if(*head == NULL){
        printf("no existing list muh dude");
        return;
    }
    node_t* p = *head;
    while(p != node){
        p = p->next;
    }

    newnode->value = value;
    newnode->next = p->next;
    p->next = newnode;
}
int get_list_size(node_t** head)
{
    int counter = 0;
    node_t* p = *head;
    while(p != NULL){
        counter++;
        p = p->next;
    }
    return counter;
}

int is_empty(node_t **head)
{
    if(*head == NULL){
        return 1;
    }else{
        return 0;
    }
}
node_t* delete_first(node_t **head)
{
    node_t* p = *head;
    *head = (*head)->next;
    free(p);
    return *head;
}
/*int delete_by_value(node_t **head, int value)
{
    node_t* p = *head;
    int counter = 0;
    while(p != NULL){
        if(p->next != NULL) {
            node_t *j = p->next;
            if (j->value == value) {

                p = j->next;
                free(j);
                counter++;
            } else {
                p = p->next;
            }
        }

    }
    return counter;
}*/