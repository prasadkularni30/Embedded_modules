#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void reverse_str(char *,int,int);

int main()
{
	char buff[30];
	
	
	printf("Enter string: ");
	scanf("%[^\n]",buff);
	//i have many books
	//welcome to cdac
	
	reverse_str(buff,0,(strlen(buff)-1));
	
	//skoob ynam evah i
	
	int j=0,k=0,count=0,ind=0;
	
	for(int i=0;i<=(strlen(buff));i++)
	{
		if((buff[i]==' ') || (buff[i]=='\0'))
		{
			reverse_str(buff,ind,i-1);
			ind=i+1;
		}
		
	}
	//books many have i
	//emoclew ot cadc
	printf("Reverse string:\n");
	printf("%s\n",buff);
	
	
}


void reverse_str(char *str,int start,int end)
{
	while(start<end)
	{
		char temp=str[start];
		str[start]=str[end];
		str[end]=temp;
		
		start++;
		end--;
	}
}
