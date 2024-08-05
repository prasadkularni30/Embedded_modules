#include<stdio.h>
#include<stdlib.h>
int strlength(char *);
void stringDisplay(char *);
void charString(char *,char *,int);

int main()
{
	char str[100];
	typedef char* cp;
	cp a,b;

	a=str;
	printf("Enter Input string: ");
	scanf("%[^\n]s",str);

	int i=strlength(a);
	b=(char *)malloc(i+1);

	charString(a,b,i);
	printf("\n");

	printf("Original String: ");
	stringDisplay(a);
	printf("\n");

	printf("Alphabet String: ");
	stringDisplay(b);
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

void charString(char *cp1,char *cp2,int size)
{
	int i=0,j=0;

	for(;i<=size;i++)
	{
		
		if( cp1[i]>=65 && cp1[i]<=90 || cp1[i]>=97 && cp1[i]<=122 )
		{
			cp2[j]=cp1[i];
			j++;
		}
	
	}
	
	*(cp2+i)='\0';
	
}

