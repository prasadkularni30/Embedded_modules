#include<stdio.h>
#include<stdio_ext.h>
#include<stdlib.h>


int strlength(char *);

void strcopy(char *);

int strcmp(char *,char *);



int main()
{
	char buff1[30];
	char buff2[30];
	
	printf("Enter String 1: ");
	scanf("%[^\n]s",buff1);
	__fpurge(stdin);
	printf("Enter String 2: ");
	scanf("%[^\n]s",buff2);
	
	
	printf("\n");
	
	printf("String lenght of string 1: %d\n",strlength(buff1));
	printf("String lenght of string 2: %d\n",strlength(buff2));
	
	printf("\n");
	
	
	strcopy(buff1);
	
	printf("\n");
	
	if(!(strcmp(buff1,buff2)))
		printf("Strings are same\n");
	else
		printf("Strings are different\n");
		
		
		printf("\n");
}

/*
Q1: Implement your own string length finding program, print the length of the
given string.
(man strlen for reference)
*/

int strlength(char *buff)
{
	char ch;
	int i=0;
	
	do
	{
		ch=buff[i];
		i++;
	}while(ch!='\0');
	
	return i-1;
}


/*
Q2: Implement your own string copy function.
(man strcpy for reference)
*/
void strcopy(char *buff)
{
	char *temp;
	
	int l=strlength(buff);
	
	temp=(char *)calloc((l+1),sizeof(char));
	int i=0;
	
	while(buff[i]!='\0')
	{
		temp[i]=buff[i];
		i++;
	}
	
	printf("Copied string: %s\n",temp);
	
	free(temp);
}


/*
Q3: Implement your own string comparison function. Which can compare two
strings and tell whether the two strings are same or not.
(man strcmp for reference)
*/

int strcmp(char *buff1,char *buff2)
{
	int i=0;
	
	while(buff1[i]!='\0' && buff2[i]!='\0')
	{
		if(buff1[i]!=buff2[i])
			return 1;	
		i++;
	}
	
	if(buff1[i]=='\0' && buff2[i]=='\0')
		return 0;
		
	return 1;
}
