#include <stdio.h>
#include <math.h>
int main()
{
    int n, m, x[25], y[25];
    printf("Enter a number n : ");
    scanf("%d", &n);
    printf("Enter a number m : ");
    scanf("%d", &m);
    printf("Enter %d numbers : \n", n);
    for (int i = 0, temp; i < n; i = i + 1)
    {
        scanf("%d", &x[i]);
    }
    printf("Enter %d numbers : \n", m);

    for (int i = 0, temp; i < m; i = i + 1)
    {
        scanf("%d", &y[i]);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < m; k++)
            {
                if (x[i] + x[j] == y[k])
                {
                    printf("\n%d+%d==%d", x[i], x[j], y[k]);
                }
            }
        }
    }

    // if (n%2==1)
    // {


        
    //     scanf("%d",&num[n-1]);
    // }

    // printf("\nNum ");
    // for (int i = 0; i < n; i++)
    // {
    //     printf("%d ,", num[i]);
    // }
    // printf("\nPos ");
    // for (int i = 0; i <k; i++)
    // {
    //     printf("%d ,", pos[i]);
    // }
    // printf("\nNeg ");
    // for (int i = 0; i <j; i++)
    // {
    //     printf("%d ,", neg[i]);
    // }

    return 0;
}