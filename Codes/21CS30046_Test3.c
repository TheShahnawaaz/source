/*
Name: SHAHNAWAZ HUSSAIN
Roll no : 21CS30046
Test no : 3
*/
// Adding library to the library
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 50     // Define size for string.
typedef struct node // Declaring structure
{
    char first_name[SIZE]; // For Storing first name
    char last_name[SIZE];  // For Storing  Last name
    struct node *next;     // For storing the address of the next node.
} node;
typedef node *linkedlist;
void swap(char *s1, char *s2) // For swapping names.
{
    char a[SIZE];
    strcpy(a, &*s1);
    strcpy(&*s1, &*s2);
    strcpy(&*s2, a);
}
linkedlist init() // Initialising the linkedlist
{
    linkedlist l;
    l = NULL; // Initialising linkedlist with null pointer.
    return l; // Returning the pointer.
}
int no_of_node(linkedlist l) // Function for Counting the number of node in the linkedlist.
{
    linkedlist ptr = l;
    int count = 0;      // Variable for counting.
    while (ptr != NULL) // Starting Loop till the last node
    {
        count++;
        ptr = ptr->next;
    }
    return count; // Returning the number of nodes.
}
void display(linkedlist l) // Function for displaying the linkedlist
{
    linkedlist ptr = l;
    printf("Linked list: (");
    while (ptr != NULL) // starting Loop till the last node
    {
        printf(" %s %s ,", ptr->first_name, ptr->last_name); // Printing each name.
        ptr = ptr->next;
    }
    printf(")\n");
}
linkedlist insert_middle(linkedlist l, char first[], char last[]) // Function for inserting node at the front
{
    int n = no_of_node(l) / 2;                                   // Storing the index of a middle node.
    linkedlist new = (struct node *)malloc(sizeof(struct node)); // Locate the new node
    linkedlist middle = l;
    strcpy(new->first_name, first); // Putting the data into the node
    strcpy(new->last_name, last);   // Putting the data into the node
    new->next = NULL;
    if (l == NULL) // If the Linked List is empty, then makeing the new node as head
    {
        l = new;
        display(l); // Displaying output
        return l;
    }
    else if (l->next == NULL) // If the Linked List has only one node.Adding new node to the left.
    {
        new->next = l;
        display(new); // Displaying output
        return new;
    }
    else // if a list have more than one node.
    {
        for (int i = 0; i < n - 1; i++) // Finding the location Where the new node is to be added
        {
            middle = middle->next;
        }
        new->next = middle->next;
        middle->next = new;
        display(l); // Displaying the result
        return l;
    }
}
linkedlist delete_middle(linkedlist l) // Function for deleting the note
{
    int n = no_of_node(l) / 2;
    linkedlist middle = l; // Pointer for locating the node to be deleted
    linkedlist prev = l;
    if (l == NULL) // If the Linked List is empty.
    {
        display(l); // Displaying output
        return l;
    }
    else if (l->next == NULL) // If List have only one node.
    {
        l = NULL;
        display(l); // Displaying output
        return l;
    }
    else if (l->next->next == NULL) // If List have only two node.
    {
        l = l->next;
        display(l); // Displaying output
        return l;
    }
    else // If list have more than two node.
    {
        if (no_of_node(l) % 2 != 0) // Adjusting n if it is odd.
        {
            n++;
        }
        for (int i = 0; i < n - 1; i++) // Finding the node to be deleted.
        {
            prev = middle;
            middle = middle->next;
        }
        prev->next = middle->next; // Deleting the node.
        middle->next = NULL;
        free(middle);
        display(l); // Displaying the result
        return l;
    }
}
void sort(linkedlist *l, int key) // Function for sorting with different key.
{
    int n = no_of_node(*l);
    linkedlist a = *l;

    for (int i = 0; i < n; i++) // Using bubble shot
    {
        // Last i elements are already in place.
        linkedlist b = a->next; // Initialising B.
        for (int j = 0; j < n - i - 1; j++)
        {
            if (key == 0) // If Key is equal to 0
            {
                if (strcmp(a->first_name, b->first_name) >= 0) // Checking the condition
                {
                    swap(a->first_name, b->first_name); // Swapping names
                    swap(a->last_name, b->last_name);   // Swapping names
                }
                b = b->next; // Moving B to the next node
            }
            if (key == 1) // If Key is equal to 1
            {
                if (strcmp(a->first_name, b->first_name) < 0) // Checking the condition
                {
                    swap(a->first_name, b->first_name); // Swapping names
                    swap(a->last_name, b->last_name);   // Swapping names
                }
                b = b->next; // Moving B to the next node
            }
            if (key == 2) // If Key is equal to 2
            {
                if (strcmp(a->last_name, b->last_name) >= 0) // Checking the condition
                {
                    swap(a->first_name, b->first_name); // Swapping names
                    swap(a->last_name, b->last_name);   // Swapping names
                }
                b = b->next; // Moving B to the next node
            }
            if (key == 3) // If Key is equal to 3
            {
                if (strcmp(a->last_name, b->last_name) < 0) // Checking the condition
                {
                    swap(a->first_name, b->first_name); // Swapping names
                    swap(a->last_name, b->last_name);   // Swapping names
                }
                b = b->next; // Moving B to the next node
            }
        }
        a = a->next; // Moving A to the next node
    }
    display(*l); // Displaying output.
    return;
}
int main()
{
    linkedlist l;
    l = init();
    printf("1. insert at middle\n"); // Printing the menu
    printf("2. delete from middle\n");
    printf("3. sort in non - decreasing order or first name\n");
    printf("4. sort in non - increasing order or first name\n");
    printf("5. sort in non - decreasing order or last name\n");
    printf("6. sort in non - increasing order or last name\n");
    printf("7. exit\n");
    int avoid_infinite_loop = 30;
    while (avoid_infinite_loop--) // Initializing the loop
    {
        int n;
        scanf("%d", &n); // Taking user's choice
        // Calling respective function in respective case
        if (n == 7) // If else case for menu button
        {
            printf("Program has been ended.....");
            return 0;
        }
        if (n == 1) // In putting in the middle
        {
            char first[SIZE], last[SIZE];
            printf("Write element to be inserted: ");
            scanf("%s %s", first, last);       // Taking names
            l = insert_middle(l, first, last); // Calling respective function
        }
        if (n == 2) // Deleting the middle node
        {
            l = delete_middle(l); // Calling respective function
        }
        if (n >= 3 && n <= 6) // Sorting the list
        {
            sort(&l, n - 3); // Calling respective function
        }
    }
    return 0;
}