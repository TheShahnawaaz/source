#include <stdio.h>
#include <stdlib.h>
int *popular(int **Known, int N)
{
    int *arr = (int *)malloc(N * sizeof(int));
    int popular_person_count = 0;
    for (int i = 0; i < N; i++)
    {
        int popularity_index = 1;
        for (int j = 0; j < N; j++)
        {
            if (Known[j][i] == (-1))
            {
                popularity_index = 0;
            }
        }
        if (popularity_index == 1)
        {
            popularity_index = 0;
            for (int k = 0; k < N; k++)
            {
                if (Known[i][k] == (-1))
                {
                    popularity_index = 1;
                }
            }
        }
        if (popularity_index == 1)
        {
            arr[popular_person_count + 1] = i;
            popular_person_count++;
        }
    }
    arr[0] = popular_person_count;
    return arr;
}
int main()
{
    int N;
    printf("Enter the number of person : ");
    scanf("%d", &N);
    int **arr = (int **)malloc(N * sizeof(int *));
    for (int i = 0; i < N; i++)
    {
        arr[i] = (int *)malloc(N * sizeof(int));
    }
    printf("Enter the matrix Known[][] :\n");
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    int *result = popular(arr, N);
    printf("Number of popular persons: %d\n", result[0]);
    printf("ID of the popular persons: ");
    for (int i = 0; i < result[0]; i++)
    {
        printf("%d ", result[i + 1]);
    }
    return 0;
}