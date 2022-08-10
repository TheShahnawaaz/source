#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;
// create a struct for linked list
struct node
{
    int data;
    struct node *next;
};
// create a function to create a linked list
// void create(int A[], int n)
// {
//     struct node *tail = NULL;
//     for (int i = 0; i < n; i++)
//     {
//         struct node *newnode = (struct node *)malloc(sizeof(struct node));
//         newnode->data = A[i];
//         newnode->next = NULL;
//         if (head == NULL)
//         {
//             head = newnode;
//             tail = newnode;
//         }
//         else
//         {
//             tail->next = newnode;
//             tail = newnode;
//         }
//     }
// }
// create a function to print the linked list
void print(struct node *head)
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void display_reverse(struct node *p)
{
    if (p)
    {
        display_reverse(p->next);
        cout << p->data << " ";
    }
}
int count(struct node *p)
{
    int count = 0;
    while (p)
    {
        count++;
        p = p->next;
    }
    return count;
}
int add(struct node *p)
{
    int sum = 0;
    while (p)
    {
        sum += p->data;
        p = p->next;
    }
    return sum;
}
int add_r(struct node *p)
{
    if (!p)
    {
        return 0;
    }
    else
    {
        return p->data + add_r(p->next);
    }
}
int index(struct node *p, int key)
{
    struct node *q = NULL;
    struct node *first = p;
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
int index_r(struct node *p, int key)
{
    if (p == NULL)
    {
        return -1;
    }
    if (p->data == key)
    {
        return 0;
    }
    else
    {
        return index_r(p->next, key) + 1;
    }
}
int get(struct node *p, int index)
{
    if (index < 0 || index >= count(p))
    {
        cout << "Invalid index" << endl;
        return -1;
    }
    struct node *q = NULL;
    struct node *first = p;
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
node *insert(struct node *p, int pos, int x)
{
    if (pos < 0 || pos >= count(p))
    {
        cout << p << count(p) << endl;
        printf("Invalid position\n");
        return p;
    }
    struct node *q = NULL;
    struct node *first = p;
    int i = 0;
    if (pos == 0)
    {
        struct node *newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = x;
        newnode->next = p;
        p = newnode;
        return p;
    }
    while (p)
    {
        if (i == pos - 1)
        {
            struct node *newnode = (struct node *)malloc(sizeof(struct node));
            newnode->data = x;
            newnode->next = p->next;
            p->next = newnode;
            return first;
        }
        q = p;
        p = p->next;
        i++;
    }
    return first;
}
node *sorted_insert(struct node *p, int x)
{
    struct node *q = NULL;
    struct node *first = p;
    if (!p)
    {
        struct node *newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = x;
        newnode->next = NULL;
        return newnode;
    }
    if (p->data > x)
    {
        struct node *newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = x;
        newnode->next = p;
        return newnode;
    }
    while (p)
    {
        if (p->data > x)
        {
            struct node *newnode = (struct node *)malloc(sizeof(struct node));
            newnode->data = x;
            newnode->next = p;
            q->next = newnode;
            return first;
        }
        q = p;
        p = p->next;
    }
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = NULL;
    q->next = newnode;
    return first;
}
node *delete_by_index(struct node *p, int pos)
{
    if (pos < 0 || pos >= count(p))
    {
        printf("Invalid position\n");
        return p;
    }
    struct node *q = NULL;
    struct node *first = p;
    int i = 0;
    if (pos == 0)
    {
        p = p->next;
        free(first);
        return p;
    }
    while (p)
    {
        if (i == pos)
        {
            q->next = p->next;
            free(p);
            return first;
        }
        q = p;
        p = p->next;
        i++;
    }
    return first;
}
node *delete_by_value(struct node *p, int value)
{
    return delete_by_index(p, index(p, value));
}
node *remove_duplicate(struct node *p)
{
    struct node *q = p->next;
    struct node *first = p;
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
    return first;
}
node *reverse(struct node *p)
{
    struct node *q = NULL;
    struct node *r = NULL;
    while (p)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    return q;
}
// node *reverse_recursion(struct node *q, struct node *p)
// {
//     if (p)
//     {
//         reverse_recursion(p, p->next);
//         p->next = q;
//     }
//     else
//     {
//         return q;
//     }
// }
node *concat(struct node *p, struct node *q)
{
    struct node *first = p;
    while (p->next)
    {
        p = p->next;
    }
    p->next = q;
    return first;
}
node *merge(struct node *p, struct node *q)
{
    struct node *first = NULL;
    struct node *last = NULL;
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
    return first;
}
int isLoop(struct node *p)
{
    struct node *q = p;
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
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> A[i];
    // }
    // create(A, n);
    // print(head);
    // display_reverse(head);
    // cout << count(head) << endl;
    // cout << add(head) << endl;
    // cout << add_r(head) << endl;
    // head = search(head, 6);
    // print(head);
    struct node *head1 = NULL;
    struct node *head2 = NULL;
    struct node *head3 = NULL;
    cout << "hello" << endl;

    head1 = sorted_insert(head1, 1);
    head1 = sorted_insert(head1, 2);
    head1 = sorted_insert(head1, 3);
    head1 = sorted_insert(head1, 4);
    head1 = sorted_insert(head1, 6);
    head1 = sorted_insert(head1, 8);
    head1 = sorted_insert(head1, 20);
    head1 = sorted_insert(head1, 30);
    print(head1);
    head1 = remove_duplicate(head1);
    print(head1);
    head2 = sorted_insert(head2, 5);
    head2 = sorted_insert(head2, 18);
    head2 = sorted_insert(head2, 19);
    head2 = sorted_insert(head2, 39);
    head2 = sorted_insert(head2, 36);
    head2 = sorted_insert(head2, 14);
    head2 = remove_duplicate(head2);
    print(head2);
    // head2 = reverse_recursion(NULL, head1);
    head1 = merge(head1, head2);
    print(head1);

    return 0;
}