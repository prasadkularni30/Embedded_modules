//program for storing student data musing sorted doubly linkedlist
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdio_ext.h>
struct node
{
    int age;
    int roll;
    char name[30];
    char address[40];
    struct node *next;
    struct node *prev;
};

void add(struct node **,int *);
void display(struct node *);
void search(struct node **,int *);
void delete(struct node **,int *);
int main() 
{
    int op,count=0;
    struct node *head=NULL;
    while(1)
    {
        printf("enter operation to do\n0.exit\n1.add\n2.search\n3.delete\n6.display\n");
        scanf("%d",&op);
        switch(op)
        {
            case 0:exit(0);
            case 1: add(&head,&count);
                    break;
            case 2: search(&head,&count);
                    break;
            case 3: delete(&head,&count);
                    break;
            case 6:display(head);
            default:printf("enter valid operation\n");

        }
    } 
    return 0;
}
void add(struct node **p,int *count)
{int flag=0;
    int rno,ag;
    char n[30];
    char ad[40];
     do
    {
    flag=0;
    printf("enter roll no\n");
    scanf("%d",&rno); 
    struct node *t1=*p;
    while(t1!=NULL)
    {
        if(rno==t1->roll)
        {
            printf("value is persent enter other value\n");
            flag=1;
            break;
        }
        t1=t1->next;
    }
    }while(flag==1);
    printf("enter name \n");
    __fpurge(stdin);
    scanf("%[^\n]s",n);
    __fpurge(stdin);
    printf("enter  age\n");
    scanf("%d",&ag);
    printf("enter address \n");
    __fpurge(stdin);
    scanf("%[^\n]s",ad);
    __fpurge(stdin);
    struct node *temp,*t1=*p;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->age=ag;
    temp->roll=rno;
    strcpy(temp->name,n);
    strcpy(temp->address,ad);
    temp->prev=NULL;
    temp->next=NULL;

    if(*p==NULL)
    {
        *p=temp;
    }
    else
    {
        if(rno<t1->roll)
        {
            temp->next=*p;
            *p=temp;
        }
        else
        {
        while((t1->next!=NULL) && (rno>t1->next->roll))
        {
            t1=t1->next;
        }
        if(t1->next==NULL)
        {
            temp->prev=t1;
            t1->next=temp;
        }
        else
        {
            temp->prev=t1;
            temp->next=t1->next;
            t1->next->prev=temp;
            t1->next=temp;
        }
        }
    }
    count ++;
}
void display(struct node *p)
{
    struct node *t1=p;
    if(p==NULL)
    {
        printf("list is empty\n");
        return ;
    }
    else
    {
        while(t1!=NULL)
        {
            printf("roll=%d\t",t1->roll);
            printf("name=%s\t",t1->name);
            printf("age=%d\t",t1->age);
            printf("address=%s\n",t1->address);
            t1=t1->next;
        }
        printf("\n");
    }
}
void search(struct node **p,int *count)
{
    struct node *t2,*t1=*p;
    int sno;
    printf("enter roll to search\n");
    scanf("%d",&sno);
    if(*p==NULL)
    {
        printf("list is empty\n");
        return;
    }
    if(t1->roll==sno)
    {
        printf("student is avilable\n");
                return;
    }
    else
    {
        int flag=0;
        while((t1)!=NULL)
        {

            if(sno==t1->roll)
            {
                flag=1;
            }

             t1=t1->next;
        }
        if(flag==0)
        {
            printf("student is not avilable\n");
                return;  
        }
        else
                 printf("student is avilable\n");
                return;
    }
}
void delete(struct node **p,int *count)
{
    struct node *t2=NULL,*t1=*p;
    int sno;
    printf("enter roll to search\n");
    scanf("%d",&sno);
    if(*p==NULL)
    {
        printf("list is empty\n");
        return;
    }
    if(t1->roll==sno)
    {
        t1->next->prev=*p;
       *p=t1->next;
    }
    else
    {
        while((t1)!=NULL)
        {
            t2=t1;
            
            if(sno==t1->roll)
            {
              t1->next->prev=t2;
              t2->next=t1->next;
              free(t1);
            }
            t1=t1->next;
        }
    }
    count--;
}
