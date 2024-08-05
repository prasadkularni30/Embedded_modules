#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
	FILE *fp1; int cnt; int i = 0;
	if( argc < 2 ) { printf("Insufficient Arguments!!!\n"); exit(0); }
	fp1 = fopen(argv[1],"r");
	if( fp1 == NULL ) {
		printf("\n%s File can not be opened : \n",argv[1]); 
		return -1;
	}
	
	fseek(fp1,0,SEEK_END);
	cnt = ftell(fp1);
	printf("%d\n",cnt);
	while( i < cnt ) {
		i++;
		fseek(fp1,-i,SEEK_END);
		printf("%c",fgetc(fp1));
	}
	printf("\n");
	fclose(fp1);
}
/*
int main(int argc, char *argv[])
{
	if(argc<2)
	{
		printf("no para");
		exit(0);
	}
	printf("nu para %d\n",argc);
	
	for(int i=1;i<5;i++)
	{
		printf("%s\n",argv[i]);
	}

	int a=atoi(argv[1]);
	int b=atoi(argv[2]);
	int d=atoi(argv[3]);

	int c=a+b+d;
	printf("\n%d\n",c);
}

*/
