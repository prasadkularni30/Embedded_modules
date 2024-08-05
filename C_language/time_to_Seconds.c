#include<stdio.h>
void seconds();
void hours();

int main()
{
	int n;
	printf("choose type of conversion\n 1. hh:mm:ss to seconds\n 2. seconds to hh:mm:ss\n");
		scanf("%d",&n);
	if (n==1)
	{
		seconds();
	}
	else if(n==2)
	{
		hours();
	}
	else{
		printf("Choose from given options only");
	}
	return 0;
}

void seconds()
{
	int h,m,s;
	printf("Enter hours: ");
	scanf("%d",&h);
	printf("Enter minutes: ");
	scanf("%d",&m);
	printf("Enter seconds: ");
	scanf("%d",&s);
	s=s+(m*60)+(h*3600);
	printf("seconds= %d",s);
}

void hours()
{
	int s,h,m;
	printf("Enter seconds: ");
	scanf("%d",&s);
	h=s/3600;
	s=s%3600;
	m=s/60;
	s=s%60;
	printf("time=%d:%d:%d",h,m,s);
}
	
