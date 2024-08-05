#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	char *buff;
	buff=(char*)malloc(sizeof(char)*30);
	int i=0;
	int count=0;
	printf("enter thje string:\n");
	scanf("%[^\n]s",buff);
	
	
	//word count
	
	while(buff[i]!='\0'){
		if(buff[i]==' ')
		{
			count++;
		}
		i++;
	}
	printf("word count is :%d",count+1);
	
	
	//char count
	
	while(buff[i]!='\0')
	{
		
		count++;
		
		i++;
	}
	printf("char count is :%d",count);
	
	
	//printing string without spaces
	
	int l=strlen(buff);
	int j;
	while(buff[i]!='\0')
	{
		
		if((buff[i]==' ' || buff[i]=='\t') || buff[i]=='\n')
		{
			j=i;
			
			while(buff[j]!='\0')
			{
				buff[j]=buff[j+1];
				
				j++;
			}	
		}
		i++;	
	}
	buff[i]='\0';
	printf("sring:%s",buff);
	
	free(buff);
	
}
