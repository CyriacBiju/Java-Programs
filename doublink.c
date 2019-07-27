#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next,*prev;
}*front;

void createlist()
{
	front=NULL;
	printf("list created\n");
}	

void insbeg()
{	struct node *new;
	int n;
	new=(struct node*)malloc(sizeof(struct node));
	printf("Enter element to be inserted:");
	scanf("%d",&n);
	new->data=n;
	new->next=front;
	new->prev=NULL;
	front=new;
	printf("\nelement inserted\n");
}

void insend()
{	struct node *new,*temp=front;
	int n;
	new=(struct node*)malloc(sizeof(struct node));
	printf("Enter element to be inserted:");
	scanf("%d",&n);
	new->data=n;
	if(front==NULL)
		front=new;
	else
	{	while(temp->next!=NULL)
			temp=temp->next;
		temp->next=new;
		new->next=NULL;
		new->prev=temp;
	}
	printf("\nelement inserted\n");
}

void delfirst()
{	struct node *temp=front;	
	if(front==NULL)
		printf("\nList empty\n");
	else if(front->next==NULL)
	{	front=NULL;
		printf("\nelement deleted\n");
	}
	else
	{	front=front->next;
		front->prev=NULL;
		free(temp);
		printf("\nelement deleted\n");
	}
}

void dellast()
{	struct node *previous,*temp=front;
	if(front==NULL)
		printf("\nList empty\n");
	else if(front->next==NULL)
	{	front==NULL;
		printf("\nelement deleted\n");
	}
	else
	{	while(temp->next!=NULL)
		{	previous=temp;
			temp=temp->next;
		}
		previous->next=NULL;
		free(temp);
		printf("\nelement deleted\n");
	}
}
		
void insaftnode()
{	struct node *new,*temp=front;
	new=(struct node *)malloc(sizeof(struct node));
	int ins,n,f=0;
	if(front->next==NULL)
		insend();
	else
	{	printf("Enter element to be inserted:");
		scanf("%d",&ins);
		printf("Enter element after which to insert:");
		scanf("%d",&n);
		new->data=ins;
		while(temp!=NULL)
		{	if(temp->data==n)
			{	f=1;
				break;
			}
			temp=temp->next;
		}
		if(f==1)
		{	
			if(temp->next==NULL)
				insend();
			else
			{
				new->next=temp->next;
				temp->next->prev=new;
				new->prev=temp;
				temp->next=new;
				printf("element inserted");
			}
		}
		else
			printf("element not found");
	}
}

void delvalnode()
{	struct node *del,*temp=front;
	int n;
	if(front==NULL)
		printf("list empty");
	else if(front->next==NULL)
	{	front=NULL;
		printf("\nelement deleted\n");
	}
	else
	{	printf("Enter element to be deleted:");
		scanf("%d",&n);
		while(temp->next!=NULL && temp->data!=n)
		{	del=temp;
			temp=temp->next;
		}
		if(temp->next==NULL)
			dellast();
		if(temp->prev==NULL)
			delfirst();
		else
		{
			del->next=temp->next;
			temp->next->prev=del;
			free(temp);
			printf("\nelement deleted\n");	
		}
	}
}

void display()
{	struct node *temp=front;
	if(front==NULL)
		printf("list empty");
	else if(front->next==NULL)
		printf("list is\n%d",front->data);
	else
	{	printf("list is\n");
		while(temp!=NULL)
		{	printf("%d ",temp->data);
			temp=temp->next;
		}
	}
}

void main()
{	
	int ch;
	front=NULL;
	do
	{
		printf("\n MENU\n");
		printf("\n1. create list");
		printf("\n2. insert at beginning");
		printf("\n3. insert at end");
		printf("\n4. insert after particular node");
		printf("\n5. delete first node");
		printf("\n6. delete last node");
		printf("\n7. delete particular node");
		printf("\n8. display");
		printf("\n9. Exit");
		printf("\nEnter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:createlist();
				   break;
			case 2:insbeg();
				   break;
			case 3:insend();
				   break;
			case 4:insaftnode();
				   break;
			case 5:delfirst();
				   break;
			case 6:dellast();
				   break;
			case 7:delvalnode();
				   break;
			case 8:display();
				   break;
			case 9:exit(0);
			default:printf("\nInvalid input");
		}
	}while(1);
}
		
