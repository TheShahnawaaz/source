#include <iostream>
using namespace std;
// create a class for node
class Node
{
public:
    Node *prev;
    int data;
    Node *next;
};
// Create a class for linked list
class DList
{
private:
    Node *first;

public:
    // constructor
    DList()
    {
        first = NULL;
    }
    // constructor
    DList(int A[], int n);
    // destructor
    ~DList();
    // create a function to display the linked list
    void print();
    // Prints the linked list in reverse order
    void print_reverse();
    // create a function to count the number of nodes in the linked list
    int count();
    // create a function to add the elements of the linked list
    int add();
    // create a function to search an element in the linked list
    int index(int key);
    // create a function for acessing an element in the linked list
    int get(int index);
    // create a function to insert an element in the linked list
    void insert(int pos, int x);
    // Instering an element at the last of the linked list
    void append(int x);
    // create a function to insert an element in the sorted linked list
    void sorted_insert(int x);
    // create a function to delete an element in the linked list by index
    int delete_by_index(int index);
    // create a function to delete an element in the linked list by value
    int delete_by_value(int value);
    // create a function to check if the linked list is sorted or not
    int is_sorted();
    // create a function to remove duplicates from the linked list
    void remove_duplicates();
    // create a function to reverse the linked list
    void reverse();
    // create a function to concatenate two linked lists
    void concatenate(DList *l2);
    // create a function to merge two sorted linked lists
    void merge(DList *l2);
    // create a function to check if the linked list is a loop or not
    int isLoop();
};
// create a constructor for linked list
DList::DList(int A[], int n)
{
    Node *last, *t;
    int i = 0;
    first = new Node;
    first->data = A[0];
    first->next = NULL;
    first->prev = NULL;
    last = first;
    for (i = 1; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = NULL;
        t->prev = last;
        last->next = t;
        last = t;
    }
}
// create a destructor for linked list
DList::~DList()
{
    Node *p = first;
    if (!first)
        return;

    while (first)
    {
        first = first->next;
        delete p;
        p = first;
    }
}
// create a function to display the D list
void DList::print()
{
    Node *p = first;
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}
// Prints the linked list in reverse order
void DList::print_reverse()
{
    Node *p = first;
    while (p->next)
        p = p->next;
    while (p)
    {
        cout << p->data << " ";
        p = p->prev;
    }
    cout << endl;
}
// create a function to count the number of nodes in the D list
int DList::count()
{
    Node *p = first;
    int count = 0;
    while (p)
    {
        count++;
        p = p->next;
    }
    return count;
}
// create a function to add the elements of the D list
int DList::add()
{
    Node *p = first;
    int sum = 0;
    while (p)
    {
        sum += p->data;
        p = p->next;
    }
    return sum;
}
// create a function to search an element in the D list
int DList::index(int key)
{
    Node *p = first;
    int index = 0;
    while (p)
    {
        if (p->data == key)
        {
            return index;
        }
        p = p->next;
        index++;
    }
    return -1;
}
// create a function to insert an element in the D list
void DList::insert(int pos, int x)
{
    Node *p = first;
    if (pos < 0 || pos > count())
    {
        printf("Invalid position\n");
        return;
    }
    int i = 0;
    if (pos == 0)
    {
        Node *newnode = new Node;
        newnode->data = x;
        newnode->next = p;
        newnode->prev = NULL;
        if (p)
            p->prev = newnode;
        first = newnode;
        return;
    }
    while (p)
    {
        if (i == pos - 1)
        {
            Node *newnode = new Node;
            newnode->data = x;
            newnode->next = p->next;
            newnode->prev = p;
            if (p->next)
                p->next->prev = newnode;
            p->next = newnode;
            return;
        }
        p = p->next;
        i++;
    }
    return;
}
// Instering an element at the last of the D list
void DList::append(int x)
{
    Node *p = first;
    Node *newnode = new Node;
    newnode->data = x;
    newnode->next = NULL;
    if (!first)
    {
        newnode->prev = NULL;
        first = newnode;
        return;
    }
    while (p->next)
        p = p->next;
    p->next = newnode;
    newnode->prev = p;
    return;
}
// create a function for acessing an element in the D list
int DList::get(int index)
{
    if (index < 0 || index >= count())
    {
        cout << "Invalid index" << endl;
        return -1;
    }
    Node *q = NULL;
    Node *p = first;
    int count = 0;
    while (p)
    {
        if (count == index)
        {
            return p->data;
        }
        q = p;
        p = p->next;
        count++;
    }
    return -1;
}
// create a function to insert an element in the sorted D list
void DList::sorted_insert(int x)
{
    Node *p = first;
    if (!p)
    {
        Node *newnode = new Node;
        newnode->data = x;
        newnode->next = NULL;
        newnode->prev = NULL;
        first = newnode;
        return;
    }
    if (p->data > x)
    {
        Node *newnode = new Node;
        newnode->data = x;
        newnode->next = p;
        newnode->prev = NULL;
        p->prev = newnode;
        first = newnode;
        return;
    }
    while (p->next)
    {
        if (p->next->data > x)
        {
            Node *newnode = new Node;
            newnode->data = x;
            newnode->next = p->next;
            newnode->prev = p;
            p->next->prev = newnode;
            p->next = newnode;
            return;
        }
        p = p->next;
    }
    Node *newnode = new Node;
    newnode->data = x;
    newnode->next = NULL;
    newnode->prev = p;
    p->next = newnode;
    return;
}
// create a function to delete an element in the D list by index
int DList::delete_by_index(int pos)
{
    if (pos < 0 || pos >= count())
    {
        cout << "Invalid index" << endl;
        return -1;
    }
    Node *p = first;
    int i = 0;
    if (pos == 0)
    {
        first = p->next;
        if (first)
            first->prev = NULL;
        int x = p->data;
        delete p;
        return x;
    }
    while (p)
    {
        if (i == pos)
        {
            p->prev->next = p->next;
            if (p->next)
                p->next->prev = p->prev;
            int x = p->data;
            delete p;
            return x;
        }
        p = p->next;
        i++;
    }
    return -1;
}
// create a function to delete an element in the D list by value
int DList::delete_by_value(int value)
{
    int i = index(value);
    int gar = delete_by_index(index(value));
    return i;
}
// create a function to check if the D list is sorted or not
int DList::is_sorted()
{
    Node *p = first;
    int x = INT_MIN;
    while (p)
    {
        if (p->data < x)
        {
            return 0;
        }
        x = p->data;
        p = p->next;
    }
    return 1;
}
// create a function to remove duplicates from the D list
void DList::remove_duplicates()
{
    Node *p = first;
    while (p->next)
    {
        if (p->data != p->next->data)
        {
            p = p->next;
        }
        else
        {
            Node *q = p->next;
            p->next = p->next->next;
            if (p->next)
                p->next->prev = p;
            int x = q->data;
            delete q;
        }
    }
    return;
}
// create a function to reverse the D list
void DList::reverse()
{
    Node *p = first;
    if (!p)
        return;
    do
    {
        Node *temp = p->prev;
        p->prev = p->next;
        p->next = temp;
        first = p;
        p = p->prev;
    } while (p);
    return;
}
// create a function to concatenate two D lists
void DList::concatenate(DList *l2)
{
    Node *p = first;
    if (!p)
    {
        first = l2->first;
        return;
    }
    while (p->next)
    {
        p = p->next;
    }
    p->next = l2->first;
    l2->first->prev = p;
    l2->first = NULL;
    return;
}
// create a function to merge two sorted D lists
void DList::merge(DList *l2)
{
    Node *p = first;
    Node *q = l2->first;
    first = NULL;
    Node *last = NULL;
    if (p->data < q->data)
    {
        first = last = p;
        p = p->next;
        first->next = NULL;
    }
    else
    {
        first = last = q;
        q = q->next;
        first->next = NULL;
    }
    while (p && q)
    {
        if (p->data < q->data)
        {
            last->next = p;
            p->prev = last;
            last = p;
            p = p->next;
            last->next = NULL;
        }
        else
        {
            last->next = q;
            q->prev = last;
            last = q;
            q = q->next;
            last->next = NULL;
        }
    }
    if (p)
    {
        last->next = p;
        p->prev = last;
    }
    if (q)
    {
        last->next = q;
        q->prev = last;
    }
    l2->first = NULL;
    return;
}
// create a function to check if the D list is a loop or not
int DList::isLoop()
{
    Node *p = first;
    Node *q = p;
    do
    {
        p = p->next;
        q = q->next;
        q = q ? q->next : q;
    } while (p && q && p != q);
    return p == q ? 1 : 0;
}
int main()
{
    DList l1;
    l1.append(1);
    l1.append(2);
    l1.append(3);
    l1.append(4);
    l1.append(5);
    l1.append(6);
    l1.print();

    DList l2;
    l2.append(1);
    l2.append(2);
    l2.append(3);

    l2.append(4);
    l2.print();
    l1.merge(&l2);
    l1.print();
    // l2.print();

    return 0;
}