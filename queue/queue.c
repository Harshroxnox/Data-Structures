#include <stdio.h>
#include <stdlib.h>

struct queue {
    int front;
    int rear;
    int elements;
    int size;
    int * array;
};

struct queue* createQueue(int size){
    struct queue* queue = (struct queue *)malloc(sizeof(struct queue));

    queue->size = size;
    queue->front = 0;
    queue->rear = size-1;
    queue->elements = 0;
    
    queue->array = (int *)malloc(size * sizeof(int));
    return queue;    
}

int isEmpty(struct queue* queue){
    if(queue->elements == 0){
        return 1;
    }else{
        return 0;
    }
}

int isFull(struct queue* queue){
    if(queue->elements == queue->size){
        return 1;
    }else{
        return 0;
    }
}

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