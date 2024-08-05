#include<stdio.h>
#include<stdlib.h>

int main(){
	FILE *fp;
	char ch[1000];
	int count=0;
	fp=fopen("linecount.txt","r");

	while(fgets(ch,1000,fp)!=NULL)
	{
		count++;
		puts(ch);
	}
	printf("count= %d",count);
	fclose(fp);
}
/*
#define FILENAME "filea.txt"

int main()
{ 
	FILE *fp;
	char ch;
	int linesCount=0;
	fp=fopen(FILENAME,"r");
	if(fp==NULL) {
		printf("File \"%s\" does not exist!!!\n",FILENAME); exit(0);
	}
	while((ch=fgetc(fp))!=EOF) {
		if(ch=='\n')
			linesCount++;
	}
	fclose(fp);
	printf("Total number of lines are: %d\n",linesCount);
}*/

