#include<stdio.h>
#include<stdlib.h>

void enqueue(int a[],int n,int *fr,int *re)
{
    int data;
    if(*re==n-1)
        {
         printf("Queue is full");
        }
    else 
        {
         *re=*re+1;
         printf("Enter data");
         scanf("%d",&data);
         a[*re]=data;
        }
    if(*re==0)
        *fr=0;
}

void dequeue(int a[],int n,int *fr,int *re)
{
    if((*fr==-1)||(*fr>*re))
        {
          printf("Queue is empty");
        }
    else
        {
          printf("Deleted element is %d",a[*fr]);
          *fr=*fr+1;
        }
    if(*fr==n)
       *fr=*re=-1;
   
}
void display(int a[],int n,int *fr,int *re)
{
    int i=*fr;
    if(*fr==-1)
        {
          printf("No element in queue");
        }
    for(i;i<=*re;i++)
        {
          printf("\n%d",a[i]);
        }
}
void main()
{
    int a[20],n,front=-1,rear=-1,ch;
    printf("Enter size of queue");
    scanf("%d",&n);
    do
    {
         printf("\n\t\tMENU\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit");
         printf("Enter choice");
         scanf("%d",&ch);
         switch(ch)
              {
                case 1:
                   {enqueue(a,n,&front,&rear);break;}
                case 2:
                   {dequeue(a,n,&front,&rear);break;}
                case 3:
                   {display(a,n,&front,&rear);break;}
                default:
                    break;
               }
    }while(ch!=4);
}
