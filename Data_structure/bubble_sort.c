#include<stdio.h>
#include<string.h>
#include<stdlib.h>


void swap(void *,void *,int );


int  main()
{
	int *arr;
	int i,j,s,count,temp,n;
	
	printf("Enter Size of array: ");
	scanf("%d",&n);
	
	arr=(int *)malloc(sizeof(int)*n);
	
	
	for(i=0;i<n;i++)
	{
		printf("Enter Element [%d]= ",i+1);
		scanf("%d",&arr[i]);
	}
	
	//swap(&arr[i],&arr[i+1],sizeof(int));
	
	//printf("arr[i]=%d,arr[i+1]=%d\n",arr[i],arr[i+1]);
	s=n;
	
	do
	{
		count=0;
		for(i=0,j=1;j<s;i++,j++)
		{
			if(arr[i]>arr[i+1])
			{
				swap(&arr[i],&arr[j],sizeof(arr[i]));
				/*temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;*/
				count++;
			}
		}
		s--;
	}while(count!=0);
	
	printf("After sorting\n");
	for(i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
	
}

void swap(void *a,void *b,int s)
{
	void *temp;
	temp=(void *)malloc(s);
	memcpy(temp,a,s);
	memcpy(a,b,s);
	memcpy(b,temp,s);
	
}
