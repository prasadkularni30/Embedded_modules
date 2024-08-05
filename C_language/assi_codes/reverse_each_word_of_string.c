//	libraries
#include<stdio.h>
#include<stdio_ext.h>
#include<string.h>
#include <stdlib.h>


int main()
{	
	char buff[40];		
		
	int l=0,i=0,j=0,count=0,ind=0;
	
	printf("enter a string\n");
	scanf("%[^\n]s",buff);		
	__fpurge(stdin);
	
	l=strlen(buff);
		
	printf("Input string : %s\n",buff);
	
	
	for(;i<=l;i++)			
	{
		if((buff[i] != ' ')&&(buff[i]!='\0'))
		{
			count++;
			
			ind=i-count;
		}
		else	
		{ 	
			
			for(j=i;j>=ind;j--)
			{
				printf("%c",buff[j]);
				
			}

			count=0;
		
		}
		
		
	}
	

	
	return 0;
}	
		
