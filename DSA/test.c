#include <stdio.h>
#include <math.h>
double C(int n,int r)
{
    if (r==0||r==n) return 1;
    return C(n-1,r-1)+C(n-1,r);
}
void TOH(int n,char a,char b,char c)
{
    if (n==1) printf("%c->%c\n",a,c);
    else
    {
        TOH(n-1,a,c,b);
        printf("%c->%c\n",a,c);
        TOH(n-1,b,a,c);
    }
}
int f(int &x, int c)
{

    c = c — 1;

    if (c = = 0)
        return 1;

    x = x + 1;

    return f(x, c) * x;
}
void main()
{
    int p=5;
    printf("%d\n",f(p,p));
}