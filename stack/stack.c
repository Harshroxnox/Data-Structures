#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct stack {
    int count;
    struct node* top;
};

struct stack * createStack(){
    struct stack* st = (struct stack*)malloc(sizeof(struct stack));
    st->count = 0;
    st->top = NULL;
    return st;
}

int isFull(){
    struct node * ptr = (struct node*)malloc(sizeof(struct node));
    if(ptr == NULL){
        return 1;
    }else{
        free(ptr);
        return 0;
    }
}

void push(struct stack* st, int data){

    if(isFull() == 1){
        printf("The stack is already full\nStack Overflow!\n");
        return;
    }
    struct node* newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = st->top;
    st->top = newNode;
    st->count++;
    printf("Pushed %d!\n", data);

}

void display(struct stack* st){
    if(st->top == NULL){
        printf("Stack Empty!\n");
        return;
    }
    struct node* ptr = st->top;
    printf("The elements in the stack are:\n");
    while(ptr != NULL){
        printf(" --> %d\n", ptr->data);
        ptr = ptr->next;
    }
}

void pop(struct stack* st){
    if(st->top == NULL){
        printf("Stack Empty!\n");
        return;
    }
    struct node* ptr = st->top; 
    st->top = (st->top)->next;
    free(ptr);
    st->count--;
    printf("Popped!\n");
}

void peek(struct stack* st){
    if(st->top == NULL){
        printf("Stack Empty!\n");
        return;
    }
    printf("First element is: %d\n", st->top->data);
}

void isEmpty(struct stack* st){
    if(st->top == NULL){
        printf("Stack is Empty!\n");
    }else{
        printf("Stack is not Empty!\n");
    }
}

void numOfElements(struct stack* st){
    printf("The no. of elements in stack: %d\n", st->count);
}

int main(){
    
    struct stack* st = createStack();

    pop(st);
    push(st,5);
    push(st,14);
    push(st,11);
    push(st, 23);
    display(st);
    numOfElements(st);
    pop(st);
    pop(st);
    display(st);

        
   // The elements in the stack are:
   // --> 14
   // --> 5
        

    peek(st);
    isEmpty(st);
    numOfElements(st);
    
 

    return 0;
}