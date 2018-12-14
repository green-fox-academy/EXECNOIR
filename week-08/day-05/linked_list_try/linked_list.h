//
// Created by EXEC_NOIR on 12/14/2018.
//

#ifndef LINKED_LIST_TRY_LINKED_LIST_H
#define LINKED_LIST_TRY_LINKED_LIST_H
typedef struct node{
    int value;
    struct node* next;
}node_t;

void push_back_list(node_t** head, int value);
void add_to_beginning_list(node_t** head, int value);
void insert_after(node_t** head, node_t* node, int value);
int get_list_size(node_t** head);
int is_empty(node_t **head);
node_t* delete_first(node_t **head);
int delete_by_value(node_t **head, int value);

#endif //LINKED_LIST_TRY_LINKED_LIST_H
