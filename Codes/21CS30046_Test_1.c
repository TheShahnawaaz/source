/*
Name: SHAHNAWAZ HUSSAIN
Roll no : 21CS30046
Test no : 1
*/
// Adding library to the library
#include <stdio.h>
#include <math.h>
float dist(int x1, int y1, int x2, int y2) // Function to find distance between two points.
{
    int dis = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)); // Distance formula.
    return dis;
}
void swap(int *xp, int *yp) // Function for swapping to integer value through call by reference.
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void display(int index, int data[10][5]) // Function for displaying rectangle.
{
    printf("%d %d %d %d ", data[index][0], data[index][1], data[index][2], data[index][3]);
}
int main()
{
    int rect[10][5], inner_rect[10][5]; // Declaring 2-d array to store data in a Ordered manner.
    printf("Write 10 rectangles : \n");
    for (int i = 0; i < 10; i++)
    {
        printf("===============\n");
        for (int j = 0; j < 4; j++) // Taking input of 10 rectangles.
        {
            scanf("%d", &rect[i][j]);
        }
        rect[i][4] = dist(rect[i][0] + rect[i][2] * 0.5, rect[i][1] + rect[i][3] * 0.5, 0, 0); // Calculating distance from origin of the rectangle and storing it in the database.
        // Note that the respective distance of the rectangle from origin is stored in the 5th row.
    }
    // Shorting the rectangle in ascending order of the distance from origin to that rectangle.
    //  Using bubble short.
    for (int i = 0; i < 10; i++)
    {
        // Last i elements are already in place.
        for (int j = 0; j < 10 - i - 1; j++)
        {
            if (rect[j][4] > rect[j + 1][4])
            {
                swap(&rect[j][0], &rect[j + 1][0]); // Swapping rectangle data.
                swap(&rect[j][1], &rect[j + 1][1]);
                swap(&rect[j][2], &rect[j + 1][2]);
                swap(&rect[j][3], &rect[j + 1][3]);
                swap(&rect[j][4], &rect[j + 1][4]);
            }
        }
    }
    int index = 0, index_data[10]; // Declared for extracting data of rectangles which are contained in some other rectangles.
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (rect[i][0] < rect[j][0] && (rect[i][0] + rect[i][2]) > (rect[j][0] + rect[j][2]) && rect[i][1] < rect[j][1] && (rect[i][1] + rect[i][3]) > (rect[j][1] + rect[j][3]))
            // Checking whether their rectangle with index j is inside the rectangle with index i or not.
            {
                display(i, rect); // Printing the result.
                printf("contains ");
                display(j, rect);
                printf("\n");

                int value = 0;
                for (int k = 0; k < index; k++) // Checking whether the data is already added to the database or not.
                {
                    if (index_data[k] == j)
                    {
                        value = 1;
                    }
                }
                if (value == 0)
                {
                    index_data[index] = j; // Adding data off insider triangle to the database if nao already added.
                    index++;
                }
            }
        }
    }
    // Note that the index variable store the number of rectangles which are contained in some other rectangles.
    printf("Rectangles sorted by distance from origin \n"); // Printing the sorted rectangles.
    for (int i = 0; i < 10; i++)
    {
        display(i, rect);
        printf("\n");
    }
    // Taking input a anbe from the user.
    int a, b;
    printf("Write a and b :\n");
    scanf("%d%d", &a, &b);

    for (int i = 0; i < index; i++) // Copying the data of rectangles which are contained in some other rectangles.
    {
        inner_rect[i][0] = rect[index_data[i]][0];
        inner_rect[i][1] = rect[index_data[i]][1];
        inner_rect[i][2] = rect[index_data[i]][2];
        inner_rect[i][3] = rect[index_data[i]][3];
        inner_rect[i][4] = dist(inner_rect[i][0] + inner_rect[i][2] * 0.5, inner_rect[i][1] + inner_rect[i][3] * 0.5, a, b); // Calculating distance from (a,b) of the rectangle and storing it in the database.
        // Note that the respective distance of the rectangle from origin is stored in the 5th row.
    }
    // Shorting the rectangle in ascending order of the distance from (a,b) to that rectangle.
    //  Using bubble short.
    for (int i = 0; i < index; i++)
    {
        // Last i elements are already in place.
        for (int j = 0; j < 10 - i - 1; j++)
        {
            if (inner_rect[j][4] > inner_rect[j + 1][4])
            {
                swap(&inner_rect[j][0], &inner_rect[j + 1][0]); // Swapping rectangle data.
                swap(&inner_rect[j][1], &inner_rect[j + 1][1]);
                swap(&inner_rect[j][2], &inner_rect[j + 1][2]);
                swap(&inner_rect[j][3], &inner_rect[j + 1][3]);
                swap(&inner_rect[j][4], &inner_rect[j + 1][4]);
            }
        }
    }
    // Printing the rectangle in ascending order of the distance from (a,b) to that rectangle.
    printf("Inner rectangles sorted by distance from (%d,%d):\n", a, b);
    for (int i = 0; i < index; i++)
    {
        display(i, inner_rect); // Printing the sorted rectangles.
        printf("\n");
    }
    return 0;
}