    #include <stdio.h>
    #include <stdlib.h>
     
    struct node
    {
    	int data;
    	struct node *leftptr, *rightptr;
    }*root = NULL;
     
    int flag1 = 0, flag2 = 0;
     
    struct node* findsuccessor(struct node *rootptr)
    {
    	if(root == NULL)
    		return NULL;
     
    	else if(root->data < rootptr->data)
    	{
    		root = root->rightptr;
    		return findsuccessor(rootptr);
    	}
     
    	else if(root->leftptr == NULL && root->rightptr == NULL && flag1 != 1)
    		return NULL;
    		
    	else if(root->leftptr->data > rootptr->data)
    	{
    		root = root->leftptr;
    		flag1 = 1;
    		return findsuccessor(rootptr);
    	}
     
    	else
    		return root;
    }
     
    struct node* findpredecessor(struct node *rootptr)
    {
    	if(root == NULL)
    		return NULL;
     
    	else if(root->data > rootptr->data)
    	{ 
    		root = root->leftptr;
    		return findpredecessor(rootptr);
    	}
     
    	else if(root->leftptr == NULL && root->rightptr == NULL && flag2 != 1)
    		return NULL;
    	
    	else if(root->rightptr->data < rootptr->data) 
    	{
    		root = root->rightptr;
    		flag2 = 1;
    		return findpredecessor(root);
    	}
     
     
    	else
    		return root;
     
    }
     
    struct node* successor(struct node *rootptr)
    {
    	if(rootptr == NULL);
     
    	else if(rootptr->rightptr != NULL)
    	{
    		rootptr = rootptr->rightptr;
    		while(rootptr->leftptr!=NULL)
    			rootptr = rootptr->leftptr;
    		return rootptr;
    	}
     
    	if(rootptr->rightptr == NULL)
    		return findsuccessor(rootptr);
    	return rootptr;
    }
     
    struct node* predecessor(struct node *rootptr)
    {
    	if(rootptr == NULL);
     
    	if(rootptr->leftptr != NULL)
    	{
    		rootptr = rootptr->leftptr;
    		while(rootptr->rightptr!=NULL)
    			rootptr = rootptr->rightptr;
    	}
     
    	else if(rootptr->leftptr == NULL)
    		return findpredecessor(rootptr);
     
    		return rootptr;
    }
     
    struct node *insert(struct node *rootptr, int element)
    {
    	if(rootptr == NULL)
    	{
    		struct node *newptr = (struct node*)malloc(sizeof(struct node));
    		newptr->data = element;
    		newptr->leftptr = newptr->rightptr = NULL;
     
    		rootptr = newptr;
    	}
     
    	else if(rootptr->data > element)
    		rootptr->leftptr = insert(rootptr->leftptr, element);
     
    	else if(rootptr->data < element)
    		rootptr->rightptr = insert(rootptr->rightptr, element);
     
    	else
    		printf("\nDuplicate element entered!");
     
    	return rootptr;
    }
     
    struct node* delete(struct node *rootptr, int element)
    {
    	if(rootptr == NULL)
    		printf("\nCannot be deleted");
     
    	else if(rootptr->data > element)
    		rootptr->leftptr = delete(rootptr->leftptr, element);
     
    	else if(rootptr->data < element)
    		rootptr->rightptr = delete(rootptr->rightptr, element);
     
    	else
    	{
    		if(rootptr->leftptr == NULL)
    			rootptr = rootptr->rightptr;
     
    		else if(rootptr->rightptr == NULL)
    			rootptr = rootptr->leftptr;
     
    		else
    		{
    			struct node *suck = successor(rootptr);
    			rootptr->data = suck->data;
    			rootptr->rightptr = delete(rootptr->rightptr, suck->data);
    		}
    	}
    	return rootptr;
    }
     
    struct node* search(struct node *rootptr, int element)
    {
    	if(rootptr == NULL)
    		printf("\nElement not found!");
     
    	else if(rootptr->data == element)
    		printf("\nElement found");
     
    	else if(rootptr->data > element)
    		rootptr = search(rootptr->leftptr, element);
     
    	else
    		rootptr = search(rootptr->rightptr, element);
     
    	return rootptr;
    }
     
    void inordertraversal(struct node *rootptr)
    {
    	if(rootptr == NULL)
    		return;
     
    	inordertraversal(rootptr->leftptr);
    	printf("%d ", rootptr->data);
    	inordertraversal(rootptr->rightptr);
    }
     
    void preordertraversal(struct node *rootptr)
    {
    	if(rootptr == NULL)
    		return;
     
    	printf("%d ", rootptr->data);
    	preordertraversal(rootptr->leftptr);
    	preordertraversal(rootptr->rightptr);
    }
     
    void postordertraversal(struct node *rootptr)
    {
    	if(rootptr == NULL)
    		return;
     
    	postordertraversal(rootptr->leftptr);
    	postordertraversal(rootptr->rightptr);
    	printf("%d ", rootptr->data);
    }
     
     
    void main()
    {
    	struct node *rootptr = NULL, *temp, *ptr;
    	int choice, element;
     
    	do
    	{
    		printf("\n\nMENU");
    		printf("\n1. Insert");
    		printf("\n2. Deletion");
    		printf("\n3. Search");
    		printf("\n4. Successor");
    		printf("\n5. Predecessor");
    		printf("\n6. Inorder Traversal");
    		printf("\n7. Preorder Traversal");
    		printf("\n8. Postorder Traversal");
    		printf("\n9. Exit");
     
    		printf("\nEnter choice : ");
    		scanf("%d", &choice);
     
    		switch(choice)
    		{
    			case 1: printf("Enter element : ");
    				scanf("%d", &element);
    				rootptr = insert(rootptr, element);
    				root = rootptr;
    				break;
     
    			case 2: printf("Enter element : ");
    				scanf("%d", &element);
    				rootptr = delete(rootptr, element);
    				break;
     
    			case 3: printf("Enter element : ");
    				scanf("%d", &element);
    				temp = search(rootptr, element);
    				break;
     
    			case 4: printf("Enter element : ");
    				scanf("%d", &element);
    				temp = search(rootptr, element);
    				if(temp == NULL);
     
    				else
    				{
    					ptr = successor(temp);
    					if(ptr == NULL)
    						printf(" but successor does not exist!");
     
    					else
    						printf("\nSuccessor is %d", ptr->data);
    				}
    				flag1 = 0;
    				break;
     
    			case 5: printf("Enter element : ");
    				scanf("%d", &element);
    				temp = search(rootptr, element);
    				if(temp == NULL);
     
    				else
    				{
    					ptr = predecessor(temp);
    					if(ptr == NULL)
    						printf(" but predecessor does not exist!");
     
    					else
    						printf("\nPredecessor is %d", ptr->data);
    				}
    				flag2 = 0;
    				break;
     
    			case 6: inordertraversal(rootptr);
    				break;
     
    			case 7: preordertraversal(rootptr);
    				break;
     
    			case 8: postordertraversal(rootptr);
    				break;
     
    			case 9: exit(0);
     
    			default: printf("\nInvalid Input");
    		}
    	}while((1+4/2) == 3);
    }
