#include <stdio.h>
#include <math.h>
int main()
{
    int n, count1 = 0, count2 = 0, count3 = 0, sum1 = 0, sum2 = 0, sum3 = 0;
    printf("Write n : ");
    scanf("%d", &n);
    int num;
    for (int i = 1; i <= n; i++)
    {
        scanf("\n%d", &num);
 
        if (num >= 1 && num <= 10)
        {
            goto label1;
        }
        else if (num >= 11 && num <= 20)
        {
            goto label2;
        }
        else if (num >= 21)
        {
            goto label3;
        }
    label1:
        count1++, sum1 += num;
        goto end;
    label2:
        count2++, sum2 += num;

        goto end;
    label3:
        count3++, sum3 += num;

        goto end;
    end:
        printf("\n");
    }
    printf("There are %d no between 0 to 10 and %d no between 11 to 20 and %d no greater than 20.", count1, count2, count3);
    printf("\nAverage of the no  ");
    if (count1 != 0)
    {
        printf("between 0 to 10 is %d ", sum1 / count1);
    }
    if (count2 != 0)
    {
        printf(", between 11 to 20 is %d", sum2 / count2);
    }
    if (count3 != 0)
    {
        printf(" and no greater than 20 is %d.", sum3 / count3);
    }

    return 0;
}