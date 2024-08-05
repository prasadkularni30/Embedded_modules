#include<stdio.h>


int main()
{
	long int n,tax;
	int age;
	char gen;
	printf("Enter your income:\n");
	scanf("%ld",&n);
	printf("Enter your age and gender(M/F):\n");
	scanf("%d %c",&age,&gen);
		

	if(n<=250000)
	{
		printf("no tax");
		
	}
	else if(250000<n<=500000)
	{
		tax=0+(n-250000)*0.05;

	
	}
	else if(500000<n<=750000)
        {
                tax=0+12500+(n-500000)*0.20;

        
	}
	else if(750000<n<=1000000)
        {
		
                tax=0+12500+50000+(n-750000)*0.20;

        
	}
	else if(1000000<n<=1250000)
        {

                tax=0+12500+50000+50000+(n-1000000)*0.30;

        
        }
	else if(1000000<n<=1250000)
        {

                tax=0+12500+50000+50000+75000+(n-1000000)*0.30;

	
        }
	else if(1250000<n<=1500000)
        {
	       
	tax=0+12500+50000+50000+75000+75000+(n-1250000)*0.30;

               
	}
	else
        {

                tax=0+12500+50000+50000+75000+75000+(n-1500000)*0.30;

               
	}


	if(age>=60)
	{
		int temp;
		temp=tax*0.15;
		tax=tax-temp;
		
		printf("tax is %ld",tax);
	}
	else
	{
		if(gen=='f'||gen=='F')
		{
			int temp=temp*0.15;
			tax=tax-temp;
			printf("Tax is %ld",tax);
		}
		else
			printf("Tax is %ld",tax);
	}






	return 0;
}

