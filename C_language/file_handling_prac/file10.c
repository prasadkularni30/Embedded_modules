#include<stdio.h>

int main()
{
	FILE *f;
	
	
	f=fopen("file10.txt","a+");

	int arr[10]={10,20,30,40,50,60,70,80,90,100},arr1[10];

	for(int i=0;i<10;i++)
	{
		fprintf(f,"%d ",arr[i]);
		
	}
	fseek(f,28,0);

	for(int i=0;i<10;i++)
	{
		fscanf(f,"%d",&arr1[i]);

	}
	for(int i=0;i<10;i++)
	{
		printf("arr1[%d]: %d ",i,arr1[i]);
	}

	fclose(f);

}


