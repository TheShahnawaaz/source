#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
char **bomberMan(int n, int grid_count, char **grid, int *result_count)
{
    if (n == 1)
    {
        *result_count = grid_count;
        return grid;
    }
    if (n % 2 == 0)
    {
        *result_count = grid_count;

        for (int i = 0; i < grid_count; i++)
        {
            for (int j = 0; j < strlen(grid[0]); j++)
            {
                grid[i][j] = 'O';
            }
        }
        return grid;
    }
    if (n >= 3)
    {

        char **a = malloc(grid_count * sizeof(char *));
        for (int i = 0; i < grid_count; i++)
        {
            *(a + i) = malloc((strlen(grid[0])) * sizeof(char));
        }
        for (int i = 0; i < grid_count; i++)
        {
            for (int j = 0; j < (strlen(grid[0])); j++)
            {
                a[i][j] = 'O';
            }
        }
        for (int i = 0; i < grid_count; i++)
        {
            for (int j = 0; j < (strlen(grid[0])); j++)
            {
                if (grid[i][j] == 'O')
                {
                    a[i][j] = '.';
                    if (i > 0)
                    {
                        a[i - 1][j] = '.';
                    }
                    if (j > 0)
                    {
                        a[i][j - 1] = '.';
                    }
                    if (i < grid_count - 1)
                    {
                        a[i + 1][j] = '.';
                    }
                    if (j < strlen(grid[0]) - 1)
                    {
                        a[i][j + 1] = '.';
                    }
                }
            }
        }
        // printf("\n**********\n");

        // for (int i = 0; i < grid_count; i++)
        // {
        //     printf("%s", *(a + i));

        //     if (i != grid_count - 1)
        //     {
        //         printf("\n");
        //     }
        // }
        // printf("\n**********\n");

        return bomberMan(n - 2, grid_count, a, result_count);
    }
}

int main()
{
    int r, c, n;
    scanf("%d %d %d", &r, &c, &n);
    int result_count;
    char **grid = malloc(r * sizeof(char *));
    for (int i = 0; i < r; i++)
    {
        *(grid + i) = malloc(c * sizeof(char));
    }
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            scanf("%d", &grid[i][j]);
        }
    }

    char **result = bomberMan(n, r, grid, &result_count);
    printf("\n");

    for (int i = 0; i < result_count; i++)
    {
        printf("%s", *(result + i));

        if (i != result_count - 1)
        {
            printf("\n");
        }
    }
    return 0;
}