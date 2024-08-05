/*
Q1: Define your own iterative functions for
(using array notation as well as exclusively using pointers)
a)finding first occurrence of given character
b)finding last occurrence of given character
c) counting number of occurrences of a given character
d)finding a substring in a main string
e)Whether a string starts or ends with a particular sub string
*/

#include <stdio.h>
#include<stdio_ext.h>
#include<string.h>

int first_occurance(char *,char);
int last_occurance(char *,char);
int occurance_count(char *, char);

int main()
{
	char str[30];
	
	char ch;
	
	printf("Enter string: ");
	scanf("%[^\n]s",str);
	__fpurge(stdin);
	printf("Enter char to find occurance: ");
	scanf("%c",&ch);
	
	printf("first occurance of '%c' in string '%s' is at position '%d'\n",ch,str,(1+first_occurance(str,ch)));
	
	printf("last occurance of '%c' in string '%s' is at position '%d'\n",ch,str,(1+last_occurance(str,ch)));
	
	printf("total occurance of '%c' in string '%s' is at position '%d'\n",ch,str,occurance_count(str,ch));
	
}

int first_occurance(char *buff,char ch)
{
	int i=0;
	while(buff[i]!='\0')
	{
		if(buff[i]==ch)
			return i;
			
		i++;
	}
	
}

int last_occurance(char *buff,char ch)
{
	int i=strlen(buff);
	//printf("%d",i);
	while(i>=0)
	{
		if(buff[i]==ch)
			return i;
			
		i--;
	}
	
}

int occurance_count(char *buff,char ch)
{
	int i=0;
	int count=0;
	while(buff[i]!='\0')
	{
		if(buff[i]==ch)
			count++;
			
		i++;
	}
	
	return count;
	
}
