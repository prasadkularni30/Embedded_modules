//reversing 3 digits no.
#include<stdio.h>
int main()
{
	int n, ans, c, temp,a;
	printf("Enter a number to reverse\n");
	scanf("%d",&a);
	temp=0;
	ans=0;
	while(a>0) //
	{
		temp=a%10; //taking last digit in temp
		ans=ans*10+temp; //storing last digit in ans
		a=a/10; //updating original with number without last digit

	}
	printf("Reversed\n");
	printf("%d\n",ans);
}
