#include<stdio.h>
int main()
{
int a, b, c;
float avg;
printf("enter three interger numbers\n");
scanf("%d",&a);
scanf("%d",&b);
scanf("%d",&c);
avg=(a+b+c)/3.0;
printf("average of 3 integer numbers is %f", avg);
return 0;
}