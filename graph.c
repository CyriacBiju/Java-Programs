#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int am[100][100];
void undirected()
{
	int v,i,j=0,id[100]={0},od[100]={0};
	printf("Enter number of vertices");
	scanf("%d",&v);
	for(i=1;i<=v;i++)
	{	
		printf("Enter the vertices adjacent to %d",i);
		do
		{
			scanf("%d",&j);
			if(j<=0)
				break;
			am[i][j]=am[j][i]=1;
		}while(j>=1 && j<=v && j!=i);
	}
	printf("The matrix is:\n");
	for(i=1;i<=v;i++)
	{	
		for(j=1;j<=v;j++)
		{
			printf("%d ",am[i][j]);
			id[i]+=am[j][i];
			od[i]+=am[i][j];
		}
		printf("\n");
	}
	printf("INDEX\tINDEGREE OUTDEGREE TOTALDEGREE\n");	
	for(i=1;i<=v;i++)
		printf("   %d\t   %d\t    %d\t      %d\n",i,id[i],od[i],id[i]);
}	

void directed()
{
	int v,i,j=0,id[100]={0},od[100]={0};
	printf("Enter number of vertices: ");
	scanf("%d",&v);
	for(i=1;i<=v;i++)
	{	
		printf("\nEnter the vertices adjacent to %d: ",i);
		do
		{
			scanf("%d",&j);
			if(j<=0)
				break;
			am[i][j]=1;
		}while(j>=1 && j<=v && j!=i);
	}
	printf("The matrix is:\n");
	for(i=1;i<=v;i++)
	{	
		for(j=1;j<=v;j++)
		{
			printf("%d ",am[i][j]);
			id[i]+=am[j][i];
			od[i]+=am[i][j];
		}
		printf("\n");
	}
	printf("INDEX\tINDEGREE OUTDEGREE TOTALDEGREE\n");	
	for(i=1;i<=v;i++)
		printf("   %d\t   %d\t    %d\t      %d\n",i,id[i],od[i],id[i]+od[i]);
}	
			


void main()
{
	int ch;
	do
	{   
		memset(am,0,100*100*sizeof(int));
		printf("MENU\n");
		printf("1. Directed graph\n");
		printf("2. Undirected graph\n");
		printf("3. Exit\n");
		printf("Enter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:directed();
				   break;
			case 2:undirected();
				   break;
			case 3:exit(0);
			default:printf("Invalid choice\n");
		}
	}while(1);
}
