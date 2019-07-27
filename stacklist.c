#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *link;
}*top=NULL;

void push(int data)
{
    struct node *newptr;
    newptr=(struct node *)malloc(sizeof(struct node));
    newptr->data=data;
    if(top==NULL)
        {
            top=newptr;
        }
    else
        {
            newptr->link=top;
            top=newptr;   
        }
}

void pop()
{
    struct node *temp=top;
    if(top==NULL)
        {printf("No element to delete");return;}
    top=top->link;
    printf("Deleted element is %d",temp->data);
    free(temp);
}

void display()
{
    struct node *temp=top;
    if(top==NULL)
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
         printf("\n\t\tMENU\n1.Push \n2.Pop \n3.Display \n4.Exit");
         printf("Enter your choice");
         scanf("%d",&ch); 
         switch(ch)
             {
                  case 1:
                  {
                       printf("Enter the data");
                       scanf("%d",&data);
                       push(data);
                       break;
                  }
                  case 2:
                  {
                       pop();
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
