#include <stdio.h>
#include <math.h>
double p(double x, int u[])
{
    double sum = 0;

    for (int i = 0; i < 4; i++)
    {
        sum += pow(x, i) * u[i];
    }

    return sum;
}
int main()
{
    int coff[4];
    for (int i = 0; i < 4; i++)
    {
        printf("Enter coefficient of x^%d : ", i);
        scanf("%d", &coff[i]);
    }
    double a = -10, b = 10, c;
    for (int i = 0; p(c, coff) > 0.001; i++)
    {
        c = (a * p(b, coff) - b * p(a, coff)) / (p(b, coff) - p(a, coff));
        // printf("%lf -> %lf\n", a, p(a, coff));
        // printf("%lf -> %lf\n", b, p(b, coff));
        // printf("%lf -> %lf\n", c, p(c, coff));
        // printf("%lf \n", p(a, coff) * p(c, coff));

        if (p(a, coff) * p(c, coff) > 0)
        {
            a = c;
        }
        else
        {
            b = c;
        }
    }

    printf("Root of the polynomial: %lf", c);
    // printf("%lf", p(b, coff));
    return 0;
}