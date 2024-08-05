/*Q5: Whats wrong in the following code, suggest a fix for this. (TRY THE FOLLOWING CODE)
to understand the logic.
struct A
{
int x;
char *str; // (or) char str[20];
};
struct A a1 = {101, “abc” } , a2;
a1.x=10;
a1.str=” hello”; //works?
scanf(“%d%s”,&a1.x,a1.str); //works?
a2 = a1; //shallow copy or deep copy?
  */


#include<stdio.h>
#include<stdio_ext.h>



struct A{
	int x;
	char *str;
	char str1[20];
};

int main()
{
	struct A a1 ={101,"abc","world"} , a2;
	printf("a1.x= %d\n a1.str=%s a1.str1[]= %s \n",a1.x,a1.str,a1.str1);

	a1.x=10;
	a1.str = "hello"; 	//works.
	//a1.str1[] = "hello"; 	//error.

	printf("a1.x= %d\n a1.str= %s \n ",a1.x,a1.str);

	scanf("%d",&a1.x);
	//__fpurge(stdin);
	//scanf("%s",&a1.str);	//segmentation fault
	scanf("%s",a1.str1);	//works

	a2=a1; 			//shallow copy

	printf("a1.x= %d\n a1.str= %s a1.str1[]=%s \n",a1.x,a1.str,a1.str1);
	printf("a2.x= %d\n a2.str= %s a2.str1[]=%s \n",a1.x,a1.str,a1.str1);

	return 0;
}



