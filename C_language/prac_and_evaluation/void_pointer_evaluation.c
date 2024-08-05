#include <stdio.h>
int main()
{	int a = 10;
	char _a = 'A';
	void *ptr;
	printf("\nptr: \t%p",ptr); 
	//printf("\nptr: \t%p",*ptr); //invalid
	printf("\nptr+1: \t%p",ptr+1); 
	printf("\nptr-1: \t%p",ptr-1);

	ptr = &a;


	printf("\nint ptr: \t%p\n",((int *)(ptr)));
       	printf("\nint ptr++: \t%p\n",((int *)ptr+1)); 
       	printf("\nint ptr++: \t%p\n",((int *)(ptr)++)); 
       	printf("\nint ptr++: \t%p\n",((int *)++ptr)); 
        printf("\nptr--: \t%p\n",((int *)ptr--)); 
        printf("\n--ptr: \t%p\n",((int *)--ptr)); 

	ptr = &_a;
	printf("\nderef :%c\n",*((char *)ptr));// typecasting to char pointer
	printf("\nchar ptr: \t%p\n",((char *)ptr+1));
       	printf("\nint ptr++: \t%p\n",((char *)ptr++)); 
	printf("\n++ptr: \t%p\n",((char *)++ptr));
        printf("\n*ptr--: \t%p\n",((char *)ptr--)); 
        printf("\n*--ptr: \t%p\n",((char *)--ptr)); 
	

}

