#include<stdio.h>
int main()
{
	int n,i,j,k,l;
	scanf("%d",&n);
	//l=1*(2-2)/1;
	//printf("%d",l);
	for (i=1;i<n;i++)
	{
		
		for(j=1;j<(n-i);j++)
		{
			printf(" ");
		}
		l=1;
		for(j=1;j<=(i);j++)
		{
			printf(" %d",l);
			l=l*(i-j)/j;
		}

		printf("\n");
	}
	return 0;
}
