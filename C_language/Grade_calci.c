#include<stdio.h>
int main()
{
	int m,n,omarks=0,tmarks,c,d,i;
	float a,e;
	printf("Enter total number of subjects: ");
	scanf("%d",&n);
	printf("Enter your obtained marks\n");
	
	for(i=1; i<=n; i++)
	{
		scanf("%d",&m);
		omarks=omarks+m;
	}
	e=omarks/n;
	d=e;
	printf("your percentage are %.2f percent\n",e);
	c=d/10;
	if (c<6&&c>=4) // for grade D
	{
		c=6;
	}


	switch(c)
	{
	case 10:
		printf("Your Grade is A+");
		break;
	case 9:
		printf("Your grade is A");
		break;
	case 8:
		printf("Your Grade is B");
		break;
	case 7:
		printf("Your Grade is c");
		break;
	case 6:
		printf("Your Grade is D");
		break;
	default:
		printf("You Grade is F\n You Failed");
		break;
	}
	return 0;

}

		

