#include<stdio.h>

int main()
{
	char ch[5]={'a','b','c','d','e'};
	char *ptr=&ch;
	
	printf("&ch[0]=%p",ptr);
	
	for(int i=0;i<5;i++)
	{
		printf("i=%d ptr++=%p,char=%c\n",i,ptr[i],ptr[i]);

	}
	return 0;
}
