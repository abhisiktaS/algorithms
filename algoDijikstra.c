#include<stdio.h>
#define INF 9999

void Dijikstra(int mat[10][10], int v, int s)
{
	int dist[10]={0}, pred[10], count; //pred stores the predecessor of node i
	int vis[10], min, total, i, j, next;
	
	// initializing the others with respect to the chosen node
	for(i=0; i<v; i++)
	{
		dist[i]= mat[s][i];
		pred[i]= s;
		vis[i]= 0;
	}
	
	dist[s]= 0;
	vis[s]= 1;
	count=1;
	
	// implementation

	while(count < v-1)
	{
		min= INF;
		for(i=0; i<v; i++)
		{
			if(dist[i]<min && !vis[i])
			{
				min= dist[i];
				next= i;
			}
		}
		//checking if lower cost path exists
		vis[next]= 1;
		for(i=0; i<v; i++)
		{
			if(!vis[i])
			{
				if((min + mat[next][i])<dist[i])  //assigns distances to other nodes if path exists
				{
					dist[i]= min + mat[next][i];
					pred[i]= next;
				}
			}
		}
		count++;
	}
	
	//printing the result
	for(i=0; i<v; i++)
	{
		if(i != s)
		{
			printf("\n\nDistance from %c to %c: %d", s+65, i+65, dist[i]);
			
			//print path
			printf("\nPath: %c", i+65);
			j=i;
			do
			{
				j=pred[j];
				printf(" <-%c",j+65);
			}while(j!=s);
		}				
	}
}
void main()
{
	int mat[10][10], v, start, i, j;
	char s;
	
	printf("\nEnter the total no. of vertices- ");
	scanf("%d", &v);
	
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
	
	printf("\nEnter starting vertex: ");
	scanf(" %c", &s);
	start= s-65;
	printf("\n\nSOURCE NODE: %c", s);
	Dijikstra(mat, v, start);
}
