#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//#include<stdio_ext.h>

#define _MAX_EACHE_CHAR_SIZE 100
#define _MAX_NO_OF_WORDS_STRING_ 5


int Count_Words(int size,char ch[]);
void Print_String_Reverse(int,char ch[]);

int main()
{

	char ch[100];
	printf("enter string->");
	fflush(stdin);
	
	fgets(ch,_MAX_EACHE_CHAR_SIZE,stdin);
	fflush(stdin);
	
	ch[strlen(ch)-1]='\0';//assigning null at end
	int stringSize=strlen(ch);
	
	//printf("stringSize=%d\nstirng=%s\n",stringSize,ch );
	int WordCount=Count_Words(stringSize,ch);
	
	printf("original=%s\n",ch );
	char *cp[WordCount];
	
	int c=0;
	int i=0;

	for(int j=0;j<WordCount;j++)
	{
		char temp[_MAX_EACHE_CHAR_SIZE];
		int k=0;
		for (; i <= stringSize; ++i)
		{
			if (ch[i]==' '||ch[i]==' '||ch[i]=='\0')
			{
				temp[k]='\0';
				int s = strlen(temp);
		//printf("temp=%s\n",temp);
				cp[c] = (char *)malloc(strlen(temp));
				strcpy(cp[c],temp);
		//Print_String_Reverse(s,cp);
		//free(cp);
				c++;
				i++;
				break;
			}
		temp[k]=ch[i];
		k++;
		}

	}


//printf("\n");
	typedef struct
	{
		int len;
		int index;
	}t1;
	t1 temp1;

	temp1.len=strlen(cp[0]);
	temp1.index=0;
	for (int i = 1; i < WordCount; ++i)
	{
		if (temp1.len<strlen(cp[i]))
		{
			temp1.len=strlen(cp[i]);
			temp1.index=i;
		}
	}

	printf("Final output -> %s\n",cp[temp1.index]);


//printf("original=%s\n",ch );
//printf("WordCount=%d\n",WordCount );

	i=0;
	for(int j=0;j<=WordCount;j++)
	{
		char temp[_MAX_EACHE_CHAR_SIZE];
		int k=0;
		for (; i <= stringSize; ++i)
		{
			if (ch[i]==' '||ch[i]==' '||ch[i]=='\0')
			{
				temp[k]='\0';
				int s = strlen(temp);
				char* cp = (char *)malloc(strlen(temp));
				strcpy(cp,temp);
				Print_String_Reverse(s,cp);
				free(cp);
				i++;
				break;
			}
			temp[k]=ch[i];
			k++;
		}
	}




 }
 
 
 int Count_Words(int size,char ch[])
 {
 	 int Count=0;
	  for (int i = 0; i <= size; ++i)
	  {	
		  if (ch[i]==' '||ch[i]=='	'||ch[i]=='\0') //comparing with space and tab
		  {
			  Count++;
		  }
	  }
	  return Count;
 }

 void Print_String_Reverse(int size,char ch[])
 {
	for (int i = size; i >= 0; --i)
  	{
		printf("%c",ch[i]);
  	}
	printf(" "); //space after every reverse word print
 }
 
 
