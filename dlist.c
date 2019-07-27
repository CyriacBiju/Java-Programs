#include<stdio.h>
#include<stdlib.h>

struct node
{int data;
 struct node *next;
  struct node *prev;
 }*head=NULL;


 void insertbeg()
 { 
   
   struct node *newptr;
   int ele;
   printf("enter the element");
   scanf("%d",&ele);
   newptr=(struct node *)malloc(sizeof(struct node));
   newptr->data=ele;
   if(head==NULL)
   head=newptr;
   else
   {
   newptr->next=head;
   newptr->prev=NULL;
   head->prev=newptr;
   head=newptr;
   }
   printf("inserted at beg");
  
 }
 
 void insertend()
  {struct node *newptr;
   struct node *ptr;
   int ele;
   printf("enter the element");
   scanf("%d",&ele);
   newptr=(struct node *)malloc(sizeof(struct node));
   newptr->data=ele;
   if(head==NULL)
   head=newptr;
   else
   {
   ptr=head;
   while(ptr->next!=NULL)
   {ptr=ptr->next;
   }
   ptr->next=newptr;
   newptr->prev=ptr;
   newptr->next=NULL;
  }
  }
 
  void insert()
  {struct node *newptr;
   struct node *ptr,*temp;
   int ele,pos,flag=0;
   printf("enter the element after which you want to insert");
   scanf("%d",&pos);
   printf("enter the element");
   scanf("%d",&ele);
   newptr=(struct node *)malloc(sizeof(struct node));
   newptr->data=ele;
   ptr=head;
   while(ptr!=NULL)
   {if(ptr->data==pos)
    {temp=ptr;
     flag=1;
     break;
     }
    ptr=ptr->next;
   }
   if(flag==1)
   {if(temp->next==NULL)
    insertend();
    else
    {
   newptr->next=temp->next;
   (temp->next)->prev=newptr;
   newptr->prev=temp;
   temp->next=newptr;
   }
   }
   else
   printf("elment not found");
   }
  
  
  void delbeg()
  {struct node *newptr;
   newptr=head;
   head=head->next;
   head->prev=NULL;
  }
  
  void delend()
  {struct node *ptr;
   ptr=head;
   while(ptr->next!=NULL)
   {
    ptr=ptr->next;
   }
   ptr=ptr->prev;
   ptr->next=NULL;
  }
  
  void delete()  
  {struct node *newptr;
   struct node *ptr,*temp;
   int ele,pos,flag=0;
   printf("enter the element you want to delete");
   scanf("%d",&pos);
   ptr=head;
   while(ptr!=NULL)
   {if(ptr->data==pos)
    {temp=ptr;
     flag=1;
     break;
     }
    ptr=ptr->next;
   }
   if(flag==1)
   {if(temp->prev==NULL)
    delbeg();
    else if(temp->next==NULL)
    delend();
    else
    {
    newptr=temp->prev;
    newptr->next=temp->next;
    temp=temp->next;
    temp->prev=newptr;
    }
    }
   else
   printf("elment not found");
  }
  
  void display()
  {struct node *ptr;
    if(head==NULL)
    printf("empty");
    else if(head->next==NULL)
    printf("%d",head->data);
    else
    {ptr=head;
     printf("%d",ptr->data);
     ptr=ptr->next;
      while(ptr->next!=NULL)
    {printf("\t%d",ptr->data);
     ptr=ptr->next;
}    
    printf("\t%d",ptr->data);
    }
  }
  
  void main()
{int c,a=1;
do{
 printf("\n\n\n1.create an empty list\n2.Insert at begining\n3.Insert at end\n4.Insert a value after a particular node\n5.Delete first node\n6.Delete last node\n7.Delete a node with a particular value\n8.Display\n9.exit\nenter your choice:");
 scanf("%d",&c);
 
 switch(c)
 {case 1:
  head=NULL;
  printf("created list");
  break;
  case 2:
  insertbeg();
  break;
  case 3:
  insertend();
  break;
  case 4:
  insert();
  break;
  case 5:
  delbeg();
  break;
  case 6:
  delend();
  break;
  case 7:
  delete();
  break;
  case 8:
  display();
  break;
  case 9:
  a=0;
  break;
  }
 
   }while(a==1);
  }      
  
 
 
