#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
}*rootptr=NULL;

struct node *insert(struct node *rootptr,int key)
{
    if(rootptr==NULL)
    {
    
    rootptr=(struct node *)malloc(sizeof(struct node));
    rootptr->data=key;
    rootptr->left=NULL;
    rootptr->right=NULL;
     }
    else 
    {
        if(key>rootptr->data)
        {
            rootptr->right=insert(rootptr->right,key);
        }
        else if(key<rootptr->data)
       {  
            rootptr->left=insert(rootptr->left,key);
	}

        else
            printf("\n duplicate node");    
    }    
      return rootptr;    
}


struct node *search(struct node *rp,int key)
{
    if(key==rp->data)
    {
        printf("Search successful");   
        return rp;
    }
    struct node *temp=rp;
    while(temp!=NULL)
    {
         if(key==temp->data)
         {
             printf("Search Successful");
             return rp;
         }
         else if(key<temp->data)
             temp=temp->left;
         else if(key>temp->data)
             temp=temp->right;
    }
}
struct node *suc(struct node *rootptr,int key)
{
     struct node *temp;
     temp=rootptr->right;   
     while(temp->left!=NULL)
     {
         temp=temp->left;
     }
     return temp;
}  
struct node *del(struct node *rp,int key)
{
     if(rp==NULL)
    {
        printf("Element no found");
        return rp;
    }
     else if(key>rp->data)
                 rp->right=del(rp->right,key);
     else if(key<rp->data)
                 rp->left=del(rp->left,key);
     else
     {
        
         if(rp->right==NULL)
                 return rp->left;

         else if(rp->left==NULL)
                 return rp->right;
         else
         {
              struct node *temp=rp->right;
              while(temp->left!=NULL)
              temp=temp->left;
              rp->data=temp->data;
              rp->right=del(rp->right,temp->data);
              free(temp);
         }
     }
         return rp;
   
}

void inorderarray(struct node *root,int a[],int *i){
    if(root!=NULL){
	    inorderarray(root->left,a,i);
    	a[(*i)++] = root->data;
	    inorderarray(root->right,a,i);
    }
}


void successor(struct node *root,int val){
	int a[25],len=0,i,j;
	inorderarray(root,a,&len);
	for(i=0;a[i]!=val && i<len;i++);
	if(i==len)
		printf("Element not Found\n");
	else if(i==len-1)
		printf("%d has no successor\n",a[len-1]);
	else
		printf("Successor : %d\n",a[i+1]);
}

void predecessor(struct node *root,int val){
	int a[25],len=0,i,j;
	inorderarray(root,a,&len);
	for(i=0;a[i]!=val && i<len;i++);
	if(i==len)
		printf("Element not Found\n");
	else if(i==0)
		printf("%d has no predecessor\n",a[0]);
	else
		printf("Predecessor : %d\n",a[i-1]);
}

void inorder(struct node *rp)
{
    if(rp==NULL)
     return;
      
    inorder(rp->left);
    printf("%d ",rp->data);

  inorder(rp->right);

}


void preorder(struct node *root){
    if(root==NULL)
        return;
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}
void postorder(struct node *rp)
{
    if(rp==NULL)
       return;
    
    postorder(rp->left);
    postorder(rp->right);
    printf("%d ",rp->data);   
}

void main()
{
    int data,ch;
    do
    {
         printf("\n\t\tMENU\n1.Insertion\n2.Deletion\n3.Search\n4.Successor\n5.Predeccessor\n6.Traversal-inorder\n7.Traversal-preorder\n8.Traversal-postorder\n9.Exit");
         printf("Enter choice");
         scanf("%d",&ch);
         switch(ch)
              {
                case 1:
                   {
                    printf("Enter the data");
                    scanf("%d",&data);
                    rootptr=insert(rootptr,data);
                    break;
                   }
                case 2:
                   {  
                    printf("Enter the data");
                    scanf("%d",&data);
                    rootptr=del(rootptr,data);break;
                   }
                case 3:
                   {
                    printf("Enter the data");
                    scanf("%d",&data);
                    struct node *temp;
                    temp=search(rootptr,data);break;
                   }
                case 4:
                   {
                    
                    printf("Enter the key");
                     scanf("%d",&data);
                    successor(rootptr,data);break;
                   }
                case 5:
                   {
                   printf("Enter the key");
                    scanf("%d",&data);
                   predecessor(rootptr,data);
                   break;
                   }
                case 6:
                   {
                   inorder(rootptr);                   
                   break;
                   }
                case 7:
                   {
                   preorder(rootptr); 
                   break;
                   }
                case 8:
                   {
                   postorder(rootptr); 
                   break;
                   }
                default:
                  printf("Invalid");
              }
    }while(ch!=9);
}
