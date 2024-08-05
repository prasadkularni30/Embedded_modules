#include<stdio.h>
int strlength(char *);
void strcopy(char *,char *);
void strcompare(char *, char*);
void strcpyInBigStr(char *,char *);
void strconcat(char *cp1, char *cp2,int);

int main()
{
	char str[20]="Lalit-Prasad",strcpy[20], BigStr[30], Con[20]="-Krushna";
	typedef char* cp;
	cp a,b,c,d;
	a=str;
	b=strcpy;
	c=BigStr;
	d=Con;

	int count=strlength(a);
	printf("\n");

	strcopy(a,b);
	printf("\n");

	strcompare(a,b);
	printf("\n");

	strcpyInBigStr(a,c);
	printf("\n");
	
	strconcat(a,d,count);
	printf("\n");
	

	return 0;
}

//Q1
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

//Q2
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

//Q3
void strcompare(char *cp1, char *cp2)
{
	int i=0;
	while(*(cp1+i)!='\0')
	{
		if(*(cp1+i)==*(cp2+i))
			i++;
		else
		{
			printf("String is not equal\n");
			return;
		}
	}
	printf("String is equal\n");
}

//Q4
void strcpyInBigStr(char *cp1,char *cp2)
{
	int i;
	for(i=0; *(cp1+i) !='\0';i++)
	{
		*(cp2+i)=*(cp1+i);
	}
	*(cp2+i)='\0';

	printf("String 1: %s\n",cp2);
	printf("Cpoied String 2: %s\n",cp2);
}
//Q5
void strconcat(char *cp1, char *cp2,int i)
{
	for(int j=0; *(cp2+j) !='\0';j++,i++)
	{
		*(cp1+i)=*(cp2+j);
	}
	*(cp1+i)='\0';
	printf("Concatenated String : %s\n",cp1);
}

