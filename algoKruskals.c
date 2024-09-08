#include<stdio.h>
int root[10]= {-1}; //to find the root
#define INF 9999
int find(int i)
{
	while(root[i]) // root[i] != -1
	
	{
		i= root[i];
	}
		return i;
}
	
int uni(int i, int j)
{
		if(i != j)
		{
			root[j]= i; //j->left vertex i->right vertex
			return 1;
		}
		return 0;
}

void main()
{
	int mat[10][10], v, start, i, j, edges= 0, cost=0, total=0;
	int min;
	int x, y, m, n;
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
			mat[i][j]= INF; // setting non connected edges to inf to avoid extra
			
			checking
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
		
		printf("\n\nEdges:\n");
		
		// Kruskal's algorithm start
		
		while(edges < v-1) //finding the vertices set with least edge value
		{
			min= INF;
			for(i=0; i<v; i++)
			{
				
				for(j=0; j<v; j++)
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
}

m= find(x);
n= find(y);

if(uni(m, n))
{
printf("\n%c - %c: %d", x+65, y+65, mat[x][y]);
total+=min;
edges++;
}

// to avoid cycle i.e retaking the same vertex set
mat[x][y]= INF;
mat[y][x]= mat[x][y];

}

printf("\n\nTotal Cost(minimum): %d", total);
}
