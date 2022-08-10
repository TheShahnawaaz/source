#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;
// Create a struct for Stack
template <class T>
class Stack
{
private:
    int size;
    int top;
    T *S;

public:
    Stack();
    Stack(int size);
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
template <class T>
Stack<T>::Stack()
{
    cout << "Enter the size of the stack: ";
    cin >> size;
    top = -1;
    S = new T[size];
}
template <class T>
Stack<T>::Stack(int size)
{
    top = -1;
    S = new T[size];
}
template <class T>
Stack<T>::~Stack()
{
    delete[] S;
}
// Create a function to check if the stack is empty
template <class T>
int Stack<T>::isEmpty()
{
    if (top == -1)
        return 1;
    return 0;
}
// Create a function to check if the stack is full
template <class T>
int Stack<T>::isFull()
{
    return (top == size - 1);
}
// Create a function to push an element in the stack
template <class T>
void Stack<T>::push(T x)
{
    if (isFull())
        cout << "Stack Overflow" << endl;
    else
    {
        top++;
        S[top] = x;
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
        x = S[top--];
    }
    return x;
}
// Create a function to peek an element from the stack
template <class T>
T Stack<T>::peek(int index)
{
    T x = -1;
    if (top - index + 1 < 0 || index <= 0)
    {
        cout << "Invalid Index" << endl;
    }
    else
    {
        x = S[top - index + 1];
    }
    return x;
}
// Create a function to display the top element of the stack
template <class T>
T Stack<T>::stackTop()
{
    if (!isEmpty())
        return S[top];
    return -1;
}
// Create a function to display the stack
template <class T>
void Stack<T>::display()
{
    int i;
    for (i = top; i >= 0; i--)
    {
        cout << S[i] << " ";
    }
    cout << endl;
}
int main()
{
    Stack<int> st(5);
    st.push(10);
    st.push(20);
    st.push(30);
    st.display();
    cout << st.pop() << endl;
    st.display();
    cout << st.peek(1) << endl;
    cout << st.stackTop() << endl;

    return 0;
}