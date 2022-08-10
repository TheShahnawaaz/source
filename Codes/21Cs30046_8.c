/*
Name: SHAHNAWAZ HUSSAIN
Roll no : 21CS30046
Experiment no : 8
*/
#include <stdio.h> //Adding library to the program.
#include <math.h>
struct num // Defining the structure.
{
    int Bin[9];  // For storing Binary Representation.
    int sizeBin; // Fou storing the size of Binary representation.
    int Oct[10]; // For storing Octal Representation.
    int sizeOct; // Fou storing the size of Octal representation.
};
void Binary(int a, struct num *A) // Function for calculating and storing binary representation.
{
    int number = abs(a);             // Taking binary representation of the absolute value of the given number.
    for (int i = 0; number > 0; i++) // Code for converting it to a binary number.
    {
        A->Bin[i] = number % 2;
        number = number / 2;
        A->sizeBin = i + 1; // Storing the size of this binary number.
    }
    if (a < 0) // Checking if it is a negative number.
    {
        for (int i = 0; i < A->sizeBin; i++) // Taking 1's complement.
        {
            A->Bin[i] = 1 - A->Bin[i];
        }
    }
}

void Octal(int a, struct num *A) // Function for calculating and storing Octal representation.
{
    int number = abs(a); // Taking Octal representation of the absolute value of the given number.

    for (int i = 0; number > 0; i++) // Code for converting it to a Octal number.
    {
        A->Oct[i] = number % 8;
        number = number / 8;
        A->sizeOct = i + 1; // Storing the size of this Octal number.
    }
    if (a < 0) // Checking if it is a negative number.
    {
        for (int i = 0; i < A->sizeOct; i++) // Taking 7's complement.
        {
            A->Oct[i] = 7 - A->Oct[i];
        }
        int j = -1;
        do // Adding 1 for 8's is compliment.
        {
            j++;
            A->Oct[j]++; // Adding one to the least significant digit.
            if (A->Oct[j] <= 7)
            {
                break;
            }
            else if (A->Oct[j] == 8) // Checking if it needs a carry.
            {
                A->Oct[j] = 0;
            }

        } while (j < A->sizeOct);
    }
}
int main()
{

    struct num A[20][20]; // Declaring 2D array A as Stucture NUM data type.
    int B[20][20];        // Declaring 2D array B as int datatype.
    int m, n;             // Declaring M and N and taking input from user.
    printf("Enter positive integer n less than equal to 20: ");
    scanf("%d", &n);
    printf("Enter positive integer m less than equal to 20: ");
    scanf("%d", &m);
    // Taking as input a decimal integer aij and store in A[i][j] a structure of type num that stores the binary and octal representations of aij.
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int x;
            printf("Enter an integer between -500 and 500 for A[%d][%d]: ", i, j);
            scanf("%d", &x);
            Binary(x, &A[i][j]); // Storing Binary representation of the inputted number.
            Octal(x, &A[i][j]);  // Storing Octal representation of the inputted number.
        }
    }
    printf("The matrix B is as follows: \n"); // Printing rseult of matrix B.
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            B[i][j] = 0;                  // Setting default value of Bij.
            int result1 = 0, result2 = 0; // Variable for checking the condition.
            if (i > A[i][j].sizeBin)      // Checking if i is greater than the size of Binary representation.
            {
                result1 = 1; // Updating result.
            }
            else
            {
                if (A[i][j].Bin[i] == 0) // Checking the desired condition.
                {
                    result1 = 1; // Updating result.
                }
            }
            if (j > A[i][j].sizeOct) // Checking if j is greater than the size of Octal representation.
            {
                result2 = 1; // Updating result.
            }
            else
            {
                if (A[i][j].Oct[j] <= 4) // Checking the desired condition.
                {
                    result2 = 1; // Updating result.
                }
            }
            if (result1 == 1 && result2 == 1) // Checking the Updated results.
            {
                B[i][j] = 1; // Updating the value of Bif If the condition is true.
            }
            printf("%d ", B[i][j]); // Printing the matrix B in this loop only.
            // Adding up new loop for printing the Matrix would just increase the number of lines in the program.
        }
        printf("\n");
    }
    return 0;
}