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
class CList
{
private:
    Node *head;

public:
    // constructor
    CList()
    {
        head = NULL;
    }
    // constructor
    CList(int A[], int n);
    // destructor
    ~CList();
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
    void concatenate(CList *l2);
    // create a function to check if the linked list is a loop or not
    int isLoop();
};
// create a constructor for linked list
CList::CList(int A[], int n)
{
    Node *last, *t;
    int i = 0;
    head = new Node;
    head->data = A[0];
    head->next = NULL;
    last = head;
    for (i = 1; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
    last->next = head;
}
// create a destructor for linked list
CList::~CList()
{
    if (!head)
        return;
    Node *p = head->next;
    for (int i = 0; count() != 0; i++)
    {
        if (head->next == head)
        {
            delete head;
            head = NULL;
            break;
        }
        else
        {
            head->next = p->next;
            delete p;
            p = head->next;
        }
    }
    return;
}
// create a function to display the linked list
void CList::print()
{
    Node *p = head;
    if (!p)
        return;
    do
    {
        cout << p->data << " ";
        p = p->next;
    } while (p != head);
    cout << endl;
    return;
}
// create a function to count the number of nodes in the linked list
int CList::count()
{
    Node *p = head;
    int count = 0;
    if (p == NULL)
    {
        return 0;
    }
    else
    {
        do
        {
            count++;
            p = p->next;
        } while (p != head);
    }
    return count;
}
// create a function to add the elements of the linked list
int CList::add()
{
    Node *p = head;
    int sum = 0;
    while (p != head)
    {
        sum += p->data;
        p = p->next;
    }
    return sum;
}
// create a function to search an element in the linked list
int CList::index(int key)
{
    Node *p = head;
    Node *q = NULL;
    int index = 0;
    if (p == NULL)
    {
        return -1;
    }
    else
    {
        do
        {
            if (p->data == key)
            {
                return index;
            }
            q = p;
            p = p->next;
            index++;
        } while (p != head);
    }
    return -1;
}
// create a function to insert an element in the linked list
void CList::insert(int pos, int x)
{
    Node *p = head;
    if (pos < 0 || pos > count())
    {
        printf("Invalid position\n");
        return;
    }
    Node *q = NULL;
    int i = 0;
    if (pos == 0)
    {
        if (!head)
        {
            head = new Node;
            head->data = x;
            head->next = head;
        }
        else
        {
            while (p->next != head)
            {
                p = p->next;
            }
            p->next = new Node;
            p->next->data = x;
            p->next->next = head;
            head = p->next;
        }
        return;
    }
    do
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
    } while (p != head);
    return;
}
// create a function for acessing an element in the linked list
int CList::get(int index)
{
    if (index < 0 || index >= count())
    {
        cout << "Invalid index" << endl;
        return -1;
    }
    Node *p = head;
    int count = 0;
    do
    {
        if (count == index)
        {
            return p->data;
        }
        p = p->next;
        count++;
    } while (p != head);
    return -1;
}
// create a function to insert an element in the sorted linked list
void CList::sorted_insert(int x)
{
    Node *q = NULL;
    Node *p = head;
    if (!p)
    {
        Node *newnode = new Node;
        newnode->data = x;
        newnode->next = newnode;
        head = newnode;
        return;
    }
    if (p->data > x)
    {
        insert(0, x);
        return;
    }
    do
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
    } while (p != head);
    Node *newnode = new Node;
    newnode->data = x;
    newnode->next = head;
    q->next = newnode;
    return;
}
// create a function to delete an element in the linked list by index
int CList::delete_by_index(int pos)
{
    if (pos < 0 || pos >= count())
    {
        cout << "Invalid index" << endl;
        return -1;
    }
    Node *q = NULL;
    Node *p = head;
    int i = 0;
    if (pos == 0)
    {
        while (p->next != head)
        {
            p = p->next;
        }
        int x = head->data;
        if (p == head)
        {
            delete head;
            head = NULL;
        }
        else
        {
            p->next = head->next;
            delete head;
            head = p->next;
        }
        return x;
    }
    do
    {
        if (i == pos)
        {
            q->next = p->next;
            int x = p->data;
            delete p;
            return x;
        }
        q = p;
        p = p->next;
        i++;
    } while (p != head);
    return -1;
}
// create a function to delete an element in the linked list by value
int CList::delete_by_value(int value)
{
    int i = index(value);
    int gar = delete_by_index(index(value));
    return i;
}
// create a function to check if the linked list is sorted or not
int CList::is_sorted()
{
    Node *p = head;
    int x = INT_MIN;
    if (!p)
    {
        return 1;
    }
    do
    {
        if (p->data < x)
        {
            return 0;
        }
        x = p->data;
        p = p->next;
    } while (p != head);
    return 1;
}
// create a function to remove duplicates from the linked list
void CList::remove_duplicates()
{
    Node *p = head;
    Node *q = p->next;
    if (!p || !q)
    {
        return;
    }
    while (q != head)
    {
        if (p->data != q->data)
        {
            p = q;
            q = q->next;
        }
        else
        {
            p->next = q->next;
            delete q;
            q = p->next;
        }
    }
    return;
}
// create a function to reverse the linked list
void CList::reverse()
{
    Node *p = head;
    Node *q = NULL;
    Node *r = NULL;
    do
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    } while (p != head);
    head->next = q;
    head = q;
    return;
}
// create a function to concatenate two linked lists
void CList::concatenate(CList *l2)
{
    Node *p = head;
    while (p->next != head)
    {
        p = p->next;
    }
    p->next = l2->head;
    do
    {
        p = p->next;
    } while (p->next != l2->head);
    p->next = head;
    l2->head = NULL;
    return;
}
// // create a function to check if the linked list is a loop or not
int CList::isLoop()
{
    Node *p = head;
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
    CList l;
    l.sorted_insert(10);
    l.sorted_insert(20);
    l.sorted_insert(30);
    l.sorted_insert(1);
    l.sorted_insert(2);
    l.sorted_insert(30);
    l.sorted_insert(2);
    l.sorted_insert(2);
    l.print();
    cout << l.get(4) << endl;
    return 0;
}