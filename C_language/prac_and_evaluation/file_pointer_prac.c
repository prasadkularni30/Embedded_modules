#include<stdio.h>
#include<stdlib.h>
int main()
{
	FILE *fp;
	
	fp = fopen("Copy_array.txt", "w");
	if(fp == NULL){//for checking the file is open or not.
		perror("File open failed");
		exit (0);
	}
	char arr[16] = "Anishant$56121";

	fprintf(fp, "%s",arr);// copy above array in file.
	printf("Pos of fp is %ld", ftell(fp));// to get the location of fp.
	fclose(fp);

	//Opening the file again.
	
	fp = fopen("Copy_array.txt", "r");
	if(fp == NULL){//for checking the file is open or not.
		perror("File open failed");
		exit (0);
	}
	char from_file[17];
	char *ch;
	ch=from_file;
	
	fscanf(fp,"%s",from_file);
	printf("Printing from file: %s\n", from_file);

	char temp_array[17], c;int j=0;


	for(int i = 0; ch[i] != NULL; i++ ){
		if(ch[i]>=65 && ch[i]<=(65+25) || ch[i]>=97 && ch[i]<=122){
			c = ch[i];
			putchar(c);
			//j++;
		//	ch[i-j]=c;
		}
	
	}
	return 0;
}

