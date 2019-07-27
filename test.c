#include<stdio.h>

struct node
{
	int c;
	struct node *link;
}*head=NULL;

void main()
{
	struct node *temp=head;
	struct node *new;
	new=(struct node *)malloc(sizeof(struct node *));
	new->c=12;
	head=new;
	printf("%p",temp);
	printf("%p",new);
}
