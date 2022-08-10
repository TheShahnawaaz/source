#include <iostream>
using namespace std;
// create a class for node
class Node
{
public:
    int data;
    Node *next;
};
// Create a class for linked list
class LinkedList
{
private:
    Node *first;

public:
    // constructor
    LinkedList()
    {
        first = NULL;
    }
    // constructor
    LinkedList(int A[], int n);
    // destructor
    ~LinkedList();
    // create a function to display the linked list
    void print();
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
    void concatenate(LinkedList *l2);
    // create a function to merge two sorted linked lists
    void merge(LinkedList *l2);
    // create a function to check if the linked list is a loop or not
    int isLoop();
};
// create a constructor for linked list
LinkedList::LinkedList(int A[], int n)
{
    Node *last, *t;
    int i = 0;
    first = new Node;
    first->data = A[0];
    first->next = NULL;
    last = first;
    for (i = 1; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}
// create a destructor for linked list
LinkedList::~LinkedList()
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
// create a function to display the linked list
void LinkedList::print()
{
    Node *p = first;
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}
// create a function to count the number of nodes in the linked list
int LinkedList::count()
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
// create a function to add the elements of the linked list
int LinkedList::add()
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
// create a function to search an element in the linked list
int LinkedList::index(int key)
{
    Node *p = first;
    Node *q = NULL;
    int index = 0;
    while (p)
    {
        if (p->data == key)
        {
            return index;
        }
        q = p;
        p = p->next;
        index++;
    }
    return -1;
}
// create a function to insert an element in the linked list
void LinkedList::insert(int pos, int x)
{
    Node *p = first;
    if (pos < 0 || pos > count())
    {
        printf("Invalid position\n");
        return;
    }
    Node *q = NULL;
    int i = 0;
    if (pos == 0)
    {
        Node *newnode = new Node;
        newnode->data = x;
        newnode->next = p;
        p = newnode;
        first = p;
        return;
    }
    while (p)
    {
        if (i == pos - 1)
        {
            Node *newnode = new Node;
            newnode->data = x;
            newnode->next = p->next;
            p->next = newnode;
            return;
        }
        q = p;
        p = p->next;
        i++;
    }
    return;
}
// create a function for acessing an element in the linked list
int LinkedList::get(int index)
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
// create a function to insert an element in the sorted linked list
void LinkedList::sorted_insert(int x)
{
    Node *q = NULL;
    Node *p = first;
    if (!p)
    {
        Node *newnode = new Node;
        newnode->data = x;
        newnode->next = NULL;
        first = newnode;
        return;
    }
    if (p->data > x)
    {
        Node *newnode = new Node;
        newnode->data = x;
        newnode->next = p;
        first = newnode;
        return;
    }
    while (p)
    {
        if (p->data > x)
        {
            Node *newnode = new Node;
            newnode->data = x;
            newnode->next = p;
            q->next = newnode;
            return;
        }
        q = p;
        p = p->next;
    }
    Node *newnode = new Node;
    newnode->data = x;
    newnode->next = NULL;
    q->next = newnode;
    return;
}
// create a function to delete an element in the linked list by index
int LinkedList::delete_by_index(int pos)
{
    if (pos < 0 || pos >= count())
    {
        cout << "Invalid index" << endl;
        return -1;
    }
    Node *q = NULL;
    Node *p = first;
    int i = 0;
    if (pos == 0)
    {
        first = p->next;
        int x = p->data;
        delete p;
        return x;
    }
    while (p)
    {
        if (i == pos)
        {
            q->next = p->next;
            int x = p->data;
            free(p);
            return x;
        }
        q = p;
        p = p->next;
        i++;
    }
    return -1;
}
// create a function to delete an element in the linked list by value
int LinkedList::delete_by_value(int value)
{
    int i = index(value);
    int gar = delete_by_index(index(value));
    return i;
}
// create a function to check if the linked list is sorted or not
int LinkedList::is_sorted()
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
// create a function to remove duplicates from the linked list
void LinkedList::remove_duplicates()
{
    Node *p = first;
    Node *q = p->next;
    while (q)
    {
        if (p->data != q->data)
        {
            p = q;
            q = q->next;
        }
        else
        {
            p->next = q->next;
            free(q);
            q = p->next;
        }
    }
    return;
}
// create a function to reverse the linked list
void LinkedList::reverse()
{
    Node *p = first;
    Node *q = NULL;
    Node *r = NULL;
    while (p)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
    return;
}
// create a function to concatenate two linked lists
void LinkedList::concatenate(LinkedList *l2)
{
    Node *p = first;
    while (p->next)
    {
        p = p->next;
    }
    p->next = l2->first;
    l2->first = NULL;
    return;
}
// create a function to merge two sorted linked lists
void LinkedList::merge(LinkedList *l2)
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
            last = p;
            p = p->next;
            last->next = NULL;
        }
        else
        {
            last->next = q;
            last = q;
            q = q->next;
            last->next = NULL;
        }
    }
    if (p)
    {
        last->next = p;
    }
    if (q)
    {
        last->next = q;
    }
    l2->first = NULL;
    return;
}
// create a function to check if the linked list is a loop or not
int LinkedList::isLoop()
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
    LinkedList l1;
    l1.sorted_insert(6);
    l1.print();
    l1.sorted_insert(5);
    l1.print();
    l1.sorted_insert(3);
    l1.print();
    l1.sorted_insert(2);
    l1.print();
    l1.sorted_insert(4);
    l1.print();
    l1.sorted_insert(5);
    l1.print();
    l1.sorted_insert(3);
    l1.print();
    l1.sorted_insert(3);
    l1.print();
    // l1.print();
    l1.remove_duplicates();
    l1.print();
    LinkedList l2;
    l2.sorted_insert(5);
    l2.print();
    l2.sorted_insert(4);
    l2.print();
    l2.sorted_insert(3);
    l2.print();
    l2.sorted_insert(2);
    l2.print();
    l2.sorted_insert(1);
    l2.print();
    l2.sorted_insert(11);
    l2.print();
    l1.concatenate(&l2);
    l1.print();
    l2.print();

    return 0;
}