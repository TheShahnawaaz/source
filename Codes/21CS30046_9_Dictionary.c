/*
Name: SHAHNAWAZ HUSSAIN
Roll no : 21CS30046
Assignment no : 9
*/
// Adding library to the library
#include <stdio.h>
#include <math.h>
struct Name // Defining the structure for Name.
{
    char FirstName[50];
    char SurName[50];
};
void DisplayName(char *First) // Function for printing Both last and first name in one line.
{
    char *p = First; // Initialising pointer p with the address of first element of firstname.
    for (int i = 0; *p != '\0'; i++, p++)
    {
        printf("%c", *p);
    }
    printf(" ");
    p = First + 50; // Initialising pointer p with the address of first element of Surname.
    ;
    for (int i = 0; *p != '\0'; i++, p++)
    {
        printf("%c", *p);
    }
    printf("\n");
}
void SwapName(struct Name *x, struct Name *y) // Function for swapping the name structure.
{
    struct Name temp = *x; // Swapping the Array.
    *x = *y;
    *y = temp;
}
void SortedByFirstName(struct Name a[10]) // Function for sorting the name array by first name.
{
    for (int i = 0; i < 10; i++)
    {
        // Last i name are already in place.
        for (int j = 0; j < 9 - i; j++)
        {
            for (int k = 50; k >= 0; k--) // Loop for checking each letter of the name.
            {
                // Note:K loop is started from last letter as first letter is given most priority.
                // First if condition is for checking that there exist a letter.
                if (((a[j].FirstName[k] >= 'a' && a[j].FirstName[k] <= 'z') || (a[j].FirstName[k] >= 'A' && a[j].FirstName[k] <= 'Z')) && ((a[j + 1].FirstName[k] >= 'a' && a[j + 1].FirstName[k] <= 'z') || (a[j + 1].FirstName[k] >= 'A' && a[j + 1].FirstName[k] <= 'Z')))
                {
                    if (a[j].FirstName[k] > a[j + 1].FirstName[k]) // Checking if they are in correct order according to dictionary or not.
                    {
                        SwapName(&a[j], &a[j + 1]); // Swapping adjacent name if they are wrongly placed.
                    }
                }
            }
        }
    }
}
void SortedBySurName(struct Name a[10]) // Function for sorting the name array by Surname.
{
    for (int i = 0; i < 10; i++)
    {
        // Last i name are already in place.
        for (int j = 0; j < 9 - i; j++)
        {
            for (int k = 50; k >= 0; k--) // Loop for checking each letter of the name.
            {
                // Note : K loop is started from last letter as first letter is given most priority.
                // First if condition is for checking that there exist a letter.
                if ((a[j].SurName[k] >= 'a' && a[j].SurName[k] <= 'z') || (a[j].SurName[k] >= 'A' && a[j].SurName[k] <= 'Z') && (a[j + 1].SurName[k] >= 'a' && a[j + 1].SurName[k] <= 'z') || (a[j + 1].SurName[k] >= 'A' && a[j + 1].SurName[k] <= 'Z'))
                {
                    if (a[j].SurName[k] > a[j + 1].SurName[k]) // Checking if they are in correct order according to dictionary or not.
                    {
                        SwapName(&a[j], &a[j + 1]); // Swapping adjacent name if they are wrongly placed.
                    }
                }
            }
        }
    }
}

int main()

{
    struct Name a[10]; // Initialising name structure for storing 10 names.
    printf("Write 10 names\n");
    for (int i = 0; i < 10; i++) // Taking Names from the user.
    {
        scanf("%s", a[i].FirstName);
        scanf("%s", a[i].SurName);
    }
    SortedByFirstName(a);                            // Sorting array by Firstname.
    printf("\n\nSorted according to first name:\n"); // Printing the sorter Name list.
    for (int i = 0; i < 10; i++)                     // Loop for printing each name.
    {
        DisplayName(a[i].FirstName);
    }
    SortedBySurName(a); // Sorting array by Surname.
    printf("\n\nSorted according to last name:\n");
    for (int i = 0; i < 10; i++) // Loop for printing each name.
    {
        DisplayName(a[i].FirstName);
    }

    return 0;
}