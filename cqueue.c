#include<stdio.h>

void enqueue(int *fr,int *re,int *qs,int a[],int n)
{
  int data;
  
  if(*re==-1)
  { 
      printf("Enter the data");
  scanf("%d",&data);  
      *fr=0;
      *re=0;
      *qs=0;
      a[*re]=data;
  }
  else if(((*re==n-1)&&(*fr==0))||(*fr==*re+1))
  {
      printf("Overflow");
  }
  else if(*re==n-1)
  {
      printf("Enter the data");
  scanf("%d",&data);  
      *re=0;
      *qs=*qs+1;
      a[*re]=data;
  } 
  else
  {
  printf("Enter the data");
  scanf("%d",&data);  
      *re=*re+1;
      *qs=*qs+1;
      a[*re]=data;
  }
}

void dequeue(int *fr,int *re,int *qs,int a[],int n)
{
  if(*fr==-1)
      {
        printf("underflow");
      }
 else if(*fr==*re)
     {
        printf("The deleted element is %d",a[*fr]);
        *fr=*re=-1;
        *qs=*qs-1;
     }
 else if(*fr==n-1)
     {
        printf("Deleted element is %d",a[*fr]);
        *fr=0;
        *qs=*qs-1;
     }

 else 
     {
        printf("Deleted element is %d",a[*fr]);
        *fr=*fr+1;
        *qs=*qs-1;
     }
}

void display(int *fr,int *re,int *qs,int a[],int n)
{
    
    if(*fr==-1)
    { 
      printf("Queue empty");
    }
         
    int i,j=*fr;
    for(i=0;i<=*qs;++i)
        {
          printf("\n%d",a[j]);
          j++;
          if(j>(n-1))
              {
                j=0;
              }
        }
}

void main()
{
    int a[20],n,data,front=-1,rear=-1,ch,qsize=-1;
    printf("Enter size of queue");
    scanf("%d",&n);
    do
    {
         printf("\n\t\tMENU\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit");
         printf("\nEnter choice");
         scanf("%d",&ch);
         switch(ch)
              {
                case 1:
                   {
                      
                      enqueue(&front,&rear,&qsize,a,n);break;
                   }
                case 2:
                   {dequeue(&front,&rear,&qsize,a,n);break;}
                case 3:
                   {display(&front,&rear,&qsize,a,n);break;}
                default:
                    break;
               }
    }while(ch!=4);
}
