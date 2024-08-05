#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};


void enqueue(struct node **,struct node **,int); 
int dequeue(struct node **,struct node **);
void delete_queue(struct node **,struct node **);
void display(struct node *);

int count = 0;

int main()
{
    struct node *front = NULL;
    struct node *rear = NULL;
    
    int choice, ele, ret;
    
    printf("Queue using Linked List\n");
    while (1) 
    {
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Delete Queue\n0.Exit\n");
        printf("Enter your choice: \n");
        scanf("%d", &choice);
        switch (choice) 
        {
            case 1:
                printf("Enter the value to enqueue\n");
                scanf("%d", &ele);
                enqueue(&front,&rear,ele);
                break;
            case 2:
                ret = dequeue(&front,&rear);
		if(ret !=-1)
		{
			printf("dequeued element:%d\n",ret);
		}
                break;
            case 3:
                display(front);
                break;
            case 4:
                delete_queue(&front,&rear);
                break;
            case 0:
                exit(0);
                break;
            default:
                printf("Wrong Choice\n");
        }
    }
    return 0;
}
void enqueue(struct node **front,struct node **rear,int ele) {
    if (count == 10) {
        printf("Queue is full\n");
        return;
    }

    struct node* temp = (struct node*)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Memory not allocated\n");
        return;
    }

    temp->data = ele;
    temp->next = NULL;

    if (*front == NULL) {
        *front = temp;
        *rear = temp;
    } else {
        (*rear)->next = temp;
        *rear = temp;
    }

    count++;
    printf("%d enqueued to queue\n", ele);
}

int dequeue(struct node **front,struct node **rear) {
    if (*front == NULL) {
        printf("Queue is empty\n");
        return -1;
    }

    int ele = (*front)->data;
    struct node* temp;
    temp=*front;
    *front = (*front)->next;

    if (*front == NULL) {
        *rear = NULL;
    }

    free(temp);
    count--;
    return ele;
}

void delete_queue(struct node **front,struct node **rear) 
{
    while (*front!= NULL) 
    {
        struct node* temp;
	temp=*front;
        *front = (*front)->next;
        free(temp);
    }

    *rear = NULL;
    count = 0;
    printf("Queue deleted\n");
}

void display(struct node *front) {
    struct node* t1;
    t1=front;
    if(front==NULL)
    {
	    printf("queue is empty\n");
    }
    while (t1!= NULL) {
        printf("-->%d ", t1->data);
        t1 = t1->next;
    }
    printf("\n");
}


