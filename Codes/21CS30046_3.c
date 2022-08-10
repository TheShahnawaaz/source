/*
Name: SHAHNAWAZ HUSSAIN
Roll no : 21CS30046
Experiment no : 3
*/
// Adding library to the library
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
//Declaring Variable
    float x,y,z,a,b,cosx=1,cosy=1,cosz=1,cosa=1,cosb=1,PI=3.14159;
    int i,j,n;
//Taking Input
    printf("Enter x : ");
    scanf("%f", &x);
    printf("Enter y : ");
    scanf("%f", &y);
    printf("Enter z : ");
    scanf("%f", &z);
    printf("Enter n : ");
    scanf("%d", &n);

//Taking Input while condition not satisfied
    printf("Enter a : ");
    scanf("%f", &a);

    while(!(a<=1 && a>=-1))
    {
        printf("Please enter a value between -1 and 1 \n");
        scanf("\n%f",&a);
    }
//Taking Input while condition not satisfied
    printf("Enter b : ");
    scanf("%f",&b);

    while(!(b<=0.5 && b>=-0.5))
    {
        printf("Please enter a value between -0.5 and 0.5 \n");
        scanf("\n%f",&b);
    }

//Converting Input data from Degree to Radian
    x*=PI/180;
    y*=PI/180;
    z*=PI/180;
    a*=PI/180;
    b*=PI/180;


//Code for calculating Cos of given values
    for(i=1;i<=n;++i)
    {
        int fact2i=1;

        for(j=1;j<=2*i;++j)
        {
            fact2i*=j;
        }

        cosx+=(pow(-1,i)*pow(x,2*i)/fact2i);
        cosy+=(pow(-1,i)*pow(y,2*i)/fact2i);
        cosz+=(pow(-1,i)*pow(z,2*i)/fact2i);
        cosa+=(pow(-1,i)*pow(a,2*i)/fact2i);
        cosb+=(pow(-1,i)*pow(b,2*i)/fact2i);

    }

//Printing output
    printf("cos(x) : %f\n", cosx);
    printf("cos(y) : %f\n", cosy);
    printf("cos(z) : %f\n", cosz);
    printf("cos(a) : %.5f\n", cosa);
    printf("cos(b) : %.5f\n", cosb);


    return 0;
}


