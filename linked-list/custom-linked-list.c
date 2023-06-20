#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node * next;
};


struct node* createLinkedList(int n){
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    struct node* head = ptr;
    
    for(int i=0; i<n; i++){
        
        printf("Enter data: ");
        scanf("%d", &(ptr->data));
        
        if(i != n-1){
            ptr->next = (struct node*)malloc(sizeof(struct node));
        }

        ptr = ptr->next;
    }

    ptr = NULL;

    return head;
}

int main(){
    struct node* head = createLinkedList(4);
    
    struct node* ptr = head;
    while(ptr != NULL){
        printf("%d --> ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");

}