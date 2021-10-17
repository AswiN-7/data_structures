#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define MAX 10

int no_of_vertices,edge;

 int minDistance(int dist[no_of_vertices], int Set[no_of_vertices])
{
   int min = 100, min_index;
   for (int v = 0; v < no_of_vertices; v++)
     if (Set[v]==0 && dist[v] <= min)
        {
            min = dist[v];
            min_index = v;
        }
   return min_index;
}

 void dijkstra(int graph[no_of_vertices][no_of_vertices], int start)
{  	
	 int dist[no_of_vertices];
     int Set[no_of_vertices];
     for (int i = 0; i < no_of_vertices; i++)
        {
            dist[i] = MAX;
             Set[i]=0;
        }
     dist[start-1] = 0;
     for (int count = 0; count < no_of_vertices-1; count++)
     {
       int u = minDistance(dist,Set);
       Set[u]=1;
       for (int v = 0; v < no_of_vertices; v++)
         if (!Set[v] && graph[u][v] && dist[u] != MAX
                                       && ((dist[u]+graph[u][v]) < dist[v]))
         {
            dist[v] = dist[u] + graph[u][v];
            if(u == 0)
            	printf("%d -> %d\n",u+1,v+1);
            else
            	printf("1 -> %d -> %d\n",u+1,v+1);
         }
     }
     for(int i=0;i<no_of_vertices;i++)
     	printf("Travel Distance from node %d: %d \n",i+1,dist[i]);
}

int main()
{
	int n,e;
	printf("Enter the vertices for directed graph : ");
	scanf("%d",&n);
	no_of_vertices = n;
	printf("Enter the edges for directed graph : ");
	scanf("%d",&e);
	edge = e;
	int adj[n][n];
	int visited[n];
	int visited1[n];
	for(int i = 0; i<n; i++){
		for(int j = 0; j<n; j++)
			adj[i][j] = 0;
		visited[i] = 0; 
		visited1[i] = 0;
	}

	printf("Enter the edges for directed graph with distance:\n");
	for(int i = 0; i<e; i++){
		int u,v;
		int p;
		scanf("%d %d %d",&u,&v,&p);
		adj[u-1][v-1] = p;
	}
	printf("\nAdj matrix :\n");
	for(int i = 0; i<n; i++){
		for(int j = 0; j<n; j++)
			printf("%d ",adj[i][j]);
		printf("\n");
	}
	printf("\nDjikstra :\n\n");
	dijkstra(adj,1);
	printf("\nEnter the vertices for undirected graph : ");
	scanf("%d",&n);
	no_of_vertices = n;
	printf("Enter the edges for undirected graph : ");
	scanf("%d",&e);
	for(int i = 0; i<n; i++){
		for(int j = 0; j<n; j++)
			adj[i][j] = 0;
		visited[i] = 0; 
		visited1[i] = 0;
	}

	printf("Enetr the edges for undirected graph with distance:\n");
	for(int i = 0; i<e; i++){
		int u,v;
		int p;
		scanf(" %d %d %d",&u,&v,&p);
		adj[u-1][v-1] = p;
		adj[v-1][u-1] = p;
		
	}
	printf("\nAdj matrix :\n");
	for(int i = 0; i<n; i++){
		for(int j = 0; j<n; j++)
			printf("%d ",adj[i][j]);
		printf("\n");
	}
	printf("\nDjikstra :\n\n");
	dijkstra(adj,1);
}




/*
SAMPLE  I/O:

Enter the vertices for directed graph : 7

Enter the edges for directed graph : 12

Enter the edges for directed graph with distance:

1 2 2
1 4 1
2 5 10
2 4 3
3 1 4
4 3 2
4 5 2
3 6 5
4 6 8
6 7 1
4 7 4
5 7 6

Adj matrix :

0 2 0 1 0 0 0 
0 0 0 3 10 0 0 
4 0 0 0 0 5 0 
0 0 2 0 2 8 4 
0 0 0 0 0 0 6 
0 0 0 0 0 0 1 
0 0 0 0 0 0 0 

Djikstra :

1 -> 2
1 -> 4
1 -> 4 -> 3
1 -> 4 -> 5
1 -> 4 -> 6
1 -> 4 -> 7
1 -> 3 -> 6

Travel Distance from node 1: 0 
Travel Distance from node 2: 2 
Travel Distance from node 3: 3 
Travel Distance from node 4: 1 
Travel Distance from node 5: 3 
Travel Distance from node 6: 8 
Travel Distance from node 7: 5 



Enter the vertices for undirected graph : 6

Enter the edges for undirected graph : 9

Enetr the edges for undirected graph with distance:

1 2
5
1 4 6
1 5 10
4 5 3
2 3 1
2 5 2
2 6 7
3 6 8
5 6 4

Adj matrix :

0 5 0 6 10 0 
5 0 1 0 2 7 
0 1 0 0 0 8 
6 0 0 0 3 0 
10 2 0 3 0 4 
0 7 8 0 4 0 

Djikstra :

1 -> 2
1 -> 4
1 -> 2 -> 6

Travel Distance from node 1: 0 
Travel Distance from node 2: 5 
Travel Distance from node 3: 10 
Travel Distance from node 4: 6 
Travel Distance from node 5: 10 
Travel Distance from node 6: 7  */
