#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;
// Create a struct for Stack
struct Stack
{
    int size;
    int top;
    int *S;
};
// Create a function to create a stack
void create(struct Stack *st)
{
    cout << "Enter the size of the stack: ";
    cin >> st->size;
    st->top = -1;
    st->S = (int *)malloc(st->size * sizeof(int));
}
// Create a function to check if the stack is empty
int isEmpty(struct Stack st)
{
    if (st.top == -1)
        return 1;
    return 0;
}
// Create a function to check if the stack is full
int isFull(struct Stack st)
{
    return (st.top == st.size - 1);
}
// Create a function to push an element in the stack
void push(struct Stack *st, int x)
{
    if (isFull(*st))
        cout << "Stack Overflow" << endl;
    else
    {
        st->top++;
        st->S[st->top] = x;
    }
}
// Create a function to pop an element from the stack
int pop(struct Stack *st)
{
    int x = -1;
    if (isEmpty(*st))
        cout << "Stack Underflow" << endl;
    else
    {
        x = st->S[st->top--];
    }
    return x;
}
// Create a function to peek an element from the stack
int peek(struct Stack st, int index)
{
    int x = -1;
    if (st.top - index + 1 < 0 || index <= 0)
    {
        cout << "Invalid Index" << endl;
    }
    else
    {
        x = st.S[st.top - index + 1];
    }
    return x;
}
// Create a function to display the top element of the stack
int stackTop(struct Stack st)
{
    if (!isEmpty(st))
        return st.S[st.top];
    return -1;
}
// Create a function to display the stack
void display(struct Stack st)
{
    int i;
    for (i = st.top; i >= 0; i--)
    {
        cout << st.S[i] << " ";
    }
    cout << endl;
}
int main()
{
    struct Stack st;
    create(&st);
    cout << isEmpty(st) << endl;
    push(&st, 10);
    push(&st, 20);
    push(&st, 30);
    push(&st, 40);
    push(&st, 50);
    cout << isFull(st) << endl;
    cout << "Poped element is: " << pop(&st) << endl;
    cout << "top element is: " << stackTop(st) << endl;
    display(st);
    return 0;
}