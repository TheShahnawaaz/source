#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
using namespace std;
// Create a struct for Queue
struct Queue
{
    int size;
    int front;
    int rear;
    int *Q;
};
// Create a function to create a queue
void create(struct Queue *q, int size)
{
    q->size = size;
    q->front = q->rear = -1;
    q->Q = (int *)malloc(q->size * sizeof(int));
}
// Create a function to display the queue
void display(struct Queue q)
{
    int i;
    for (i = q.front + 1; i <= q.rear; i++)
        printf("%d ", q.Q[i]);
    printf("\n");
}
// Create a function to enqueue an element in the queue
void enqueue(struct Queue *q, int x)
{
    if (q->rear == q->size - 1)
        printf("Queue is Full");
    else
    {
        q->rear++;
        q->Q[q->rear] = x;
    }
}
// Create a function to dequeue an element from the queue
int dequeue(struct Queue *q)
{
    int x = -1;
    if (q->front == q->rear)
        printf("Queue is Empty");
    else
    {
        q->front++;
        x = q->Q[q->front];
    }
    return x;
}
// Create a function to check if the queue is empty
int isEmpty(struct Queue q)
{
    return q.front == q.rear;
}
// Create a function to check if the queue is full
int isFull(struct Queue q)
{
    return q.rear == q.size - 1;
}
// Create a function to peek an element from the queue
int peek(struct Queue q, int index)
{
    int x = -1;
    if (q.front + index <= q.rear)
        x = q.Q[q.front + index];
    return x;
}
// Create a function to display the front element of the queue
int queueFront(struct Queue q)
{
    int x = -1;
    if (q.front != q.rear)
        x = q.Q[q.front + 1];
    return x;
}
// Create a function to display the rear element of the queue
int queueRear(struct Queue q)
{
    int x = -1;
    if (q.front != q.rear)
        x = q.Q[q.rear];
    return x;
}
int main()
{
    struct Queue q;
    create(&q, 5);
    enqueue(&q, 10);
    enqueue(&q, 20);
    dequeue(&q);
    enqueue(&q, 30);
    enqueue(&q, 40);
    dequeue(&q);
    enqueue(&q, 50);
    enqueue(&q, 60);
    // enqueue(&q, 60);

    display(q);
    return 0;
}