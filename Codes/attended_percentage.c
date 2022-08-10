#include <stdio.h>
#include <math.h>
int main()
{
    int held, attended = 2147483646;
    float percent;

    printf("Number of classes held : ");
    scanf("%d", &held);
    printf("Number of classes attended : ");
    scanf("%d", &attended);
    while (attended > held)
    {
        printf("Number of attended class cannot be greater than number of held class.\nPlease try again.\nNumber of classes attended : ");
        scanf("%d", &attended);
    }
    percent = ((float)attended / held) * 100;
    printf("Percentage of class attended is %lf .\n", percent);
    if (percent > 75)
    {
        printf("You are allowed to set an exam.");
    }
    else
    {
        printf("You are not allowed to sit an exam.");
    }

    return 0;
}