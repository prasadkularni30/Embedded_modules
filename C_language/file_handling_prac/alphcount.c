#include<stdio.h>

int main(){
	FILE *fp;
	int ch;
	int count=0;
	fp=fopen("alphcount.txt","r");

	while((ch=fgetc(fp))!=EOF)
	{
		if((ch>=65&&ch<=90)||(ch>=97&&ch<=122))
		{
			count++;
			putchar(ch);
		}
	
	}
	printf("\ncount= %d",count);
	fclose(fp);
}

