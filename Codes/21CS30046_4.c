/*
Name: SHAHNAWAZ HUSSAIN
Roll no : 21CS30046
Experiment no : 4
*/
// Adding library to the library

#include <stdio.h>
#include <math.h>
int main()
{

    // First Queation
    // Declaring variable
    int number1, remainder, iitnum = 0, n, num1duplicate;
    printf("Enter the numer x : "); // Taking input
    scanf("%d", &number1);
    num1duplicate = number1;
    for (int i = 1; number1 != 0; i++) // first loop
    {
        remainder = number1 % 10;
        int fact = 1;
        for (int j = 1; j <= remainder; j++) // second loop
        {
            fact = fact * j;
        }

        iitnum = iitnum + fact;
        number1 = number1 / 10;
    }
    if (iitnum == num1duplicate) // Checking condition
    {
        printf("Yes, %d is an IIT number.", num1duplicate);
    }
    else
    {
        printf("No, %d is not an IIT number.", num1duplicate);
    }

    int num2 = 1, rem2, iitnum2, num2duplicate = 1;
    printf("\nEnter the numer n : ");
    scanf("%d", &n);
    printf("IIT number between 1 and %d are ", n);

    for (int k = 1; k <= n; k++)
    {
        iitnum = 0;
        number1 = k;

        num1duplicate = number1;
        for (int i = 1; number1 != 0; i++)
        {
            remainder = number1 % 10;
            int fact = 1;
            for (int j = 1; j <= remainder; j++)
            {
                fact = fact * j;
            }

            iitnum = iitnum + fact;
            number1 = number1 / 10;
        }
        if (iitnum == num1duplicate)
        {
            printf(" %d ,", num1duplicate);
        }
    }

    // Second Queation

    int kgp, sum2 = 0;

    printf("Write number x: ");
    scanf("%d", &kgp);

    for (int i = 1; i < kgp; ++i) // outer loop
    {
        if (fmod(kgp, i) == 0) // inner loop
        {
            sum2 += i;
        }
    }

    if (sum2 == kgp) // Checking if number is KGP number
    {
        printf("%d is a KGP number\n", kgp);
    }
    else
    {
        printf("%d is not a KGP number\n", kgp);
    }

    int p, sum2b = 0;

    printf("Write number n: "); // taking in n
    scanf("%d", &n);

    printf("The KGP numbers between 1 and %d are:", n);

    for (p = 1; p <= n; ++p) // outer loop from 1 to n
    {
        sum2b = 0;

        for (int i = 1; i < p; ++i)
        {
            if (fmod(p, i) == 0)
                sum2b += i;
        }

        if (sum2b == p) // prints every number that is a KGP number
        {
            printf(" %d,", p);
        }
    }

    
    //Third Question

    int x, y, rows;
    printf("\nWrite number n: ");
    scanf("%d", &rows);
    for (x = rows; x >= 1; --x)
    {
        for (y = 1; y <= x; ++y)
        {
            printf("* ");
        }
        printf("\n");
    }

    int m;
    for (m = 2; m <= rows; ++m)
    {
        for (n = 1; n <= m; ++n)
        {
            printf("* ");
        }
        printf("\n");
    }
    return 0;
}