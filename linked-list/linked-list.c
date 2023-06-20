#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

void insertAtBeginning(struct node** head_ref, int data){
    struct node* new_node = (struct node*)malloc(sizeof(struct node));

    new_node->data = data;
    new_node->next = *head_ref;

    *head_ref = new_node;
}

void insertAfter(struct node* prev_node, int data){
    struct node* new_node = (struct node*)malloc(sizeof(struct node));

    new_node->data = data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

void insertAtEnd(struct node** head_ref, int data){
    struct node* new_node = (struct node*)malloc(sizeof(struct node));

    new_node->data = data;
    new_node->next = NULL;

    struct node* ptr = *head_ref;
    while(ptr->next != NULL){
        ptr = ptr->next;
    }
    ptr->next = new_node;
}

void print(struct node** head_ref){
    struct node* ptr = *head_ref;
    while(ptr != NULL){
        printf("%d --> ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

void deleteAtBeginning(struct node** head_ref){
    struct node* ptr = *head_ref;
    *head_ref = (*head_ref)->next;
    free(ptr);
}

void deleteAtEnd(struct node** head_ref){
    struct node* ptr = *head_ref;
    while(ptr->next->next != NULL){
        ptr = ptr->next;
    }
    struct node* last = ptr->next;
    ptr->next = NULL;
    free(last);
}

void deleteAfter(struct node* prev_node){
    struct node* ptr = prev_node->next;
    prev_node->next = prev_node->next->next;
    free(ptr);
}

int main(){
    struct node* head = NULL;

    insertAtBeginning(&head, 15);
    insertAtEnd(&head, 5);
    insertAtEnd(&head, 11);
    insertAfter(head, 8);
    deleteAtBeginning(&head);
    deleteAtEnd(&head);
    insertAtBeginning(&head, 15);
    insertAtEnd(&head, 11);
    deleteAfter(head);
    print(&head);

    return 0;
}