#include<stdio.h>

int main()
{
	int arr[10]={10,20,30,40,50,60,70,80,90,100};
	
	int mid,start,end;
	
	
	int x;
	
	while(1)
	{
	start=0;
	end=9;
	printf("Enter Element: ");
	scanf("%d",&x);
	
		while(start<=end)
		{
			mid=(start+end)/2;
		
			if(arr[mid]==x)
			break;
			
			if(arr[mid]<x)
			start=mid+1;
			
			if(arr[mid]>x)
			end=mid-1;
	
		}
		
		printf("element found at positon : %d\n",mid+1);
		
		
		int flag=0,i;
		for(i=0;i<10;i++)
		{
			if(x==arr[i])
			{
				flag++;
				break;
			}
			
		}
		if(flag==1)
		{
			printf("element found at pos %d\n",i+1);
		}
		if(flag==0)
		{
			printf("element not found");
		}
	
	}
	
}
