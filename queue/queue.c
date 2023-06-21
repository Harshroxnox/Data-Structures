#include <stdio.h>

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