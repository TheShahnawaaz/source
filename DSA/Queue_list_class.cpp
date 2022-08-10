#include <iostream>
using namespace std;
// Create a class for Node
template <class T>
class Node
{
public:
    T data;
    Node *next;
};
// Create a class for Queue using linked list
template <class T>
class Queue
{
private:
    Node<T> *front;
    Node<T> *rear;

public:
    Queue();
    ~Queue();
    // Create a function to check if the queue is empty
    int isEmpty();
    // Create a function to check if the queue is full
    int isFull();
    // Create a function to enqueue an element in the queue
    void enqueue(T x);
    // Create a function to dequeue an element from the queue
    T dequeue();
    // Create a function to peek element of the queue
    T peek(int index);
    // Create a function to check the front element of the queue
    T Front();
    // Create a function to check the rear element of the queue
    T Rear();
    // Create a function to display the queue
    void display();
};
// Create a constructor for Queue using linked list
template <class T>
Queue<T>::Queue()
{
    front = rear = NULL;
}
// Create a destructor for Queue using linked list
template <class T>
Queue<T>::~Queue()
{
    if (!isEmpty())
    {
        Node<T> *p = front;
        while (front)
        {
            front = front->next;
            delete p;
            p = front;
        }
    }
}
// Create a function to check if the queue is empty
template <class T>
int Queue<T>::isEmpty()
{
    return front == NULL;
}
// Create a function to check if the queue is full
template <class T>
int Queue<T>::isFull()
{
    Node<T> *t = new Node<T>;
    int r = (t == NULL);
    delete t;
    return r;
}
// Create a function to enqueue an element in the queue
template <class T>
void Queue<T>::enqueue(T x)
{
    if (isFull())
        cout << "Queue is full" << endl;
    else
    {
        Node<T> *t = new Node<T>;
        t->data = x;
        t->next = NULL;
        if (front == NULL)
            front = rear = t;
        else
        {
            rear->next = t;
            rear = t;
        }
    }
}
// Create a function to dequeue an element from the queue
template <class T>
T Queue<T>::dequeue()
{
    T x = -1;
    if (isEmpty())
        cout << "Queue is empty" << endl;
    else
    {
        Node<T> *p = front;
        front = front->next;
        x = p->data;
        delete p;
    }
    return x;
}
// Create a function to peek element of the queue
template <class T>
T Queue<T>::peek(int index)
{
    if (isEmpty())
        cout << "Queue is empty" << endl;
    else
    {
        Node<T> *p = front;
        for (int i = 0; i < index - 1 && p; i++)
            p = p->next;
        if (p)
            return p->data;
        else
        {
            cout << "Invalid index" << endl;
            return -1;
        }
    }

    return -1;
}
// Create a function to check the front element of the queue
template <class T>
T Queue<T>::Front()
{
    if (isEmpty())
    {
        cout << "Queue is empty" << endl;
        return -1;
    }
    return front->data;
}
// Create a function to check the rear element of the queue
template <class T>
T Queue<T>::Rear()
{
    if (isEmpty())
    {
        cout << "Queue is empty" << endl;
        return -1;
    }
    return rear->data;
}
// Create a function to display the queue
template <class T>
void Queue<T>::display()
{
    if (isEmpty())
        cout << "Queue is empty" << endl;
    else
    {
        Node<T> *p = front;
        while (p)
        {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }
}
int main()
{
    Queue<int> q;
    cout << "Queue is empty: " << q.isEmpty() << endl;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.display();
    cout << "Queue is empty: " << q.isEmpty() << endl;
    cout << "Front element is " << q.Front() << endl;
    cout << "Rear element is " << q.Rear() << endl;
    cout << "Peek element at index 3 is " << q.peek(6) << endl;
    cout << "Dequeued element is " << q.dequeue() << endl;
    cout << "Dequeued element is " << q.dequeue() << endl;
    cout << "Dequeued element is " << q.dequeue() << endl;

    q.display();
    return 0;
}