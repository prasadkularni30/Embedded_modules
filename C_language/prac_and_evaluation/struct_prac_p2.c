/*Q7: Using function calls, create a structure variable in one function and return the structure
variable to the caller function, where caller can use the data returned by function to display
the output.
Example: main(){

struct data var = function();
----- code to display var data ----
}
struct data function()
{
struct data var1;
--- initialization code ---
return var1;
}*/

#include<stdio.h>

typedef struct demo{
	int a;
	int b;
	int c;
}d;

struct demo fun();

int main()
{
	struct  demo v1=fun();
	printf("Sum =%d\n",v1.c);
}

struct demo fun()
{
	d sum;
	
	printf("Enter number:");
	scanf("%d",&sum.a);
	printf("\nEnter number:");
	scanf("%d",&sum.b);

	sum.c=sum.a+sum.b;
	return sum;
}



