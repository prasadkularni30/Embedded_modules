//include library 
#include <stdio.h>

int main() 
{	
	int i, j, n=5;
	
// Code is implemented as per pattern mention but we can also take user input for pattern
	//printf("Taking user input for no of rows and columns\n");
	//scanf("%d",&n);
	
	for(int i=0;i<n;i++)	//i is for columns
	{
		for(int j=0;j<n;j++)	//j is for rows
		{
			if(i==0 || i==n-1 || i ==(n/2))	//if column is first or last print
				printf("8 ");
			else if(j==0 || j==n-1)		//if row is first or last printf 
				printf("8 ");
			else
				printf("  ");			//else all at remaining places printf ' '(space)
		}
		printf("\n");			//to switch to new line after printing each row
	    	
	}

	return 0;
}

