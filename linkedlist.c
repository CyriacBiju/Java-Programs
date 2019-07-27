#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *link;
}*front=NULL;

void createlist()
{
	front=NULL;
	printf("list created\n");
}	

void insbeg()
{	struct node *new;
	int n;
	new=(struct node*)malloc(sizeof(struct node));
	printf("Enter element to be inserted");
	scanf("%d",&n);
	new->data=n;
	new->link=front;
	front=new;
	printf("\nelement inserted\n");
}

void insend()
{	struct node *new,*temp=front;
	int n;
	new=(struct node*)malloc(sizeof(struct node));
	printf("Enter element to be inserted");
	scanf("%d",&n);
	new->data=n;
	new->link=NULL;
	if(front==NULL)
		front=new;
	else
	{	while(temp->link!=NULL)
			temp=temp->link;
		temp->link=new;
	}
	printf("\nelement inserted\n");
}

void delfirst()
{	struct node *temp=front;	
	if(front==NULL)
		printf("\nList empty\n");
	else if(front->link==NULL)
	{	front=NULL;
		printf("\nelement deleted\n");
	}
	else
	{	front=front->link;
		free(temp);
		printf("\nelement deleted\n");
	}
}

void dellast()
{	struct node *prev,*temp=front;
	if(front==NULL)
		printf("\nList empty\n");
	else if(front->link==NULL)
	{	front==NULL;
		printf("\nelement deleted\n");
	}
	else
	{	while(temp->link!=NULL)
		{	prev=temp;
			temp=temp->link;
		}
		prev->link=NULL;
		free(temp);
		printf("\nelement deleted\n");
	}
}
		
void insaftnode()
{	struct node *new,*temp=front;
	new=(struct node *)malloc(sizeof(struct node));
	int ins,n,f=0;
	if(front->link==NULL)
		insend();
	printf("Enter element to be inserted");
	scanf("%d",&ins);
	printf("Enter element after which to insert");
	scanf("%d",&n);
	new->data=ins;
	new->link=NULL;
	while(temp!=NULL)
	{	if(temp->data==n)
		{	f=1;
			break;
		}
		temp=temp->link;
	}
	if(f==1)
	{	new->link=temp->link;
		temp->link=new;
		printf("element inserted");
	}
	else
		printf("element not found");
}

void delvalnode()
{	struct node *del,*temp=front;
	int n;
	if(front==NULL)
		printf("list empty");
	else if(front->link==NULL)
	{	front==NULL;
		printf("\nelement deleted\n");
	}
	else
	{	printf("Enter element to be deleted");
		scanf("%d",&n);
		while(temp->link!=NULL && temp->data!=n)
		{	del=temp;
			temp=temp->link;
		}
		del->link=temp->link;
		free(temp);
		printf("\nelement deleted\n");	
	}
}

void display()
{	struct node *temp=front;
	if(front==NULL)
		printf("list empty");
	else if(front->link==NULL)
		printf("list is\n%d",front->data);
	else
	{	printf("list is\n");
		while(temp!=NULL)
		{	printf("%d ",temp->data);
			temp=temp->link;
		}
	}
}

void main()
{	
	int ch,ans;
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
		printf("\nEnter your choice");
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
			default:printf("\nInvalid input");
		}
		
	}while(ch!=9);
}
				   	

