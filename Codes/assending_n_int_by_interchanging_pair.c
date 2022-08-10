#include <stdio.h>
#include <math.h>
int main()
{
    int n, x[25], asc[25];
    printf("Enter a number n : ");
    scanf("%d", &n);

    printf("Enter %d numbers : ", n);
    for (int i = 0, temp; i < n; i = i + 1)
    {
        scanf("%d", &x[i]);
    }
    int j = 0, k = 0, temp;
    for (int j = 0; j < n; j++)
    {
        for (int i = 1; i < n; i++)
        {
            if (x[i - 1] > x[i])
            {
                temp = x[i - 1];
                x[i - 1] = x[i];
                x[i] = temp;
            }
        }
        printf("\nAssending ");
        for (int i = 0; i < n; i++)
        {
            printf("%d ,", x[i]);
        }
        printf("\n");
    }

    //  printf("Min %d\n", min);
    // printf("k=%d\n", k);
    // k++;

    // printf("\nUnion ");
    // for (int i = 0; i < l; i++)
    // {
    //     printf("%d ,", u[i]);
    // }
    // printf("\nDiffrence ");
    // for (int i = 0; i < q; i++)
    // {
    //     printf("%d ,", diff[i]);
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