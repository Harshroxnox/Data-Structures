#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

int count = 0;
struct node* top = NULL;

int isFull(){
    struct node * ptr = (struct node*)malloc(sizeof(struct node));
    if(ptr == NULL){
        return 1;
    }else{
        return 0;
    }
}

void push(int data){
    struct node* newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    if(isFull() == 1){
        printf("The stack is already full\nStack Overflow!\n");
    }
    else if(top == NULL){
        newNode->next = NULL;
    }else{
        newNode->next = top;
    }
    top = newNode;
    count++;
    printf("Pushed %d!\n", data);

}

void display(){
    if(top == NULL){
        printf("Stack Empty!\n");
        return;
    }
    struct node* ptr = top;
    printf("The elements in the stack are:\n");
    while(ptr != NULL){
        printf(" --> %d\n", ptr->data);
        ptr = ptr->next;
    }
}

void pop(){
    if(top == NULL){
        printf("Stack Empty!\n");
        return;
    }
    struct node* ptr = top; 
    top = (top)->next;
    free(ptr);
    count--;
    printf("Popped!\n");
}

void peek(){
    if(top == NULL){
        printf("Stack Empty!\n");
        return;
    }
    printf("First element is: %d\n", top->data);
}

void isEmpty(){
    if(top == NULL){
        printf("Stack is Empty!\n");
    }else{
        printf("Stack is not Empty!\n");
    }
}

void numOfElements(){
    printf("The no. of elements in stack: %d\n", count);
}

int main(){
    
    pop();
    push(5);
    push(14);
    push(11);
    push(23);
    display();
    numOfElements();
    pop();
    pop();
    display();

        
   // The elements in the stack are:
   // --> 14
   // --> 5
        

    peek();
    isEmpty();
    numOfElements();
    
 

    return 0;
}