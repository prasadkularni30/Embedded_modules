#include<stdio.h>
int main()
{
double a, b, c;
printf("enter any two variables:\n");
scanf("%Lf", &a);
scanf("%Lf", &b);
printf("First variable is %Lf\n", a);
printf("Second variable is %Lf\n", b);
c=a;
a=b;
b=c;
printf("After swapping\n");
printf("First variable is %Lf\n", a);
printf("second variable is %Lf\n", b);

}