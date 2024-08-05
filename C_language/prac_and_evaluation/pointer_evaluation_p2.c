#include <stdio.h>
int main()
{
	int a[5] = {10, 20, 30, 40, 50 };
	int *p=a; int *q=*(&a+1)-1;
 	printf("\n+p++: \t%d",*p++);
       	printf("\n*++p: \t%d",*++p); 
       	printf("\n*++p: \t%d",(*p)++);
       	printf("\n*++p: \t%d",++(*p)); 
       	printf("\n*++p: \t%d",++*p);  
       	printf("\n*++p: \t%d",*(p++));
	printf("\n*++p: \t%d\n",*(++p)); 
 	
	
	printf("\n*q--: \t%d",*q--);
       	printf("\n*--q: \t%d",*--q); 
       	printf("\n(*q)--: \t%d",(*q)--);
       	printf("\n--(*q): \t%d",--(*q)); 
       	printf("\n--*q: \t%d",--*q);  
       	printf("\n*(q--): \t%d",*(q--));
	printf("\n*(--q): \t%d\n",*(--q)); 
}

