#include<stdio.h>
#include<stdlib.h>

struct structure{
	int prn;
	char name[20];
};


int main(){
	FILE *fp;
	struct structure st= {9119, "prasad kulkarni"};

	fp=fopen("struct.txt","w+");

	if(fp==NULL)
	{
		perror(":");
		exit(0);
	}

	fprintf(fp,"name: %s\nPRN: %d",st.name,st.prn);

	fseek(fp,0,0);

	fscanf(fp,"name: %[^\n]s\nPRN: %d",st.name,&st.prn);

//	fscanf(fp,"%d",&temp);
	
	printf("Name: %s\nPRN: %d",st.prn,st.name);
	fclose(fp);

}

