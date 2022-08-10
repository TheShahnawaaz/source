#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;
// Create a class for circular queue
template <class T>
class Queue
{
private:
    int size;
    int front;
    int rear;
    T *Q;

public:
    Queue();
    Queue(int size);
    ~Queue();
    // Create a function to display the queue
    void display();
    // Create a function to enqueue an element in the queue
    void enqueue(T x);
    // Create a function to dequeue an element from the queue
    T dequeue();
    // Create a function to check if the queue is empty
    int isEmpty();
    // Create a function to check if the queue is full
    int isFull();
    // Create a function to peek element of the queue
    T peek(int index);
    // Create a function to check the front element of the queue
    T Front();
    // Create a function to check the rear element of the queue
    T Rear();
};
// Create a constructor for circular queue
template <class T>
Queue<T>::Queue()
{
    size = 10;
    front = rear = 0;
    Q = new int[size];
}
// Create a parameterized constructor for circular queue
template <class T>
Queue<T>::Queue(int size)
{
    this->size = size;
    front = rear = 0;
    Q = new int[this->size];
}
// Create a destructor for circular queue
template <class T>
Queue<T>::~Queue()
{
    delete[] Q;
}
// Create a function to check if the queue is empty
template <class T>
int Queue<T>::isEmpty()
{
    return front == rear;
}
// Create a function to check if the queue is full
template <class T>
int Queue<T>::isFull()
{
    return (rear + 1) % size == front;
}
// Create a function to display the queue
template <class T>
void Queue<T>::display()
{
    if (!isEmpty())
    {
        int i = (front + 1) % size;
        do
        {
            cout << Q[i] << " ";
            i = (i + 1) % size;
        } while (i != (rear + 1) % size);
        cout << endl;
    }
}
// Create a function to enqueue an element in the queue
template <class T>
void Queue<T>::enqueue(T x)
{
    if (isFull())
        cout << "Queue is Full" << endl;
    else
    {
        rear = (rear + 1) % size;
        Q[rear] = x;
    }
}
// Create a function to dequeue an element from the queue
template <class T>
T Queue<T>::dequeue()
{
    T x;
    if (isEmpty())
    {
        cout << "Queue is Empty" << endl;
        return -1;
    }

    else
    {
        front = (front + 1) % size;
        x = Q[front];
        return x;
    }
    return -1;
}
// Create a function to peek an element from the queue
template <class T>
T Queue<T>::peek(int index)
{
    if ((front + index) % size <= rear)
        return Q[(front + index) % size];
    cout << "Invalid Index to peek" << endl;
    return -1;
}
// Create a function to display the front element of the queue
template <class T>
T Queue<T>::Front()
{
    if (front != rear)
        return Q[(front + 1) % size];
    cout << "Queue is Empty" << endl;
    return -1;
}
// Create a function to display the rear element of the queue
template <class T>
T Queue<T>::Rear()
{
    if (front != rear)
        return Q[rear];
    cout << "Queue is Empty" << endl;
    return -1;
}
int main()
{
    Queue<int> q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.enqueue(50);
    q.enqueue(3);

    q.display();
    q.dequeue();
    q.display();
    cout << q.peek(1) << endl;
    cout << q.peek(2) << endl;
    cout << q.peek(3) << endl;
    cout << q.Front() << endl;
    cout << q.Rear() << endl;
    return 0;
}