

#include<stdio.h>
#include<stdio_ext.h>
#include <stdlib.h>
#include <string.h>



typedef struct students{
	char name[30];
	int rollno;
	char class;
	
}data;

int count=0,size=0;


void input(data *);
void display(data *,int );
void update(data *);
int search(data *);


void read_from_file(data *);
void write_in_file(data *);


int main(){

	int temp;
	data *studs=NULL;
	
	FILE *fp=NULL;
	fp=fopen("student_data.txt","w+");
	
	if(fp==NULL)
	{
		printf("No file found\n");
		return 0;
	}
	
	fscanf(fp,"%d\n",&size);
	printf("size: %d\n",size);
	
	fclose(fp);
	if((size==0))
	{
		printf("Enter total number of students: ");
		scanf("%d",&size);
	}
	
	studs=(data *)malloc(sizeof(data)*size);
	
	read_from_file(studs);
	
	while(1)
	{
		printf("1:\tData Input\n2:\tDisplay all students data\n3:\tSearch and display specific data\n4:\tUpdate data\n5:\tRead from file\n0:\tExit\n");
		printf("Enter Choice:");
		scanf("%d",&temp);
		
		switch(temp){
			case 1:
				if(count<size)
				input(studs);
				else{
				printf("you have entered all students data\n");
				}
				break;
			case 2:
				for(int i=0;i<count;i++)
				display(studs,i);
				break;
			case 3:
				search(studs);
				break;
			case 4:
				update(studs);
				break;
			case 5:
				//read_from_file(studs);
				break;
			case 0:
				printf("=======================================EXITING=============================================\n");
				write_in_file(studs);
				free(studs);
				
				studs=NULL;
				exit(0);
			default:
				printf("Invalid Input\n");
				break;
				}
	}

}

//to write data stored in array in the file 
void write_in_file(data *s)
{
	FILE *fp=NULL;
	fp=fopen("student_data.txt","w");
	
	if(fp==NULL)
	{
		printf("No file found\n");
		return;
	}
	
	fprintf(fp,"%d\n%d\n",size,count);
	for(int i=0; i<count;i++)
	{
		fprintf(fp,"%d %s %c\n",s[i].rollno,s[i].name,s[i].class);
	}
	fprintf(fp,"\n");
	
	fclose(fp);
}

void read_from_file(data *s)
{
	FILE *fp=NULL;
	fp=fopen("student_data.txt","r");
	
	if(fp==NULL)
	{
		printf("No file found\n");
		return;
	}
	fseek(fp,1,SEEK_CUR);
	fscanf(fp,"%d\n",&count);
	printf("count: %d\n",count);
	for(int i=0;i<count;i++)
	{
		fscanf(fp,"%d %s %c\n",&s[i].rollno,s[i].name,&s[i].class);
	}
	
	
	fclose(fp);
	
	
}
void input(data *s)
{

	printf("======================================================================\n");
	
	printf("Enter student name: ");
	__fpurge(stdin);
	scanf(" %s",s[count].name);
	__fpurge(stdin);
	
	
	
	printf("Enter student roll no: ");
	scanf("%d",&(s+count)->rollno);
	__fpurge(stdin);
	
	printf("Enter Division: ");
	scanf("%c",&(s+count)->class);
	__fpurge(stdin);

	count++;
	printf("======================================================================\n");
}

void display(data *s,int i)
{
	printf("======================================================================\n");
	printf("Student Roll no: %d\n",(s+i)->rollno);
	printf("Student Name: %s\n",(s+i)->name);
	printf("Division: %c\n",(s+i)->class);
	
	
	printf("======================================================================\n");
}



int search(data *s)
{
	int temp,flag=0;
	printf("======================================================================\n");
	printf("Enter student roll no: ");
	scanf("%d",&temp);
	
	for(int i=0;i<count;i++)
	{
		if(temp==(s+i)->rollno)
		{
			flag=1;
			display(s,i);
			return i;
		}
	}
	if(flag==0)
	{	
		printf("No Data match\n");
	printf("======================================================================\n");
}
}

void update(data *s)
{
	int i=search(s);
	int n;
	char buff[20];
	printf("======================================================================\n");
	printf("Modification: \n1. name\n");
	printf("Enter choice: ");
	scanf("%d",&n);
	
	switch(n){
		case 1:
			printf("Enter student name: ");
			__fpurge(stdin);
			scanf("%[^\n]s",buff);
			__fpurge(stdin);
			strcpy((s+i)->name,buff);
			break;
		default:
			printf("Invalid Choice");
			break;
		}
	printf("======================================================================\n");
}

