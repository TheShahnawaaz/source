#include <stdio.h>

main()
{
    int n, m, A[100], B[100], C[200], i, j, temp, count = 0, D[200], size = 0, counter = 0, size1 = 0, x;

    printf("Enter positive integer n: "); // Taking Inputs of m,n
    scanf("%d", &n);

    printf("Enter positive integer m:");
    scanf("%d", &m);

    printf("Enter %d positive integers for array A:", n);

    for (i = 0; i < n; i++)
        scanf("%d", &A[i]); // Inputing the array A

    printf("Enter the %d positive integers for array B:", m);

    for (i = 0; i < n; i++)
        scanf("%d", &B[i]); // Inputing the array B

    for (i = 0; i < n; i++) // Sorting the array A
    {
        for (j = i; j < n; j++)
        {
            if (A[i] > A[j])
            {
                temp = A[i];
                A[i] = A[j];
                A[j] = temp;
            }
        }
    }

    for (i = 0; i < n; i++) // Sorting the array B
    {
        for (j = i; j < n; j++)
        {
            if (B[i] > B[j])
            {
                temp = B[i];
                B[i] = B[j];
                B[j] = temp;
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < size; j++)
        {
            if (C[j] == A[i])
                ;
            {
                count++;
                break;
            }
        }
        if (count == 0)
        {
            C[size] = A[i];
            size++;
        }
        count = 0;
    }

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < size; j++)
        {
            if (C[j] == B[j])
            {
                count++;
                break;
            }
        }
        if (count == 0)
        {
            C[size] = B[size];
            size++;
        }
        count = 0;
    }

    for (j = 0; j < size1; j++)
    {
        x = C[j];

        for (i = 0; i < n; i++)
        {
            if (A[i] == x)
                counter++;
        }
        for (i = 0; i < m; i++)
        {
            if (B[i] == x)
                counter++;
        }
        D[size1] = counter;
        size1++;
        counter = 0;
    }
    printf("The array c");
    for (i = 0; i < size; i++)
        printf("%d\n", C[i]);
    printf("The array D");
    for (i = 0; i < size1; i++)
        printf("%d\n", D[i]);
    return 0;
}
