#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
#define SWAP(type, a, b) {type t ; t=a; a=b ; b=t ;}
int main()
{
int x=10, y=20;
printf("x=%d y=%d\n", x,y);
SWAP(int, x,y);
printf("x=%d y=%d\n", x,y);
}
*/

/*
int main()
{
char a[20],b[20];
char *ptr;
printf("B= ");
scanf("%s",b);
ptr=memcpy(a,b,10);
printf("A= %s\n",a);

printf("PTR= %s\n",ptr );
scanf("%s",b);

strcpy(a,b);
printf("A= %s\n",a);
printf("PTR= %s\n",ptr );
}*/
/*
int main()
{
char*cptr;
cptr=malloc(20);
char*ptr;
ptr=memset(cptr,65,20);
printf("cptr= %s\n",cptr);
printf("ptr= %s\n",ptr);
char a[10]={"abcdefgh"};
strcpy(cptr,a);
printf("cptr= %s\n",cptr);
printf("ptr= %s\n",ptr);


}*/

/*
int main()
{
char ch='a';
int i=97;
char *ptr1=&ch;
int *ptr2=&i;
int flag=memcmp(ptr1,ptr2,1);
printf("%d\n",flag);
}*/

void g_swap(void*,void*,int );
int main()
{
	int a=10,b=20;
	char c1='a',c2='b';
	float f1=10.1,f2=20.1;
	
	printf("before swapping\n");
	printf("a=%d b=%d\n",a,b);
	printf("c1=%c c2=%c\n",c1,c2);
	printf("f1=%f f2=%f\n",f1,f2);
	
	g_swap(&a,&b,sizeof(a));
	g_swap(&c1,&c2,sizeof(c1));
	g_swap(&f1,&f2,sizeof(f1));

	printf("after swapping\n");
	printf("a=%d b=%d\n",a,b);
	printf("c1=%c c2=%c\n",c1,c2);
	printf("f1=%f f2=%f\n",f1,f2);
}
void g_swap(void*ptr1,void*ptr2,int check)
{
	void*cptr=malloc(check);
	memcpy(cptr,ptr1,check);
	memcpy(ptr1,ptr2,check);
	memcpy(ptr2,cptr,check);

	free(cptr);
}


