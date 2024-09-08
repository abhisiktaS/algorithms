#include<stdio.h>
void dfs(int mat[10][10], int start, int v);
int main()
{
	int mat[10][10], v, start, i, j;
	char s;
	
	printf("Enter the total no. of vertices- ");
	scanf("%d", &v);
	
	printf("Enter 1 the two nodes are connected else enter 0\n");
	
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
	
	printf("\nAdjacency Matrix: \n\n");
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
	printf("\n\nRESULT OF DFS TRAVERSAL:\n");
	dfs(mat, start, v);
	return 0;
}

void dfs(int mat[10][10], int start, int v)
{
	int stack[10], top=-1, j, i;
	static int  vis[10]= {0};

	i= start;
	if(vis[i]!= 1)
	{
		printf("%c ", start+65);
		vis[i]= 1;     //marking the top of stack as visited
	}
	
	//Pushing the adjacent vertices to the stack
	for(j=0; j<v; j++)
	{
		if(mat[i][j]== 1 && !vis[j])
			dfs(mat, j, v);
	}
//	}
}
