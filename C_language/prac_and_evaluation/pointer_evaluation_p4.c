#include<stdio.h>
/*
const int * p;
int const * p
int * const p = &x;
const int * const p = &x;
Try *p=20, p++, (*p)++, p=&y in each case*/

int main()
{
	/*
	int const *p;
	const int x=10;
	p=&x;
	*p=20;//error,can not change the value of const variable 
	*/
/*	int x=100,y=10;
	int const *p;	//here, int const *p and const int *p are same
	//const int *p;

	p=&x;
	//*p=200;			//error, here variale is integer(y) and p is treating integer(y) as a constant
       	//p=&y;				//assign pointer to another variable
        //printf("*++p: %d",*++p);	//p will be incremented by 4byte, and fetch the value from next address
       	// printf("(*p)++: %d",(*p)++);	//error, here variale is integer(y) and p is treating integer(y) as a constant so value cannot be incremented
	
*/

/*	int x=10,y=20;
	int *const p=&x;
	printf("*ptr: %d",*p);

	//p=&y;				//error, pointer is constant so we cannot change stored  address at run-time
	//*p=200;			//we can change the value stored in address but not variable 
	//printf("*p: %d",*p);	
	//printf("*++p: %d",*++p);	//error, as p is constant pointer we can not increment and store new address again in run-time after once it it declared 
	//printf("++(*p): %d",++(*p));	//will deref p and increment the value stored at &x by 1
*/
	

/*	int x=10,y=20;
	const int * const p=&x;
	printf("*ptr: %d",*p);

	p=&y;				//error, pointer is constant so we cannot change stored  address at run-time
	//*p=200;			//error, here variale is integer(y) and p is treating integer(y) as a constant
	//printf("*p: %d",*p);	
	//printf("*++p: %d",*++p);	//error, as p is constant pointer we can not increment and store new address again in run-time after once it it declared 
	// printf("(*p)++: %d",(*p)++); //error, here variale is integer(y) and p is treating integer(y) as a constant so value cannot be incremented

*/
}
