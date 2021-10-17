#include<stdio.h>
#define MAX 25
#define QUEUE_SIZE 25
int queue[QUEUE_SIZE];
int queue_front, queue_end;

void dfs(int adj[][MAX],int visited[],int start,int n,int choice)
{
    int stack[MAX];
    int top=-1,i;
    if(choice==1)
       printf(" %c ",start+65);
    else
       printf(" %d ",start);
    visited[start]=1;
    stack[++top]=start;
    while(top!=-1)
    {
    start=stack[top--];
    for(i=0;i<n;i++)
    {
      if(adj[start][i] && visited[i]==0)
    {
      stack[++top]=i;
      if(choice==1)
        printf("%c ",i+65);
      else
        printf("%d ",i);
      visited[i]=1;
      }
    }
  }
}

void enqueue(int v) 
{
  queue[queue_end++] = v;
}

int dequeue() 
{
  int index = queue_front;
  queue_front++;
  return queue[index];
}


void bfs(int Adj[][MAX], int n, int source,int sv) 
{
  int i, j;
  int visited[MAX];
  queue_front = 0;
  queue_end = 0;
  for(i = 0; i < MAX; i++) 
    visited[i] = 0;
  visited[source] = 1;
 enqueue(source);
  if(sv==1)
    printf("%c ",source+65);
 else
    printf("%d ",source);
  while(queue_front <= queue_end) 
  {
    i = dequeue();
    for(j = 0; j < n; j++) 
    {
      if(visited[j] == 0 && Adj[i][j] == 1) 
      {
       visited[j] = 1;
       enqueue(j);
        if(sv==1)
        printf("%c ",j+65);
        else
          printf("%d ",j);
      }
    }
  }
  printf("\n");
}

int main()
{
  int adj[MAX][MAX];
  int visited[MAX]={0};
  int i,j;
  int n,choice;
  char ch;
  do
  {
  printf("Enter the number of vertices:");
  scanf("%d",&n);
  for(i=0;i<n;i++)
  { printf("\nNode %d : \n",i);
    for(j=0;j<n;j++)
    {
      printf("\'1\' if has ADJACENCY with %d else \'0\' : ",j);
      scanf("%d",&adj[i][j]);
    }
  }
  printf("\nADJACENCY MATRIX : \n");
  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
      printf(" %d",adj[i][j]);
    printf("\n");
  }
  printf("\n\t1.Alphabetic Graph\n\t2.Numeric Graph\n");
  printf("Enter choice : ");
  scanf("%d",&choice);
  printf("\nDFS Traversal : \n");
  dfs(adj,visited,0,n,choice);
  printf("\n");
  printf("\nBFS Traversal : \n");
  bfs(adj,n,0,choice);
  printf("Do you want to continue (y/n) ? ");
  scanf(" %c",&ch);
  }while(ch=='y');      
  return 0;
}

/*
C:\Users\Azeez\Downloads>gcc gtraversal.c

C:\Users\Azeez\Downloads>a
Enter the number of vertices:5

Node 0 :
'1' if has ADJACENCY with 0 else '0' : 0
'1' if has ADJACENCY with 1 else '0' : 1
'1' if has ADJACENCY with 2 else '0' : 1
'1' if has ADJACENCY with 3 else '0' : 0
'1' if has ADJACENCY with 4 else '0' : 1

Node 1 :
'1' if has ADJACENCY with 0 else '0' : 1
'1' if has ADJACENCY with 1 else '0' : 0
'1' if has ADJACENCY with 2 else '0' : 0
'1' if has ADJACENCY with 3 else '0' : 1
'1' if has ADJACENCY with 4 else '0' : 1

Node 2 :
'1' if has ADJACENCY with 0 else '0' : 1
'1' if has ADJACENCY with 1 else '0' : 0
'1' if has ADJACENCY with 2 else '0' : 0
'1' if has ADJACENCY with 3 else '0' : 0
'1' if has ADJACENCY with 4 else '0' : 0

Node 3 :
'1' if has ADJACENCY with 0 else '0' : 0
'1' if has ADJACENCY with 1 else '0' : 1
'1' if has ADJACENCY with 2 else '0' : 0
'1' if has ADJACENCY with 3 else '0' : 0
'1' if has ADJACENCY with 4 else '0' : 0

Node 4 :
'1' if has ADJACENCY with 0 else '0' : 1
'1' if has ADJACENCY with 1 else '0' : 1
'1' if has ADJACENCY with 2 else '0' : 0
'1' if has ADJACENCY with 3 else '0' : 0
'1' if has ADJACENCY with 4 else '0' : 0

ADJACENCY MATRIX :
 0 1 1 0 1
 1 0 0 1 1
 1 0 0 0 0
 0 1 0 0 0
 1 1 0 0 0

        1.Alphabetic Graph
        2.Numeric Graph
Enter choice : 1

DFS Traversal :
 A B D E C

BFS Traversal :
A B C E D
Do you want to continue (y/n) ? y
Enter the number of vertices:5

Node 0 :
'1' if has ADJACENCY with 0 else '0' : 0
'1' if has ADJACENCY with 1 else '0' : 1
'1' if has ADJACENCY with 2 else '0' : 0
'1' if has ADJACENCY with 3 else '0' : 0
'1' if has ADJACENCY with 4 else '0' : 0

Node 1 :
'1' if has ADJACENCY with 0 else '0' : 0
'1' if has ADJACENCY with 1 else '0' : 0
'1' if has ADJACENCY with 2 else '0' : 1
'1' if has ADJACENCY with 3 else '0' : 0
'1' if has ADJACENCY with 4 else '0' : 0

Node 2 :
'1' if has ADJACENCY with 0 else '0' : 0
'1' if has ADJACENCY with 1 else '0' : 0
'1' if has ADJACENCY with 2 else '0' : 0
'1' if has ADJACENCY with 3 else '0' : 1
'1' if has ADJACENCY with 4 else '0' : 1

Node 3 :
'1' if has ADJACENCY with 0 else '0' : 1
'1' if has ADJACENCY with 1 else '0' : 0
'1' if has ADJACENCY with 2 else '0' : 0
'1' if has ADJACENCY with 3 else '0' : 0
'1' if has ADJACENCY with 4 else '0' : 0

Node 4 :
'1' if has ADJACENCY with 0 else '0' : 0
'1' if has ADJACENCY with 1 else '0' : 0
'1' if has ADJACENCY with 2 else '0' : 1
'1' if has ADJACENCY with 3 else '0' : 0
'1' if has ADJACENCY with 4 else '0' : 0

ADJACENCY MATRIX :
 0 1 0 0 0
 0 0 1 0 0
 0 0 0 1 1
 1 0 0 0 0
 0 0 1 0 0

        1.Alphabetic Graph
        2.Numeric Graph
Enter choice : 2

DFS Traversal :
 0

BFS Traversal :
0 1 2 3 4
Do you want to continue (y/n) ? n

*/
