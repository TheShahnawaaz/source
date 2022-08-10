// code for printing
//  1
//  0 1
//  1 0 1
//  0 1 0 1
//  1 0 1 0 1
#include <stdio.h>
#include <math.h>
int main()
{
    int n;
    scanf("%d", &n);
    int i, j;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= i; j++)
        {
            if (j % 2 != 0 && i % 2 != 0)// both odd
                printf("1 ");
            else
            {
                if (i % 2 == 0 && j % 2 == 0)// both even
                    printf("1 ");
                else
                    printf("0 ");
            }
        }
        printf("\n");
    }
    return 0;
}