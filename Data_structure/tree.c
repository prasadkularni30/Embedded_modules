#include<stdio.h>
#include<stdlib.h>

struct node{
	struct node *left;
	int data;
	struct node *right;
};

void insert(struct node **, int );
void in_order(struct node *);
void pre_order(struct node *);
void post_order(struct node *);
int search(struct node *,int );

int main()
{
	struct node *root;
	int choice=1,ele,i;
	root=NULL;
	
	if(root!=NULL)
	{
		printf("Tree not empty\n");
		exit(0);
	}	
	
	while(choice)
	{
		printf("\n(1)Insert\n(2)In order Display\n(3)pre order display\n(4)post order display\n(5)search(0)Exit\n");
		printf("Enter choice: ");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:
				printf("Enter Element: ");
				scanf("%d",&ele);
				insert(&root,ele);
				break;
			case 2:
				if(root==NULL)
				{
					printf("No nodes\n");
					break;
				}
				printf("In-Order Display: \n");
				in_order(root);
				break;
			case 3:
				if(root==NULL)
				{
					printf("No nodes\n");
					break;
				}
				printf("Pre-Order Display: \n");
				pre_order(root);
				break;
			case 4:
				if(root==NULL)
				{
					printf("No nodes\n");
					break;
				}
				printf("Post-Order display\n");
				post_order(root);
				break;
			case 5:
				printf("Enter Element: ");
				scanf("%d",&ele);
				i=search(root,ele);
				
				if(i==1)
					printf("Element present in tree\n");
				else
					printf("Element not present\n");
					break;
			default:
				printf("Invalid choice\n");
				break;
		}
		
	}
	
}

void insert(struct node **r, int ele)
{
	if((*r)==NULL)
	{
		*r=(struct node*)malloc(sizeof(struct node));
		(*r)->data=ele;
		(*r)->left=NULL;
		(*r)->right=NULL;

	}
	else
	{
		if(ele>=(*r)->data)
		{
			insert(&(*r)->right,ele);
		}
		else
		{
			insert(&(*r)->left,ele);
		}
	}
	
}

void in_order(struct node *r)
{
	if(r!=NULL)
	{
		in_order(r->left);
		printf("-->%d",r->data);
		in_order(r->right);
	}
}

void pre_order(struct node *r)
{
	if(r!=NULL)
	{
		printf("-->%d",r->data);
		pre_order(r->left);
		pre_order(r->right);
	}
}
void post_order(struct node *r)
{
	if(r!=NULL)
	{
		post_order(r->left);
		post_order(r->right);
		printf("-->%d",r->data);
	}
}


int search(struct node *r, int ele)
{
	//struct node *t=r;
	
	
	if(r!=NULL)
	{
		if(ele==(r)->data)
			return 1;
		
		if(ele>=(r)->data)
		{
			return search((r)->right,ele);
		}
		else
		{
			return search((r)->left,ele);
		}
	}
	return -1;
	
}
