/*
Name: SHAHNAWAZ HUSSAIN
Roll no : 21CS30046
Experiment no : 5
*/
// Adding library to the Program.
#include <stdio.h>
#include <math.h>

int main()
{
    int n, m, A[25], B[25], C[25], D[25]; // Declaring variables and arrays.

    /*Taking input from the user*/

    printf("Enter positive integer n: ");
    scanf("%d", &n);
    printf("Enter positive integer m: ");
    scanf("%d", &m);
    printf("Enter %d positive integers for array A: ", n);
    for (int i = 0, temp; i < n; i = i + 1)
    {
        scanf("%d", &A[i]);
    }
    printf("Enter %d positive integers for array B: ", m);
    for (int i = 0, temp; i < m; i = i + 1)
    {
        scanf("%d", &B[i]);
    }

    /*Adding distinct integer from A and B to C.*/

    int l = 0; // Declared l for calculating number of distinct integers in array C.
    C[0] = 0;

    for (int i = 0; i < n; i++)
    {
        if (A[i] % 2 == 0) // Checking for even numbers in A.
        {
            int val = 0, count = 0;
            for (int j = 0; j <= l; j++)
            {
                if (A[i] == C[j]) // Checking if this number already exists in the array C.
                {
                    val = 1;
                    D[j]++; // Counting the frequency of each the number.
                }
            }
            if (val == 0)
            {
                C[l] = A[i]; // Adding new number if it doesn't already exist in the array C.
                D[l] = 1;
                l++;
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        if (B[i] % 2 == 0) // Checking for even numbers in B.
        {
            int val = 0, count = 0;
            for (int j = 0; j <= l; j++)
            {
                if (B[i] == C[j]) // Checking if this number already exists in the array C.
                {
                    val = 1;
                    D[j]++; // Counting the frequency of each the number.
                }
            }
            if (val == 0)
            {
                C[l] = B[i]; // Adding new number if it doesn't already exist in the array C.
                D[l] = 1;
                l++;
            }
        }
    }
    int n1 = l; // Declared n1 for calculating number of even integers in array C.

    for (int i = 0; i < n; i++)
    {
        if (A[i] % 2 != 0) // Checking for odd number in A.
        {
            int val = 0, count = 0;
            for (int j = 0; j <= l; j++)
            {
                if (A[i] == C[j]) // Checking if this number already exists in the array C.
                {
                    val = 1;
                    D[j]++; // Counting the frequency of each the number.
                }
            }
            if (val == 0)
            {
                C[l] = A[i]; // Adding new number if it doesn't already exist in the array C.
                D[l] = 1;
                l++;
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        if (B[i] % 2 != 0) // Checking for odd number in B.
        {
            int val = 0, count = 0;
            for (int j = 0; j <= l; j++)
            {
                if (B[i] == C[j]) // Checking if this number already exists in the array C.
                {
                    val = 1;
                    D[j]++; // Counting the frequency of each the number.
                }
            }
            if (val == 0)
            {
                C[l] = B[i]; // Adding new number if it doesn't already exist in the array C.
                D[l] = 1;
                l++;
            }
        }
    }

    /*
    printf("The required set of the distinct numbers of A and B are (unsorted): \n");
    for (int i = 0; i < l; i++)
    {
        printf("%d  (%d)\n", C[i], D[i]);
    }
    */

    /*Sorting of all even numbers begins.*/

    int j = 0, temp, tempD;
    for (int i = 0; i <= n1 - 1; i++)
    {
        int min = 2147483646;
        for (j = i; j <= n1 - 1; j++)
        {
            if (C[j] < min) // Searching for the smallest number.
            {
                min = C[j];
                temp = j;
            }
        }
        tempD = D[temp]; // Swapping that Smallest number.
        C[temp] = C[i];
        D[temp] = D[i];
        C[i] = min;
        D[i] = tempD;
    }

    /*Sorting of all odd numbers begins.*/

    for (int i = l - 1; i >= n1; i--)
    {
        int min = 2147483646;
        for (j = i; j >= n1; j--)
        {
            if (C[j] < min) // Searching for the smallest number.
            {
                min = C[j];
                temp = j;
            }
        }
        tempD = D[temp]; // Swapping that Smallest number.
        C[temp] = C[i];
        D[temp] = D[i];
        C[i] = min;
        D[i] = tempD;
    }

    /*Printing the required sorting numbers*/

    printf("The required sorting of the distinct numbers of A and B are: \n");
    for (int i = 0; i < l; i++)
    {
        printf("%d  (%d)\n", C[i], D[i]);
    }

    return 0;
}