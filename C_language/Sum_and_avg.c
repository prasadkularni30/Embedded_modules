//Sum and Average of N numbers
#include<stdio.h>
int main()
{
	float n;
	printf("Enter number=");
	scanf("%f",&n);
	
	int sum=0;
	float avg;
	for(int i=1;i<=n;i++)
	{
		sum=sum+i;
	}
	avg=sum/n;
	printf("Sum of Total numbers is %d\n",sum);
	printf("Average of Total numbers is %0.2f\n",avg);
	return 0;
}
