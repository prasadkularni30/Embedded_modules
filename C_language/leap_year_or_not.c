//Find out given year is leap year or not
#include<stdio.h>
int main()
{
       int n;
       printf("Enter a Year");
       scanf("%d",&n);
       if(n%100!=0 && n%400==0 || n%4==0) // if number is not divisible by 100 and divisible by 400 or number is divisible by 4
	       printf("%d is a leap year",n);
       else 
       printf("%d is not leap year",n);
      
return 0;
}
