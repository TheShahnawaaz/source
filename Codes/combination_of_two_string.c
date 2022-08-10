

#include <stdio.h>
#include <math.h>
int main()
{
    char name1[25], name2[25], con[25];
    printf("Enter first name : ");
    scanf("%s", name1);
    printf("Enter second name : ");
    scanf("%s", name2);
    int i = 0,j=0;
    for (; name1[i]!='\0'; i++)
    {
        con[i]=name1[i];
    }
    for (; name2[j]!='\0'; j++,i++)
    {
        con[i]=name2[j];
    }
    

    printf("%s\n",name1);
    printf("%s\n",name2);
    printf("%s\n",con);

    return 0;
}