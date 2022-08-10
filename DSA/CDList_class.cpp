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
class CDList
{
private:
    Node *head;

public:
    // constructor
    CDList()
    {
        head = NULL;
    }
    // constructor
    CDList(int A[], int n);
    // destructor
    ~CDList();
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
    void concatenate(CDList *l2);
    // create a function to check if the linked list is a loop or not
    int isLoop();
};
// create a constructor for linked list
CDList::CDList(int A[], int n)
{
    Node *last, *t;
    int i = 0;
    head = new Node;
    head->data = A[0];
    head->next = head;
    head->prev = head;
    last = head;
    for (i = 1; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        t->prev = last;
        last = t;
    }
    last->next = head;
    head->prev = last;
}
// create a destructor for linked list
CDList::~CDList()
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
void CDList::print()
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
// Prints the linked list in reverse order
void CDList::print_reverse()
{
    Node *p = head;
    while (p->next != head)
        p = p->next;
    do
    {
        cout << p->data << " ";
        p = p->prev;
    } while (p->next != head);
    cout << endl;
}
// create a function to count the number of nodes in the linked list
int CDList::count()
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
int CDList::add()
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
int CDList::index(int key)
{
    Node *p = head;
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
            p = p->next;
            index++;
        } while (p != head);
    }
    return -1;
}
// create a function to insert an element in the linked list
void CDList::insert(int pos, int x)
{
    Node *p = head;
    if (pos < 0 || pos > count())
    {
        printf("Invalid position\n");
        return;
    }
    int i = 0;
    if (pos == 0)
    {
        if (!head)
        {
            head = new Node;
            head->data = x;
            head->next = head;
            head->prev = head;
        }
        else
        {
            p = p->prev;
            p->next = new Node;
            p->next->data = x;
            p->next->next = head;
            p->next->prev = p;
            head->prev = p->next;
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
            newnode->prev = p;
            p->next->prev = newnode;
            p->next = newnode;
            return;
        }
        p = p->next;
        i++;
    } while (p != head);
    return;
}
// create a function for acessing an element in the linked list
int CDList::get(int index)
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
void CDList::sorted_insert(int x)
{
    Node *p = head;
    if (!p)
    {
        Node *newnode = new Node;
        newnode->data = x;
        newnode->next = newnode;
        newnode->prev = newnode;
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
            newnode->prev = p->prev;
            p->prev->next = newnode;
            p->prev = newnode;
            return;
        }
        p = p->next;
    } while (p != head);
    Node *newnode = new Node;
    newnode->data = x;
    newnode->next = head;
    newnode->prev = head->prev;
    head->prev->next = newnode;
    head->prev = newnode;
    return;
}
// create a function to delete an element in the linked list by index
int CDList::delete_by_index(int pos)
{
    if (pos < 0 || pos >= count())
    {
        cout << "Invalid index" << endl;
        return -1;
    }
    Node *p = head;
    int i = 0;
    if (pos == 0)
    {
        p = p->prev;
        int x = head->data;
        if (p == head)
        {
            delete head;
            head = NULL;
        }
        else
        {
            p->next = head->next;
            head->next->prev = p;
            delete head;
            head = p->next;
        }
        return x;
    }
    do
    {
        if (i == pos)
        {
            p->prev->next = p->next;
            p->next->prev = p->prev;
            int x = p->data;
            delete p;
            return x;
        }
        p = p->next;
        i++;
    } while (p != head);
    return -1;
}
// create a function to delete an element in the linked list by value
int CDList::delete_by_value(int value)
{
    int i = index(value);
    int gar = delete_by_index(index(value));
    return i;
}
// create a function to check if the linked list is sorted or not
int CDList::is_sorted()
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
void CDList::remove_duplicates()
{
    Node *p = head;
    if (!p || !p->next)
    {
        return;
    }
    while (p->next != head)
    {
        if (p->data != p->next->data)
        {
            p = p->next;
        }
        else
        {
            p->next = p->next->next;
            delete p->next->prev;
            p->next->prev = p;
        }
    }
    return;
}
// create a function to reverse the linked list
void CDList::reverse()
{
    Node *p = head;
    if (!p)
        return;
    do
    {
        Node *temp = p->prev;
        p->prev = p->next;
        p->next = temp;
        p = p->prev;
    } while (p != head);
    head = p->next;
    return;
}
// create a function to concatenate two linked lists
void CDList::concatenate(CDList *l2)
{
    Node *p = head;
    if (!p)
    {
        head = l2->head;
        return;
    }
    while (p->next != head)
    {
        p = p->next;
    }
    p->next = l2->head;
    l2->head->prev->next = head;
    head->prev = l2->head->prev;
    l2->head->prev = p;
    l2->head = NULL;
    return;
}
// // create a function to check if the linked list is a loop or not
int CDList::isLoop()
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
    CDList l;
    l.sorted_insert(10);
    l.sorted_insert(20);
    l.sorted_insert(2);
    l.sorted_insert(30);
    l.sorted_insert(2);
    l.sorted_insert(2);
    l.insert(7, 88);
    l.print();
    cout << l.count() << " " << l.get(3) << " " << l.add() << " " << l.index(88) << endl;
    l.print();
    l.remove_duplicates();
    l.delete_by_value(20);
    l.print();
    cout << l.isLoop();
    return 0;
}