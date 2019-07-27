#include <stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *lsub,*rsub;
};

struct node* insert(struct node *root,int el){
    if(root==NULL){
        struct node *temp=(struct node*)malloc(sizeof(struct node));
        temp->data=el;
        temp->lsub=NULL;
        temp->rsub=NULL;
        root=temp;
        return root;
    }
    else if(root->data==el)
        printf("Value %d already exists\n",root->data);
    else if(root->data<el)
        root->rsub=insert(root->rsub,el);
    else 
        root->lsub=insert(root->lsub,el);
    return root;
}

struct node *del(struct node *root,int s){
    if(root==NULL){
    	printf("Element Not Found\n");
        return NULL;
    }
    if(root->data>s)
        root->lsub=del(root->lsub,s);
    else if(root->data<s)
        root->rsub=del(root->rsub,s);
    else{
        if(root->lsub==NULL)
            return root->rsub;
        else if(root->rsub==NULL)
            return root->lsub;
        struct node *temp=root->rsub;
        while(temp->lsub!=NULL)
            temp=temp->lsub;
        root->data=temp->data;
        root->rsub=del(root->rsub,temp->data);
    }
    return root;
}

void search(struct node *temp,int s){
    if(temp==NULL){
        printf("%d not Found\n",s);
        return;
    }
    else if(temp->data==s){
        printf("%d Found\n",s);
        return;
    }
    else if(temp->data>s)
        search(temp->lsub,s);
    else
        search(temp->rsub,s);
}

void inorderarray(struct node *root,int a[],int *i){
    if(root!=NULL){
	    inorderarray(root->lsub,a,i);
    	a[(*i)++] = root->data;
	    inorderarray(root->rsub,a,i);
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

void inorder(struct node *root){
    if(root==NULL)
        return;
    inorder(root->lsub);
    printf("%d ",root->data);
    inorder(root->rsub);
}

void preorder(struct node *root){
    if(root==NULL)
        return;
    printf("%d ",root->data);
    preorder(root->lsub);
    preorder(root->rsub);
}

void postorder(struct node *root){
    if(root==NULL)
        return;
    postorder(root->lsub);
    postorder(root->rsub);
    printf("%d ",root->data);
}

void main() {
	struct node *root=NULL;
	int ch,el,s;
	do{
    	printf("\nMENU : \n1.Insertion\n2.Deletion\n3.Search\n4.Find Successor\n5.Find Predecessor\n6.Inorder Traversal\n7.Preorder Traversal\n8.Post Order Traversal\n9.Exit\nEnter Choice : ");
    	scanf("%d",&ch);	
	if(ch==1){
	    printf("Enter Value to be inserted : ");
            scanf("%d",&el);
	    root=insert(root,el);
    	}
	else if(ch==2){
            printf("Enter element to be deleted : ");
            scanf("%d",&s);
	    root=del(root,s);
    	}
        else if(ch==3){
            printf("Enter node to be searched : ");
            scanf("%d",&s);
            search(root,s);
        }   
        else if(ch==4){
        	printf("Enter Element : ");
        	scanf("%d",&el);
        	successor(root,el);	
        }
        else if(ch==5){
        	printf("Enter Element : ");
        	scanf("%d",&el);
        	predecessor(root,el);	
        }
        else if(ch==6){
            inorder(root);
            printf("\n");
	}
        else if(ch==7){
            preorder(root);
            printf("\n");
        }
        else if(ch==8){
            postorder(root);
            printf("\n");
        }
    }while(ch!=9);
}  


