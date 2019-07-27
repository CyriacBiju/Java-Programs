#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *link;
}*front=NULL,*rear=NULL;

void enqueue(int data)
{
    struct node *newptr;
    newptr=(struct node *)malloc(sizeof(struct node));
    newptr->data=data;
    newptr->link=NULL;
    if(rear==NULL)
        {
            rear=front=newptr;
        }
    else
        {
            rear->link=newptr;
            rear=newptr;
        }
}

void dequeue()
{
    struct node *temp=front;
    if(front==NULL)
        {printf("No element to delete");return;}
    front=front->link;
    printf("Deleted element is %d",temp->data);
    free(temp);
    if(front==NULL)
        rear=NULL;
}

void display()
{
    struct node *temp=front;
    if(front==NULL)
       {printf("No element to display");
        return;
       }
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->link;
    }
}

void main()
{
    int data,ch;
    do
    {
         printf("\n\t\tMENU\n1.Enqueue \n2.Dequeue \n3.Display \n4.Exit");
         printf("Enter your choice");
         scanf("%d",&ch); 
         switch(ch)
             {
                  case 1:
                  {
                       printf("Enter the data");
                       scanf("%d",&data);
                       enqueue(data);
                       break;
                  }
                  case 2:
                  {
                       dequeue();
                       break;
                  }
                  case 3:
                  {
                       display();
                       break;
                  }
                  case 4:
                       break;
                  default:
                       printf("Invalid input");
             }
    }while(ch!=4);
}         
