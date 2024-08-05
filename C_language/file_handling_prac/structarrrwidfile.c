#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct structure{
	int prn;
	char name[20];
}st;


int main(){
	char ch[20];

	

	struct structure *str;

	str=(struct structure *)malloc(sizeof(st)*2);

	str[0].prn=9119;
	scanf("%s",ch);
	//ch="prasad kulkarni";
	strcpy(str[0].name,ch);
	str[1].prn=7823;
	scanf("%s",ch);
	//ch="shubham Yadav";
	strcpy(str[1].name,ch);

/*
	printf("PRN: %d",str[0].prn);
	printf("name: %s\n",str[0].name);
	printf("PRN: %d",str[1].prn);
	printf("name: %s",str[1].name);

*/
	
	FILE *fp;
	//struct structure st= {9119, "prasad kulkarni"};

	fp=fopen("structarray1.txt","w+");

	if(fp==NULL)
	{
		perror(":");
		exit(0);
	}

	
	int x=fwrite(str,sizeof(st),2,fp);
	printf("x=%d",x);
	
	
//	fprintf(fp,"name: %s\nPRN: %d",st.name,st.prn);

	fseek(fp,0,0);
	struct structure arr[2];
	/*
	fread(&st,sizeof(st),1,fp);

//fscanf(fp,"name: %[^\n]s\nPRN: %d",st.name,&st.prn);

	
	printf("\nName: %d\nPRN: %s",st.prn,st.name);

	x=ftell(fp);
	printf("\nx: %d\n",x);
	fread(&st,sizeof(st),1,fp);
	printf("Name: %d\nPRN: %s\n",st.prn,st.name);
	x=ftell(fp);
	printf("\nx: %d\n",x);
	*/
	fread(arr,sizeof(st),2,fp);
	for(int i=0;i<2;i++)
		printf("%d, %s\n", arr[i].prn, arr[i].name);

	fclose(fp);

}

