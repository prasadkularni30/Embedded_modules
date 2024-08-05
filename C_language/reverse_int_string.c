/*Q9. Implement your own function to convert a string having only digits into an
integer and vice versa.*/

#include<stdio.h>
#include<stdlib.h>
int strlength(char *);
void convert(char *,int *);
void strcopy(char *, char *);


int main()
{
	char str[100];
	int choice,i;
	char *cp;
	cp=str; 
	
	/*Printf("Enter choice:");
	scanf(" %d",&choice);
	printf("\n");*/
	
	printf("Enter Numbers: ");
	scanf(" %[^\n]s",str);
	
	i=strlength(str);
	cp=(char *)malloc(i+1);
	
	int *arr=(int *)malloc(sizeof(int)*i);
	
	strcopy(str,cp);
	printf("\n");
	
	convert(cp,arr);
	printf("\n");
	printf("integers: );
	for(int k=0;k<i;k++)
	{
		printf("%d",arr[k]);
	
	}
	
	free(cp);
	free(arr);

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
	//printf("Stringlength: %d\n",count);
	return count;
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

void convert(char *cp,int *arr)
{
	int i=0,j=0;
	
	for(;cp[i]!='\0';i++)
	{
		if( cp[i]>=65 && cp[i]<=90 || cp[i]>=97 && cp[i]<=122 );
		{
			arr[j]=cp[i]-48;
			j++;
		}
		
	}
	
	/*
	else if(choice==2)
	{
	for(i=0;i<size;i++)
	{
		cp[i]=arr[i]+48;
	}
	}
		*/
}

  
