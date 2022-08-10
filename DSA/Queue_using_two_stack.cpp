#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;
// Create a class for Node
template <class T>
class Node
{
public:
    T data;
    Node *down;
};
// Create a struct for Stack
template <class T>
class Stack
{
private:
    Node<T> *top;

public:
    Stack();
    ~Stack();
    // Create a function to check if the stack is empty
    int isEmpty();
    // Create a function to check if the stack is full
    int isFull();
    // Create a function to push an element in the stack
    void push(T x);
    // Create a function to pop an element from the stack
    T pop();
    // Create a function to peek an element from the stack
    T peek(int index);
    // Create a function to display the top element of the stack
    T stackTop();
    // Create a function to display the stack
    void display();
};
// Create a constructor for Stack
template <class T>
Stack<T>::Stack()
{
    top = NULL;
}
// Create a destructor for Stack
template <class T>
Stack<T>::~Stack()
{
    Node<T> *p = top;
    while (top)
    {
        top = top->down;
        delete p;
        p = top;
    }
}
// Create a function to check if the stack is empty
template <class T>
int Stack<T>::isEmpty()
{
    if (top == NULL)
        return 1;
    return 0;
}
// Create a function to check if the stack is full
template <class T>
int Stack<T>::isFull()
{
    Node<T> *t = new Node<T>;
    int r = t ? 0 : 1;
    delete t;
    return r;
}
// Create a function to push an element in the stack
template <class T>
void Stack<T>::push(T x)
{
    if (isFull())
        cout << "Stack Overflow" << endl;
    else
    {
        Node<T> *t = new Node<T>;
        t->data = x;
        t->down = top;
        top = t;
    }
}
// Create a function to pop an element from the stack
template <class T>
T Stack<T>::pop()
{
    T x = -1;
    if (isEmpty())
        cout << "Stack Underflow" << endl;
    else
    {
        Node<T> *p = top;
        top = top->down;
        x = p->data;
        delete p;
    }
    return x;
}
// Create a function to peek an element from the stack
template <class T>
T Stack<T>::peek(int index)
{
    Node<T> *p = top;
    for (int i = 0; p != NULL && i < index - 1; i++)
    {
        p = p->down;
    }
    if (p != NULL)
        return p->data;
    return -1;
}
// Create a function to display the top element of the stack
template <class T>
T Stack<T>::stackTop()
{
    if (top != NULL)
        return top->data;
    return -1;
}
// Create a function to display the stack
template <class T>
void Stack<T>::display()
{
    Node<T> *p = top;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->down;
    }
    cout << endl;
}
// Create a class for Queue
template <class T>
class Queue
{
private:
    Stack<T> s1;
    Stack<T> s2;

public:
    // Create a function to enqueue an element in the queue
    void enqueue(T x);
    // Create a function to dequeue an element from the queue
    T dequeue();
    // Create a function to check if the queue is empty
    int isEmpty();
    // Create a function to check if the queue is full
    int isFull();
    // Create a function to display the first element of the queue
    T first();
};
// Create a function to enqueue an element in the queue
template <class T>
void Queue<T>::enqueue(T x)
{
    s1.push(x);
}
// Create a function to dequeue an element from the queue
template <class T>
T Queue<T>::dequeue()
{
    T x = -1;
    if (isEmpty())
        cout << "Queue is Empty" << endl;
    else
    {
        if (s2.isEmpty())
        {
            while (!s1.isEmpty())
            {
                s2.push(s1.pop());
            }
        }
        x = s2.pop();
    }
    return x;
}
// Create a function to check if the queue is empty
template <class T>
int Queue<T>::isEmpty()
{
    if (s1.isEmpty() && s2.isEmpty())
        return 1;
    return 0;
}
// Create a function to check if the queue is full
template <class T>
int Queue<T>::isFull()
{
    return 0;
}
// Create a function to display the first element of the queue
template <class T>
T Queue<T>::first()
{
    T x = -1;
    if (isEmpty())
        cout << "Queue is Empty" << endl;
    else
    {
        if (s2.isEmpty())
        {
            while (!s1.isEmpty())
            {
                s2.push(s1.pop());
            }
        }
        x = s2.stackTop();
    }
    return x;
}
int main()
{
    Queue<int> q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.first() << endl;
    cout << q.dequeue() << endl;
    return 0;
}