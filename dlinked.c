#include<stdio.h>
#include<stdlib.h>
//My program-doubly linked list,but dellast() not working
struct node
{
    int data;
    struct node *prev;
    struct node *next; 
}*heap=NULL,*tail=NULL;

void create()
{
    heap==NULL;
}

void insertbeg(int data)
{
    struct node *newptr;
    newptr=(struct node *)malloc(sizeof(struct node));
    newptr->data=data;
    newptr->prev=NULL;
    newptr->next=NULL;
    if(heap==NULL)
        {
            heap=tail=newptr;
        }
    else
        {
            newptr->next=heap;
            heap=newptr;   
        }
}

void insertvalue(int data1,int value)
{
    struct node *newptr,*temp=heap;
    int flag=1;
    newptr=(struct node *)malloc(sizeof(struct node));
    newptr->data=data1;
    newptr->next=NULL;
    newptr->prev=NULL;
    while(temp!=NULL)
        {
             if(temp->data==value)
                {
                 newptr->next=temp->next;
                 newptr->prev=temp;
                 temp->next=newptr;
                 flag=0;
                 printf("Value inserted");
                 break;
                }
             temp=temp->next;
        }
    if(flag==1)
       printf("Element not found");
}

void insertend(int data)
{
    struct node *newptr;
    newptr=(struct node *)malloc(sizeof(struct node));
    newptr->data=data;
    newptr->next=NULL;
    newptr->prev=NULL;
    if(tail==NULL)
        {
            heap=tail=newptr;
        }
    else
        {
            tail->next=newptr;
            newptr->prev=tail;
            tail=newptr;   
        }
}

void delfirst()
{
    struct node *temp=heap;
    if(heap==NULL)
        {printf("No element to delete");return;}
    heap=heap->next;
    free(temp);
    if(heap==NULL)
        tail=NULL;
    printf("Deleted");
}

void dellast()
{
    struct node *temp=heap;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }

    temp=temp->prev;
    temp->next=NULL;
    
    printf("Deleted");
}

void delvalue(int value)
{
    struct node *temp=heap,*del;
    if(heap==NULL)
        {printf("No element to delete");return;}
    if(temp->data==value)
    {
     delfirst();return;
    }
    while((temp->next)->data!=value)
    {
        temp=temp->next;
    }
    del=temp->next;
    temp->next=del->next;
    (del->next)->prev=temp;
    free(del);
    printf("Deleted");
   
}
void display()
{
    struct node *temp=heap;
    if(heap==NULL)
       {printf("No element to display");}
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
}

void main()
{
    int data,ch;
    do
    {
         printf("\n\t\tMENU\n1.Create an Empty list\n2.Insert value at beginning\n3.Insert value at end\n4.Insert value after particular value\n5.Delete first node\n6.delete last node\n7.Delete node with particular value\n8.Display the contents\n9.Exit");
         printf("Enter choice");
         scanf("%d",&ch);
         switch(ch)
              {
                case 1:
                   {create();break;}
                case 2:
                   { printf("Enter the data");
                     scanf("%d",&data);
                    insertbeg(data);break;
                   }
                case 3:
                   {printf("Enter the data");
                     scanf("%d",&data);
                    insertend(data);break;
                   }
                case 4:
                   {
                   int value;
                   printf("Enter the data");
                     scanf("%d",&data);
                    printf("Enter the value");
                     scanf("%d",&value);
                    insertvalue(data,value);break;
                  }
                case 5:
                  {
                   delfirst();
                   break;
                  }
                case 6:
                  {
                   dellast();
                   break;
                  }
                case 7:
                  {
                   int value;
                   printf("Enter the value");
                   scanf("%d",&value);
                   delvalue(value);
                   break;
                  }
                case 8:
                  {
                   display();
                   break;
                  }
                default:
                  printf("Invalid");
              }
    }while(ch!=9);
}

