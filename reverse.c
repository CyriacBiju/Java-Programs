#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node
{
	char ch;
	struct node *link;
}*head;


void main()
{
	int i;
	char str[10];
        printf("Enter the string");
	scanf("%s",&str);
        int l=strlen(str);
	struct node *fptr,*temp;
        fptr=(struct node *)malloc(sizeof(struct node *));
	fptr->ch=str[0];
	head=fptr;
	temp=fptr;
        struct node *ptr,*cur=head,*prev=NULL,*next;

        for(i=1;i<l;++i)
	{
		struct node *newptr;
		newptr=(struct node *)malloc(sizeof(struct node *));
		newptr->ch=str[i];
		temp->link=newptr;
		temp=temp->link;
        }
	        temp->link=NULL;
	        next=cur->link;
		prev=cur;
		cur->link=NULL;
		cur=next;
        

	for(i=1;i<l;++i)
        {
		next=cur->link;
                cur->link=prev;
		prev=cur;
		cur=next;
	}
	ptr=prev;
	for(i=0;i<l;++i)
	{
		printf("%c",ptr->ch);
		ptr=ptr->link;
	}
}


