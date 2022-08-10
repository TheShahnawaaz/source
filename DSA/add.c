#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "library.c"
// create a functon to add two numbers

int main()
{
    int a, b;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);
    printf("The sum of %d and %d is %d", abs(a), abs(b), add(abs(a), abs(b)));
    return 0;
}