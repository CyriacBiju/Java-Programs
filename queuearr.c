#include<stdio.h>
#include<stdlib.h>
#define size 1
int qu[20],front=-1,rear=-1;
void enqueue()
{
	int n;
	if(rear==size)
		printf("\nQueue overflow");
	else
	{	if(front==-1)
			front=0;
		printf("\nEnter element to be added: ");
		scanf("%d",&n);
		rear++;
		qu[rear]=n;
		printf("\nelement added");
	}
}

void dequeue()
{
	if(rear==-1 || front>rear)
		printf("\nQueue underflow");
	else if(front==rear)
		front=rear=-1;
	else
	{	front++;
		printf("\nElement deleted");
	}
}

void disp()
{
	int i;
	if(rear==-1 || front>rear)
		printf("Queue empty");
	else
	{	printf("\nQueue is\n");
		for(i=front;i<=rear;i++)
			printf("%d ",qu[i]);
		printf("\n");
	}
}

void main()
{
	int ch;
	char ans;
	do
	{
		printf("\n MENU\n");
		printf("\n1. Enqueue");
		printf("\n2. Dequeue");
		printf("\n3. Display");
		printf("\n4. Exit");
		printf("\nEnter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:enqueue();
				   break;
			case 2:dequeue();
				   break;
			case 3:disp();
				   break;
			case 4:exit(0);
			default:printf("\nInvalid input");
		}
		printf("\nDo you want to continue?(y/n)");
		scanf("%s", &ans);
	}while(ans=='y');
}
				   	
