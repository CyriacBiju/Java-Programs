#include<stdio.h>
#include<stdlib.h>
struct node
{
	int co;
	struct node *link;
}*head=NULL;
void main()
{
	int i,n,data;
	printf("Enter the highest power of polynomial:");
	scanf("%d",&n);
	struct node *temp=head;
        struct node *fptr;
	fptr=(struct node *)malloc(sizeof(struct node *));
	printf("\nEnter the coefficient for x^%d:",n);
	scanf("%d",&fptr->co);
	temp=fptr;
	head=fptr;
	for(i=n-1;i>=0;i--)
	{
		struct node *newptr;
		newptr=(struct node *)malloc(sizeof(struct node *));
		printf("\nEnter the coefficient for x^%d:",i);
		scanf("%d",&newptr->co);
		temp->link=newptr;
		temp=temp->link;
	}
	temp=head;
	printf("Polynomial:");
	for(i=n;i>=0;i--)
	{
		if(i==0)
			printf("%d ",temp->co);
		else
		{

		        printf("%dx^%d+",temp->co,i);
		        temp=temp->link;
		}
	}
}
