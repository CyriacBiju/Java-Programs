#include<stdio.h>
#include<stdlib.h>

void disp(int st[],int top)
{
	int i;
	if(top==-1)
		printf("Stack empty\n");
	else
	{   printf("\n Current stack is\n");
		for(i=0;i<=top;i++)
			printf("%d \n",st[i]);
	}
}

int push(int st[],int top)
{
	int n;
	if(top==3)
	{	printf("Stack full");
		return top;
	}
	else
	{	
		printf("\nEnter element to be added:");
		scanf("%d",&n);
		top++;
		st[top]=n;
		disp(st,top);
		return top;
	}
}

int pop(int st[],int top)
{
	if(top==-1)
	{	printf("Stack Empty");
		return top;
	}
	else
	{	
		printf("%d is deleted",st[top]);
		top--;
		return top;
	}
}

void main()
{
	int st[100],top=-1,ch,ret;
	char ans;
	do
	{
		printf("MENU\n");
		printf("1. Push\n");
		printf("2. Pop\n");
		printf("3. Display\n");
		printf("4. Exit\n");
		printf("\nEnter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:top=push(st,top);
			       break;    
			case 2:top=pop(st,top);
		           break;
			case 3:disp(st,top);
		           break;
			case 4:exit(0);
			       break;
		}
		printf("\nDo you want to continue?(y/n): ");
		scanf("%s",&ans);
	}while(ans=='y');
}		
		
		
		
		
		
		
		
		
		
