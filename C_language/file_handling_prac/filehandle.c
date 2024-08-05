#include<stdio.h>

int main()
{
	FILE *fp;

	fp=fopen("abc.txt","r+");
	
	
	fputs("abcdefghijklmnop",fp);
	fputc('1',fp);

	fprintf(fp,"%d",10);
	//fclose(fp);
	//fp=fopen("abc.txt","r");
	

	fseek(fp,a,0);
	char ch[20];
	fscanf(fp,"%s",ch);
	


	printf("%s",ch);
	





	fclose(fp);
}


