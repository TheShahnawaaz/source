/*
Name: SHAHNAWAZ HUSSAIN
Roll no : 21CS30046
Assignment no : 11
*/
// Adding library to the library
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
typedef struct node // Defining the node
{
    int data;
    struct node *next;
} node;
typedef node *linkedlist;
void init(linkedlist *l) // Initialising the linkedlist
{
    *l = NULL;
}
void display(linkedlist l) // Function for displaying the linkedlist
{
    linkedlist ptr = l;
    while (ptr != NULL) // starting Loop till the last node
    {

        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}
void insert_front(linkedlist *l, int x) // Function for inserting node at the front
{
    linkedlist new = (struct node *)malloc(sizeof(struct node)); // Locate the new node
    linkedlist last = *l;
    new->data = x;    // Putting the data into the node
    new->next = NULL; // This new node is going to be the last node, so make next of it as NULL
    if (*l == NULL)   // If the Linked List is empty, then makeing the new node as head
    {
        printf("1st\n");
        *l = new;
        display(*l); // Displaying output

        return;
    }
    while (last->next != NULL) // Else traverse till the last node
    {
        last = last->next;
    }
    last->next = new;
    display(*l); // Displaying the result
    return;
}
void delete_front(linkedlist *l) // Function for deleting the note
{
    linkedlist last = *l;
    if ((*l) == NULL) // if not initialised
    {
        *l = NULL;
    }
    else if ((*l)->next == NULL) // if it had only one node
    {
        *l = NULL;
    }
    else
    {
        printf("DElete\n");
        while (last->next->next != NULL) // Finding the last note
        {
            printf("%d\n", last->data);
            last = last->next;
        }
        printf("%d\n", last->data);

        last->next = NULL;
        display(*l); // Displaying output
    }
}

void reverse(linkedlist *l) // Function for reversing the linked list
{
    linkedlist previous = NULL;
    linkedlist current = *l;
    linkedlist next = NULL;
    while (current != NULL)
    {
        next = current->next;     // Store next
        current->next = previous; // Reverse current node's pointer
        previous = current;       // Move pointers one position ahead.
        current = next;
    }
    *l = previous;
    display(*l); // Displaying output
}
void display_backward(linkedlist l)
{
    if (l->next == NULL)
    {
        printf("%d ", l->data);
        return;
    }
    else
    {
        display_backward(l->next);
        printf("%d ", l->data);
        return;
    }
}
void delete_max(linkedlist *l)
{
    int max = 0;
    linkedlist p = *l;
    linkedlist q = p;
    if (p->next == NULL)
    {
        free(p);
        p = NULL;
    }

    while (p != NULL)
    {
        if (p->data > max)
        {
            max = p->data;
            q = p;
            p = p->next;
        }
        else
        {
            p = p->next;
        }
    }
    p = *l;
    while (p->next != q)
    {
        p = p->next;
    }
    p->next = q->next;
    q->next = NULL;
    free(q);
    display(*l);
}
int main()
{
    linkedlist l;

    init(&l);
    // if (l == NULL)
    // {
    //     printf("*****\n");
    // }
    // insert_front(&l, 15);
    // // display(l);
    // insert_front(&l, 525);
    // insert_front(&l, 545);
    // insert_front(&l, 865);
    // insert_front(&l, 86);
    // insert_front(&l, 78);
    // display_backward(l);
    // display(l);
    while (1)
    {
        int n;
        // Printing the menu
        printf("\n0-exit\n1-insert_front\n2-delete_front\n3-display\n4-reverse\n5-display_backward\n6-delete_max\nWhat do you want to do?\nEnter a number between 0-4 : ");
        scanf("%d", &n);
        // Calling respective function in respective case
        if (n == 0) // If else case for menu button
        {
            printf("Program has been ended.....");
            return 0;
        }
        if (n == 1)
        {
            int x;
            printf("Enter the number you want to insert : ");
            scanf("%d", &x);
            printf("insert_front : ");
            insert_front(&l, x);
        }
        if (n == 2)
        {
            printf("delete_front : ");
            delete_front(&l);
        }
        if (n == 3)
        {
            printf("display : ");

            display(l);
        }
        if (n == 4)
        {
            printf("reverse : ");
            reverse(&l);
        }
        if (n == 5)
        {
            printf("display_backward : ");
            display_backward(l);
        }
        if (n == 6)
        {
            printf("delete_max : ");
            delete_max(&l);
        }
    }
    return 0;
}