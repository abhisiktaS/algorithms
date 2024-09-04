#include<stdio.h>
int main()
{
	int mat[10][10], v, i, j, front=-1, rear=-1, queue[10], start, vis[10]={0};
	char s;
	
	printf("Number of vertices- ");
	scanf("%d", &v);
	
	for(i=0; i<v; i++)
	{
		for(j=0; j <v; j++)
		{
			if(i!=j)
			{
				printf("\nEnter mat[%c][%c]- ", i+65, j+65);
				scanf("%d", &mat[i][j]);
			}
			else
			{
				mat[i][j]= 0;
			}
			
		}
		printf("\n\n");
	}
	
	printf("\nAdjacency Matrix: \n");
	for(i=0; i<v; i++)
	{
		for(j=0; j <v; j++)
		{
			printf("%d\t", mat[i][j]);
			
		}
		printf("\n");
	}
	
	printf("\nEnter starting vertex: ");
	scanf(" %c", &s);
	
	
	start= s-65;
	vis[s-'A']= 1;
	rear++;
	queue[rear]= s-'A';
	printf("\nBFS TRAVERSAL RESULT: \n");
	while(front<rear)
	{
		front++;
		i= queue[front];
		printf("%c ", i+'A');
		
		for(j=0; j<v; j++)
		{
			if(mat[i][j]== 1 && !vis[j])
			{
				rear++;
				queue[rear]= j;
				vis[j]= 1;
			}
		}
	}
	return 0;
}
