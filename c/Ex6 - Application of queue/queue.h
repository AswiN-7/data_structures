#include<stdlib.h>
#include<string.h>
#define MAX 10
typedef struct node
{
	 int burstime;
         char jobno[20];
} node;     

typedef struct Queue
{
	int capacity,front,rear,w;
	node* array;
}Queue;

Queue* createQueue()
{
 Queue* q=(Queue*)malloc(sizeof(Queue));
 q->front=-1;
 q->rear=-1;
 q->w=0;
 q->capacity=MAX;
 q->array=(node*)malloc(sizeof(node)*MAX);
 return q;

}
int isEmpty(Queue*q)
{
  return q->front==-1;
}

int isFull(Queue*q)
{
	return q->rear==q->capacity-1;
}


 void push(char jobno[],int burstime,Queue*q)
{
	if(!isFull(q))
	{
     if(q->front==-1&&q->rear==-1)
     	{
          q->front=q->rear=0;
          strcpy(q->array[q->rear].jobno,jobno);
          q->array[q->rear].burstime=burstime;
       }
      else
      {
      	++q->rear;
      	strcpy(q->array[q->rear].jobno,jobno);
        q->array[q->rear].burstime=burstime;
      }
	}
	else
		 {
		 	printf("queue is full");

		 }
   
}
node* pop(Queue*q)
{
	if(!isEmpty(q))
	{
		node*temp;

		temp=&q->array[q->front++];
	    return temp;
	}
	else
	{
		printf("Queue is empty");
	} 
} 
int selector_fun(Queue*q1,Queue*q2)
{
	int q1time=0,q2time=0,i,j;
	for(i=0;i<q1->rear;i++)
	{
		q1time+=q1->array[i].burstime;
	}
	for(j=0;j<q2->rear;j++)
	{
		q2time+=q2->array[j].burstime;
	}

	if(q1time>q2time)
		return 1;
	else if(q1time<q2time)
		return -1;
	else if (q1time==q2time)
		return 0;

}
float cal_average(Queue *q)
{
 float avg=0;
 int i,j;
 for(i=0;i<=q->rear;i++)
	{
              for(j=0;j<i;j++)
		   avg+=q->array[i].burstime;
	}
     avg=(avg/(q->rear+1));
     return avg;
}
void input_fun(Queue*q1,Queue*q2)
{
	push("j1",6,q1);
	push("j2",5,q2);
	int inburstime,selector,size,i;
        char	injobno[20];
        printf("enter how many input you are going to give (already one job is inserted in both the queues so input taken as n-2 ):");
		scanf("%d",&size);
	for(i=0;i<size-2;i++)
	{
	printf("enter job name %d:",i+3);
		scanf("%s",injobno);
	printf("enter burstime : ");
		scanf("%d",&inburstime);
		selector=selector_fun(q1,q2);
      	if(selector==1)
    		push(injobno,inburstime,q2);
    	else if(selector==-1)
    		push(injobno,inburstime,q1);
    	else if(selector==0)
    		push(injobno,inburstime,q1);
        }
}
void output_fun(Queue *q)
{
	int i,j;
     printf("job name        : ");
     for(i=0;i<=q->rear;i++)
	{
		printf("%s  ",q->array[i].jobno);
	}
        printf("\nBursting time : ");
    for(j=0;j<=q->rear;j++)
	{
		printf("%d    ",q->array[j].burstime);
	}
         printf("\n");
}

