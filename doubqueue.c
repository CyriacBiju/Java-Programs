#include<stdio.h>

int rear1=-1,front1=-1,rear2=-1,front2=-1;

void enqueue1(int a[],int s)
{
      int data;
      if(rear1+1==rear2)
      {
	      printf("Queue is full!!");

      }
      else if(rear1==-1)
      {
              printf("Enter the element for first queue:");
	     
	      scanf("%d",&data);
              printf("\nEnqueue 1 succesful!!");
	      rear1=rear1+1;
              front1=0;
	      a[rear1]=data;
      } 
      else
      {
	      printf("Enter the element for first queue:");
	      scanf("%d",&data);
	      printf("\nEnqueue 1 succesful!!");
              rear1=rear1+1;
	      a[rear1]=data;
      }
}

void enqueue2(int a[],int s)
{
      int data;
      if(rear2==rear1+1)
      {
	      printf("Queue is full!!");

      }
      else if(rear2==-1)
      {
              printf("Enter the element for second queue:");
	      scanf("%d",&data);
	      printf("\nEnqueue 2 succesful!!");

              rear2=s-1;
              front2=s-1;
	      a[rear2]=data;
      } 
      else
      {
	      printf("Enter the element for second queue:");
	       
	      scanf("%d",&data);
              printf("\nEnqueue 2 succesful!!");

	      rear2=rear2-1;
	      a[rear2]=data;
      }
}

void dequeue1(int a[])
{
    if((front1==-1)||(front1>rear1))
    {
        printf("first queue is empty!!");
	front1=rear1=-1;
    }

    else if(front1+1==rear2)
    {
        printf("Dequeued element from first queue:%d",a[front1]);
        front1=rear1=-1;
    }
    else
    {
       
        printf("Dequeued element from first queue:%d",a[front1]);
        front1=front1+1;

    }
}
void dequeue2(int a[])
{
    	
    if((front2==-1)||(front2<rear2))
    {
        printf("second queue is empty!!");
	front2=rear2=-1;
    }

    else if(front2==rear1+1)
    {
        printf("Dequeued element from second queue:%d",a[front2]);
        front2=rear2=-1;
    }
    else
    {
       
        printf("Dequeued element from second queue:%d",a[front2]);
        front2=front2-1;

    }
}

void display(int a[])
{
    int i=0;	
    printf("Front1--->");
    for(i=front1;i<=rear1;i++)
	printf("%d,",a[i]);
    printf("<---Rear1 Rear2--->");
    for(i=rear2;i<=front2;i++)
	printf("%d,",a[i]);
    printf("<---Front2");
}
void main()
{
    int c,s,a[50];
    printf("Enter the queue size");
    scanf("%d",&s);
    do
    {
        printf("\n  MENU: \n\t1.enqueue1 \n\t2.enqueue2 \n\t3.dequeue1 \n\t4.dequeue2 \n\t5.display \n\t6.exit");
 	printf("\nSelect your option:\n");
	scanf("%d",&c);
        switch(c)
        {
		case 1:
			{
				Enqueue1(a,s);
				break;
			}
		case 2:
			{
				Enqueue2(a,s);
				break;
			}
		case 3:
			{
				Dequeue1(a);
				break;
			}
		case 4:
			{
				Dequeue2(a);
				break;
			}
		case 5:
			{
				Display(a);
				break;
			}
		case 6:
			{
				break;
			}
	}
    }while(c!=6);
}



		    	

