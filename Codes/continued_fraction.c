#include <stdio.h>
#include <math.h>
int main()
{
    int a, b, c;
    printf("Enter a and b: \n");
    scanf("%d %d", &a, &b);

    printf("Continued fraction = [ %d ", a / b);
    for (int i = 0; i < 100; i++)
    {
        if (a % b == 0)
        {
            printf("]");
            break;
        }
        if (i > 0)
        {
            printf(",");
        }
        else
        {
            printf(";");
        }

        c = b;
        b = a % b;
        a = c;
        printf(" %d ", a / b);
    }

    return 0;
}