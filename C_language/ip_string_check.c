#include<stdio.h>
#include<stdlib.h>
int strlength(char *);
void stringDisplay(char *);
int charString(char *);
void strcopy(char *, char *);

int main()
{
	char str[100];
	typedef char* cp;
	cp a,b;
	a=str;
	int flag=1;

	while(flag==1)
	{
	

	printf("Enter First Name: ");
	scanf(" %[^\n]s",str);
	
	int i=strlength(a);
	b=(char *)malloc(i+1);

	strcopy(a,b);
	printf("\n");

	flag=charString(b);
	printf("\n");

	if(flag==0)
	{
	printf("First Name: ");
	stringDisplay(b);
	printf("\n");
	
	free(b);
	return -1;
	}

	}
}

int strlength(char *cp)
{
	int count=0,i=0;
	while(*(cp+i)!='\0')
	{
		count++;
		i++;
	}
	//printf("Stringlength: %d\n",count);
	return count;
}
void stringDisplay(char *cp)
{
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
}

int charString(char *cp)
{
	int i=0;

	for(;cp[i]!='\0';i++)
	{
		if( cp[i]>=65 && cp[i]<=90 || cp[i]>=97 && cp[i]<=122 );
		else
		{
			printf("Enter your first name properly");
			return 1;
		}
	}
		return 0;
}

