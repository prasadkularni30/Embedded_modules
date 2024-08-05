/*Q8
Create a structure for student/employee information with suitable members and do the
following
- Creating variables, input, output operations
- initialization (complete or partial) of variables
- create a pointer of struct type, and assign address of variable
- access members from the pointer using arrow operator
- calculate size of variable, offset of each member
- create alias for the structure type, pointer type using typedef

Q9
In the student structure created above modify marks member as an array(array of 5 subjects), create an
array of struct variables and do some input, output operations.(Marks of ith student in jth subject
etc).Find the student wise totals, subject wise totals.*/

#include<stdio.h>
#include<stdio_ext.h>
#include <stdlib.h>
#include <string.h>

char *subject[5]={"English","Maths","Physics","Chemistry","Biology"};
int count=0;


typedef struct students{
	char *name;
	int rollno;
	char class;
	int marks[5];
}data;

void input(data *);
void display(data *,int );
void update(data *);
int search(data *);
void marks(data *);

int main(){

	int n,temp;
	data a, *studs;
	printf("Enter total number of students: ");
	scanf("%d",&n);

	studs=(data *)malloc(sizeof(a)*n);
	
	while(1)
	{
		printf("1:\tData Input\n2:\tDisplay all students data\n3:\tSearch and display specific data\n4:\tUpdate data\n5:\tTotal obtained marks\n0:\tExit\n");
		printf("Enter Choice:");
		scanf("%d",&temp);
		
		switch(temp){
			case 1:
				if(count<n)
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
				marks(studs);
				break;
			case 0:
				printf("=======================================EXITING=============================================");
				for(int j=0;j<count;j++)
				{
					free((studs+j)->name);
					free(studs+j);
				}
				studs->name=NULL;
				studs=NULL;
				exit(0);
			default:
				printf("Invalid Input\n");
				break;
				}
	}

}

void input(data *s)
{	char buff[20];

	printf("======================================================================\n");
	
	printf("Enter student name: ");
	__fpurge(stdin);
	scanf(" %s",buff);
	__fpurge(stdin);
	
	int i=strlen(buff);
	(s+count)->name=(char *)malloc(sizeof(char)*i);
	strcpy((s+count)->name,buff);
	
	printf("Enter student roll no: ");
	scanf("%d",&(s+count)->rollno);
	__fpurge(stdin);
	
	printf("Enter Division: ");
	scanf("%c",&(s+count)->class);
	__fpurge(stdin);

	for(i=0;i<5;i++)
	{
		printf("Enter marks of subject %s : ",subject[i]);
		scanf("%d",&(s+count)->marks[i]);
		__fpurge(stdin);
	}
	count++;
	printf("======================================================================\n");
}

void display(data *s,int i)
{
	printf("======================================================================\n");
	printf("Student Roll no: %d\n",(s+i)->rollno);
	printf("Student Name: %s\n",(s+i)->name);
	printf("Division: %c\n",(s+i)->class);
	
	for(int j=0;j<5;j++)
	{
		printf("Marks of subject %s : %d\n",subject[j],(s+i)->marks[j]);
	}
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
	printf("Modification: \n1. name\n2. marks\n");
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
		case 2:
			printf("Choose Subject:\n1. English\n2. Maths\n3. Physics\n4. Chemistry\n5. Biology\n");
			scanf("%d",&n);
			
			printf("Enter marks of subject %s : ",subject[n-1]);
			scanf("%d",&(s+i)->marks[n-1]);
			break;
		default:
			printf("Invalid Choice");
			break;
		}
	printf("======================================================================\n");
}

void marks(data *s)
{
	printf("======================================================================\n");
	int i=search(s);
	int t_marks=0;
	
	for(int j=0;j<5;j++)
	{
		t_marks=t_marks+(s+i)->marks[j];
	}
	printf("Total Marks of %s: %d\n",(s+i)->name,t_marks);
	printf("======================================================================\n");

}
