#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;
// Create a struct for Node

struct Node
{
    int data;
    Node *down;
};
// Create a struct for Stack using linked list
struct Stack
{
    struct Node *top;
};
// Create a function to create a stack
void create(struct Stack *st)
{
    st->top = NULL;
}
// Create a function to check if the stack is empty
int isEmpty(struct Stack *ptr)
{
    if (ptr->top == NULL)
        return 1;
    return 0;
}
// Create a function to check if the stack is full
int isFull(struct Stack *ptr)
{
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    if (t == NULL)
        return 1;
    return 0;
}
// Create a function to push an element in the stack
void push(struct Stack *ptr, int x)
{
    if (isFull(ptr))
        cout << "Stack Overflow! Cannot push " << x << " to the stack" << endl;
    else
    {
        struct Node *t = (struct Node *)malloc(sizeof(struct Node));
        t->data = x;
        t->down = ptr->top;
        ptr->top = t;
    }
}
// Create a function to pop an element from the stack
int pop(struct Stack *ptr)
{
    if (isEmpty(ptr))
    {
        cout << "Stack Underflow! Cannot pop from the stack" << endl;
        return -1;
    }
    else
    {
        struct Node *t = ptr->top;
        ptr->top = ptr->top->down;
        int x = t->data;
        free(t);
        return x;
    }
}
// Create a function to peek an element from the stack
int peek(struct Stack *ptr, int pos)
{
    struct Node *p = ptr->top;
    for (int i = 0; (i < pos - 1 && p); i++)
    {
        p = p->down;
    }
    if (p)
        return p->data;
    else
        return -1;
}
// Create a function to display the stack
void display(struct Stack *ptr)
{
    struct Node *p = ptr->top;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->down;
    }
    cout << endl;
}
int main()
{
    struct Stack s;
    struct Stack *st = &s;

    create(st);
    push(st, 10);
    push(st, 20);
    push(st, 30);
    push(st, 40);
    push(st, 50);
    display(st);
    cout << "Popped " << pop(st) << " from the stack" << endl;
    cout << "Popped " << pop(st) << " from the stack" << endl;
    cout << isEmpty(st) << endl;
    cout << "seeking 2nd element from top" << endl;
    cout << peek(st, 2) << endl;
    cout << "seeking 3rd element from top" << endl;
    cout << peek(st, 3) << endl;
    return 0;
}