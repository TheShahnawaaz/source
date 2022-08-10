/*
Name: SHAHNAWAZ HUSSAIN
Roll no : 21CS30046
Assignment no : 6
*/
// Adding library to the library
#include <stdio.h>
#include <math.h>
int digits(int num) // Function for returning digits of a number.
{
    int count = 0;
    for (int i = 0; num != 0; i++)
    {
        num = num / 10;
        count++; // Counting digits.
    }
    return count;
}

void swap(int *xp, int *yp) // Function for swapping to integer value through call by reference.
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void sortArray(int Array[50], int n) // Function for sorting an array in descending order.
{
    for (int i = 0; i < n; i++) // Using bubble sort.
    {
        // Last i elements are already in place.
        for (int j = 0; j < n - i - 1; j++)
        {
            if (Array[j] < Array[j + 1])
            {
                swap(&Array[j], &Array[j + 1]);
            }
        }
    }
}

int isFascinating(int num) // Function for detecting fascinating number
{
    if (digits(num) < 3) // A number can't be a fascinating number if its number of digits are less than 3.
    {
        return 0;
    }
    int sample[9] = {9, 8, 7, 6, 5, 4, 3, 2, 1}, Arr[20], index = 0, n; // Initialising sample array for matching with the array.
    for (int i = 0; i < 3; i++)                                         // Taking digits into the array.
    {
        int temp;
        temp = num * (i + 1);
        n = digits(temp);
        for (int i = 0; i < n; i++)
        {
            Arr[index] = temp % 10;
            index++;
            temp = temp / 10;
        }
    }
    sortArray(Arr, index); // Shorting the array

    int result = 1;
    for (int i = 0; i < 9; i++) // Checking whether it's match the condition or not.
    {
        if (Arr[i] != sample[i])
        {
            result = 0;
        }
    }

    return result;
}
int isArmstrong(int num) // Function for detecting Armstrong number
{
    int n, sum = 0, temp, result = 0;
    n = digits(num);
    temp = num;
    for (int i = 0; i < n; i++) // Using loop for every digit.
    {
        sum += pow(temp % 10, n);
        temp = temp / 10;
    }
    if (sum == num) // Checking the condition.
    {
        result = 1;
    }
    return result;
}
int main()
{
    int a, b, c;
    printf("Enter a : "); // Taking the range from the user
    scanf("%d", &a);
    printf("Enter b : ");
    scanf("%d", &b);
    if (a > b) // Swapping a and b if a is not smaller than b.
    {
        swap(&a, &b);
    }
    while (1) // Starting the program.
    {
        printf("What do you want to print :\n1:Fascinating Numbers\n2:Armstrong Numbers\n3:Both Fascinating and Armstrong Numbers\n4:Exit\nChoose a number from 1 to 4 :");
        scanf("%d", &c); // Displaying options to the user.
        switch (c)       // Printing output as users choice.
        {
        case 1: // Printing all fascinating numbers
            for (int i = a; i <= b; i++)
            {
                if (isFascinating(i) == 1) // Checking if i is a fascinating number.
                {
                    printf("%d ,", i);
                }
            }
            printf(" are All Fascinating number between %d and %d.\n", a, b);

            printf("Number which are between %d and %d and not printed here are not a Fascinating Number.\n", a, b);
            break;
        case 2: // Printing all Armstrong numbers
            for (int i = a; i <= b; i++)
            {
                if (isArmstrong(i) == 1) // Checking if i is Armstrong number.
                {
                    printf("%d ,", i);
                }
            }
            printf(" are All Armstrong number between %d and %d.\n", a, b);

            printf("Number which are between %d and %d and not printed here are not a Armstrong Number.\n", a, b);
            break;
        case 3: // Printing all Armstrong and fascinating number.
            printf("List of All Fascinating and Armstrong number between %d and %d are as follows :\n", a, b);
            for (int i = a; i <= b; i++)
            {
                // Checking condition for each Option.
                if (isArmstrong(i) == 1 && isFascinating(i) == 1)
                {
                    printf("%d is both a Fascinating and a Armstrong Number Too.\n", i);
                }
                else if (isArmstrong(i) == 1)
                {
                    printf("%d is a Armstrong Number.\n", i);
                }
                else if (isFascinating(i) == 1)
                {
                    printf("%d is a Fascinating Number.\n", i);
                }
            }
            printf("Number which are between %d and %d and not printed here are neither Fascinating nor Armstrong Number.\n", a, b);

            break;

        default:
            break;
        }
        if (c == 4) // Checking if user want to exit the program.
        {
            printf("Exiting Program !!....");
            break; // Coming out from while loop.
        }
    }

    return 0;
}

