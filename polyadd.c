#include<stdio.h>
#include<stdlib.h>
struct node
{
	int co;
	int pow;
	struct node *link;
}*head1=NULL,*head2=NULL;
void main()
{
	int i,n1,n2,c1,c2,data;
	printf("Enter the highest power of polynomial1:");
	scanf("%d",&n1);
	c1=n1;
	struct node *temp1=head1;
        struct node *fptr1;
	fptr1=(struct node *)malloc(sizeof(struct node *));
	printf("Enter the coefficient for x^%d:",n1);
	scanf("%d",&fptr1->co);
	fptr1->pow=n1;
	temp1=fptr1;
	head1=fptr1;
	for(i=n1-1;i>=0;i--)
	{
		struct node *newptr;
		newptr=(struct node *)malloc(sizeof(struct node *));
		printf("Enter the coefficient for x^%d:",i);
		scanf("%d",&newptr->co);
		newptr->pow=i;
                newptr->link=NULL;
		temp1->link=newptr;
		temp1=temp1->link;
	}
	temp1=NULL;
        printf("\nEnter the highest power of polynomial2:");
	scanf("%d",&n2);
	c2=n2;
	struct node *temp2=head2;
        struct node *fptr2;
	fptr2=(struct node *)malloc(sizeof(struct node *));
	printf("Enter the coefficient for x^%d:",n2);
	scanf("%d",&fptr2->co);
	fptr2->pow=n2;
	temp2=fptr2;
	head2=fptr2;
	for(i=n2-1;i>=0;i--)
	{
		struct node *newptr;
		newptr=(struct node *)malloc(sizeof(struct node *));
		printf("Enter the coefficient for x^%d:",i);
		scanf("%d",&newptr->co);
		newptr->pow=i;
                newptr->link=NULL;
		temp2->link=newptr;
		temp2=temp2->link;
	}
        temp1=head1;
	temp2=head2;
	while((c1>=0)&&(c2>=0))
	{
		if(c2>c1)
		{
			printf("%dx^%d+",temp2->co,c2);
		        temp2=temp2->link;
		        c2=c2-1;	

		}
		else if(c1>c2)
		{
			printf("%dx^%d+",temp1->co,c1);
		        temp1=temp1->link;
		        c1=c1-1;
		}
	        else if((c1==0)&&(c2==0))
		{
			printf("%d",temp2->co+temp1->co);
		        temp2=temp2->link;
			temp1=temp1->link;
			c1=c1-1;
		        c2=c2-1;
		}
                else
		{
			printf("%dx^%d+",temp2->co+temp1->co,c2);
		        temp2=temp2->link;
			temp1=temp1->link;
			c1=c1-1;
		        c2=c2-1;
		}

	}	
      

}
