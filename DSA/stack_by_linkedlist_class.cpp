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
int isBalanced(char *exp)
{
    Stack<char> stk;
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
            stk.push(exp[i]);
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if (stk.isEmpty())
                return 0;
            char x = stk.pop();
            if (exp[i] == ')' && x != '(')
                return 0;
            else if (exp[i] == '}' && x != '{')
                return 0;
            else if (exp[i] == ']' && x != '[')
                return 0;
        }
    }
    return stk.isEmpty() ? 1 : 0;
}
int pre(char x)
{
    if (x == '+' || x == '-')
        return 1;
    else if (x == '*' || x == '/')
        return 2;
    else if (isalnum(x))
        return 3;
    return 0;
}
char *infixToPostfix(char *infix)
{
    Stack<char> stk;
    char *postfix = new char[strlen(infix) + 1];
    int i = 0, j = 0;
    while (infix[i] != '\0')
    {
        if (isalnum(infix[i]))
            postfix[j++] = infix[i++];
        else
        {
            if (stk.isEmpty())
                stk.push(infix[i++]);
            else
            {
                if (pre(infix[i]) > pre(stk.stackTop()))
                    stk.push(infix[i++]);
                else
                {
                    postfix[j++] = stk.pop();
                }
            }
        }
    }
    while (!stk.isEmpty())
        postfix[j++] = stk.pop();
    postfix[j] = '\0';
    return postfix;
}
char *infixToPostfix1(char *infix)
{
    Stack<char> stk;
    char *postfix = new char[strlen(infix) + 1];
    int i = 0, j = 0;
    while (infix[i] != '\0')
    {

        if (stk.isEmpty())
            stk.push(infix[i++]);
        else
        {
            if (pre(infix[i]) > pre(stk.stackTop()))
                stk.push(infix[i++]);
            else
            {
                postfix[j++] = stk.pop();
            }
        }
    }
    while (!stk.isEmpty())
        postfix[j++] = stk.pop();
    postfix[j] = '\0';
    return postfix;
}
char *infixToPostfix2(char *infix)
{
    if (!isBalanced(infix))
    {
        char *postfix = new char[strlen(infix) + 1];
        strcpy(postfix, "Invalid Expression");
        return postfix;
    }
    Stack<char> stk;
    char *postfix = new char[strlen(infix) + 1];
    int i = 0, j = 0;
    while (infix[i] != '\0')
    {
        if (isalnum(infix[i]))
        {
            postfix[j++] = infix[i++];
        }
        else
        {
            if (stk.isEmpty())
                stk.push(infix[i++]);
            else
            {
                if (infix[i] == '(')
                    stk.push(infix[i++]);
                else if (infix[i] == ')')
                {
                    while (stk.stackTop() != '(')
                        postfix[j++] = stk.pop();
                    stk.pop();
                    i++;
                }
                else
                {
                    if (infix[i] == '+' || infix[i] == '-')
                    {
                        while (!stk.isEmpty() && stk.stackTop() != '(')
                            postfix[j++] = stk.pop();
                        stk.push(infix[i++]);
                    }
                    else if (infix[i] == '*' || infix[i] == '/')
                    {
                        while (!stk.isEmpty() && stk.stackTop() != '(' && stk.stackTop() != '+' && stk.stackTop() != '-')
                            postfix[j++] = stk.pop();
                        stk.push(infix[i++]);
                    }
                }
            }
        }
    }
    while (!stk.isEmpty())
        postfix[j++] = stk.pop();
    postfix[j] = '\0';
    return postfix;
}
int evaluate(char *exp)
{
    Stack<int> stk;
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (isalnum(exp[i]))
            stk.push(exp[i] - '0');
        else
        {
            int x1 = stk.pop();
            int x2 = stk.pop();
            switch (exp[i])
            {
            case '+':
                stk.push(x2 + x1);
                break;
            case '-':
                stk.push(x2 - x1);
                break;
            case '*':
                stk.push(x2 * x1);
                break;
            case '/':
                stk.push(x2 / x1);
                break;
            }
        }
    }
    return stk.pop();
}
int main()
{
    char exp[] = "(5+3)*(3-1)/2";
    cout << "Infix: " << exp << endl;
    // cout << "Postfix: " << infixToPostfix(exp) << endl;
    // cout << "Postfix: " << infixToPostfix1(exp) << endl;
    cout << "Postfix: " << infixToPostfix2(exp) << endl;
    cout << "Evaluation: " << evaluate(infixToPostfix2(exp)) << endl;

    return 0;
}