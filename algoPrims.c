#include<stdio.h>
#define INF 999999

void Prims(int mat[10][10], int v, int s)
{
	int i,j,x,y;
	int edge=0, cost=0;
	int selected[10]= {0}; // making all the vertices unvisited
	selected[s]= 1;
	
	while(edge < v-1)
	{
		int min= INF;
		for(i=0; i<v; i++)
		{
			if(selected[i]== 1)   // if the vertex i is selected
			{
				for(j=0; j<v; j++)
				{
					if((selected[j]!= 1) && (mat[i][j]>0))
					{
						if(mat[i][j] < min)
						{
							min= mat[i][j];
							x=i;      
							y=j;
						}
					}
				}
			}
		}
		
		printf("\n%c - %c: %d", x+65, y+65, mat[x][y]);  //printing the chosen edge and its cost
		cost+=mat[x][y];
		selected[y]= 1;
		edge++;
	}
	printf("\n\nTotal Cost(minimum): %d", cost);
}

int main()
{
	int mat[10][10], v, start, i, j;
	char s;
	
	printf("\nEnter the total no. of vertices- ");
	scanf("%d", &v);
	
	printf("Enter the cost if the two nodes are connected else enter 0\n");
	
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
	printf("\n\n RESULT:\n");
	Prims(mat, v, start);
	return 0;
}

