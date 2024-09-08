#include<stdio.h>
#define INF 9999
void printMatrix(int mat[10][10], int v)
{
	int i, j;
	for(i=0; i<v; i++)
	{
		for(j=0; j <v; j++)
		{
			if(mat[i][j]== INF)
			{
				printf("0\t");
			}
			else
				printf("%d\t", mat[i][j]);
			
		}
		printf("\n");
	}
}

void FloydWarshall(int mat[10][10], int v)
{
	int dist[10][10], i, j, k;
	
	for(i=0; i<v; i++)
	{
		for(j=0; j< v; j++)
		{
			dist[i][j]= mat[i][j];
		}
	}
	
	for(k=0; k<v; k++)
	{
		for(i=0; i<v; i++)
		{
			for(j=0; j<v; j++)
			{
				if(i==j)
				{
					dist[i][j]== 0;
				}
				else
				{
					if((dist[i][k]+dist[k][j])< dist[i][j])
					{
						dist[i][j]= dist[i][k] + dist[k][j];
					}
				}
			}
		}
	}
	
	printf("\n\nThe final Distance matrix: \n");
	printMatrix(dist, v);
	
}

void main()
{
	int mat[10][10], v, start, i, j;
	char s;
	
	printf("\nEnter the total no. of vertices- ");
	scanf("%d", &v);
	
	printf("\nEnter the cost if the two nodes are connected else enter 0\n");
	
	for(i=0; i<v; i++)
	{
		for(j=0; j <v; j++)
		{
			if(i!=j)
			{
				printf("\nEnter mat[%c][%c]- ", i+65, j+65);
				scanf("%d", &mat[i][j]);
				
				if(mat[i][j]== 0)
				{
					mat[i][j]= INF; // setting non connected edges to inf to avoid extra checking
				}
			}
			else
			{
				mat[i][j]= INF; // setting non connected edges to inf to avoid extra checking
			}
			
		}
		printf("\n\n");
	}
	
	printf("\nAdjacency Matrix: \n\n");
	printMatrix(mat, v);
	FloydWarshall(mat, v);
	
}
