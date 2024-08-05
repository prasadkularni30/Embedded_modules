/*Q6: Try out nesting of structures, unions
(a) Union inside a structure
(b) Structure/Structures inside a union
(c) Union inside another union etc.
*/


#include<stdio.h>

struct structure{
	int x;
	union{
		char ch;
	}a;
};


union uni{
	int x;
	struct{
		char ch[4];
		short int q;
		short int p;
	}a;
};
union str{
	int x;
	union un{
		short int q;
	}a;
};

int main()
{
	//union inside structure
	struct structure z;

	z.x=0x41424344;

	printf("union in structure %x\n",*(&z.a.ch-1));

	//structure inside  union
	//
	union uni w;
	w.x=0x41424344;
	for(int i=0;i<4;i++)
	{
	printf("loop%x\n",w.a.ch[i]);
	}

	printf("short int q%x\n",w.a.q);
	printf("short int p%x\n",w.a.p);

	//union inside union
	
	union str f;
	f.a.q=0x4441;

	printf("union in union %x",f.x);
	

}

	/*
	printf("%x\n",z.a.y);
	printf("a=%ld\n",sizeof(z.a));
	printf("ch=%ld\n",sizeof(z.a.ch));
	printf("b=%ld\n",sizeof(z.a.b));
	printf("y=%ld\n",sizeof(z.a.y));
	printf("q=%ld\n",sizeof(z.a.q));
	
	*/

