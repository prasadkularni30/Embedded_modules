#include<stdio.h>
#include<stdlib.h>
int strlength(char *);
void stringDisplay(char *);
void StrReverse(char *,int);
void strcopy(char *, char *);

int main()
{
	char str[100];
	typedef char* cp;
	cp a,b;

	a=str;
	printf("Enter Input string: ");
	scanf("%[^\n]s",str);

	int i=strlength(a);
	//printf("%d\n",i);

	b=(char *)malloc(i+1);

	strcopy(a,b);
	printf("\n");
	
	stringDisplay(b);
	printf("\n");

	StrReverse(b,i);
	printf("\n");
	
	free(b);

	return 0;
}

int strlength(char *cp)
{
	int count=0,i=0;
	while(*(cp+i)!='\0')
	{
		count++;
		i++;
	}
	printf("Stringlength: %d\n",count);
	return count;
}
void stringDisplay(char *cp)
{

	printf("String Display:");
	for(int i=0;cp[i]!='\0';i++)
	{
		printf("%c",cp[i]);
	}
	printf("\n");
}

void strcopy(char *cp1, char *cp2)
{
	int i;
	for(i=0; *(cp1+i) !='\0';i++)
	{
		*(cp2+i)=*(cp1+i);
	}
	*(cp2+i)='\0';

	printf("String 1: %s\n",cp1);
	printf("String 2: %s\n",cp2);
}

void StrReverse(char *cp,int size)
{
	printf("Reverse string: ");
	for(size;size>=0;size--)
	{
		printf("%c",cp[size]);
	}
	printf("\n");
}

