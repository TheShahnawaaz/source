/*
Name: SHAHNAWAZ HUSSAIN
Roll no : 21CS30046
Assignment no : 7
*/
// Adding library to the library
#include <stdio.h>
#include <math.h>
int isPrime(int number) // Function for checking prime number.
{
    static int temp = 2; // Declaring static variable for recurssion.
    int result = 0;
    if (temp > sqrt(number)) // Checking the condition for prime number.
    {
        temp = 2; // Resetting temp before returning for re-using the function.
        return 1; // Returning the result.
    }

    if (number % temp != 0) // Checking if divisible by temp or not
    {
        temp++;
        result = isPrime(number); // Recalling the function.
    }
    temp = 2;      // Resetting temp before returning for re-using the function.
    return result; // Returning the result.
}

int properDivisor(int number) // Function for printing proper divisor and returning the sum of it.
{
    static int i = 1;   // Declaring static variable for recurssion.
    static int sum = 0; // Declaring static variable for Storing the value of sum.
    if (i > number / 2) // Terminating condition for recursion.
    {
        return i; // Returning random values to the garbage variable as function is int type.
    }
    if (number % i == 0) // Checking if i is a factor of the number.
    {
        printf(" %d,", i); // Printing all divisors.
        sum = sum + i;     // Adding i to the sum.
    }
    i++;
    int garbage = properDivisor(number); // Recalling the function.
    return sum;                          // Returning the sum.
}
void PrimeOrComposite(int number) // Function for telling the user that a number is prime or composite.
{
    if (isPrime(number)) // Checking if it is a prime Number.
    {
        printf("\n%d  is a PRIME number.\n", number); // Printing for prime number
    }
    else
    {
        printf("\n%d  is a COMPOSITE number.\n", number); // Else Printing for composite numbers
    }
}
void BeautifulNumber(int number, int sum) // Function for checking if it is a beautiful number.
{
    if (number == sum) // Checking the condition for beautiful number.
    {
        printf("%d is a Beautiful number.\n", number); // Printing that it is a beautiful number.
    }
    else
    {
        printf("%d is NOT a Beautiful number.\n", number); // Else painting that it is not a beautiful number.
    }
    return;
}
int main()

{
    int n;
    printf("Write n: "); // Taking input from user.
    scanf("%d", &n);
    printf("The Proper divisors of %d are", n); // Printing all the proper divisor of n.
    int sum = properDivisor(n);
    PrimeOrComposite(n);     // Checking whether it is a prime or a composite number.
    BeautifulNumber(n, sum); // Checking whether it is a beautiful number.
    return 0;
}