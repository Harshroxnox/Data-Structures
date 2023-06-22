// Circular array implementation of queue

#include <stdio.h>
#include <stdlib.h>

// Structure for my queue it contains

// front -> which contains index of first element in array(or queue)
// rear -> which contains index of last element in array(or queue)
// elements -> an integer to track the no. of elements in array(or queue)
// size -> length of the array which needs to be predetermined because size of array is fixed
// array -> an int pointer to first index of array which contains the elements of queue

struct queue {
    int front;
    int rear;
    int elements;
    int size;
    int * array;
};


// This function creates the queue 
// Note: it only needs the size beforehand to do so.
// Creates queue pointer gives it memory, sets the size, front to zero
// and rear one behind front since this is circular implementation one behind front(starting index i.e 0) is 
// the last index size-1

struct queue* createQueue(int size){
    struct queue* queue = (struct queue *)malloc(sizeof(struct queue));

    queue->size = size;
    queue->front = 0;
    queue->rear = size-1;
    queue->elements = 0;
    
    queue->array = (int *)malloc(size * sizeof(int));
    return queue;    
}

// Checks if queue is empty by just seeing if elements is zero or not
// returns 1 if true else 0

int isEmpty(struct queue* queue){
    if(queue->elements == 0){
        return 1;
    }else{
        return 0;
    }
}

// Similarly this checks if queue is full i.e the size of array is equal to num of elements

int isFull(struct queue* queue){
    if(queue->elements == queue->size){
        return 1;
    }else{
        return 0;
    }
}

// Places the element to the last of the queue if there is free space on the array 
// increments rear value by one circularly( i.e if rear is last and there is free space then it will to the first index(0))
// places the data value on the array on rear index
// increments elements

void enqueue( struct queue* queue, int data){
    if(isFull(queue)){
        printf("Cannot Enqueue. Queue full!\n");
        return;
    }
    queue->rear = (queue->rear+1)%(queue->size);
    *(queue->array + queue->rear) = data;
    queue->elements++;
    printf("%d enqueued!\n", data);
}

// a function that iterates through each value inside array no. of elements times and then
// displays it.

void display(struct queue* queue){
    if(isEmpty(queue)){
        printf("No elements to display!\n");
        return;
    }
    for(int i=queue->front; i<queue->elements; i++){
        printf(" <-- %d",*(queue->array+i));
    }
    printf("\n");
}

int main(){

    struct queue* queue = createQueue(5);

    enqueue(queue, 13);
    enqueue(queue, 4);
    enqueue(queue, 8);
    enqueue(queue, 12);
    enqueue(queue, 5);
    enqueue(queue, 2);

    display(queue);

    printf("front %d\n", queue->front);
    printf("rear %d\n", queue->rear);
    printf("elements %d\n", queue->elements);

    


    return 0;
}