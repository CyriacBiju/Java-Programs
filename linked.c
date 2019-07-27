#include<stdio.h>

struct node
{
    int data;
    struct node *link;
}*heap=NULL;

void insert(int pos)
{
    int i=0;
    struct node *newptr,*temp=heap;
    newptr=(struct node *)calloc(sizeof(struct node));
    newptr->data=data;
    newptr->link=NULL;
    if(heap==NULL)
        {
            heap=newptr;
        }
    else
        {
         while((temp!=NULL)||i<=pos-2)
            {
             temp=temp->link;
            }
         newptr->link=temp;
         temp=newptr;
         
}

void del(int pos)
{
    int i=0;
