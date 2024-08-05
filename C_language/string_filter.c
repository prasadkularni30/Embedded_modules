#include<stdio.h>
#include<stdio_ext.h>
#include<string.h>
#include <stdlib.h>



char* filterr(char *, char);

int main()
{
	char data[40];
	char filter;
	
	
	printf("Enter string: ");
	scanf("%[^\n]s",data);
	__fpurge(stdin);
	printf("Enter char to filter: ");
	scanf("%c",&filter);
	printf("\n");
	
	
	printf("output string: %s\n",filterr(data,filter));
}

char * filterr(char *data,char filter)
{
	char *filtered_data;
	
	filtered_data=(char *)malloc(strlen(data)+1);
	
	int a;
	if(filter>90)
	{
		a=filter-32;
	}
	else
	{
		a=filter+32;
	}
	
	printf("a: %d\n",a);
	int i=0,j=0;
	while(data[i]!='\0')
	{
		if(data[i]!=filter && data[i]!=a)
		{
			filtered_data[j]=data[i];
			j++;
		}
		i++;
	}
	
	filtered_data[j]='\0';
	
	return filtered_data;
	
	
}
