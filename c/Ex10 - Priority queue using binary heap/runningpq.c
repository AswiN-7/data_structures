//max Q
 
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MIN 0
struct heapstruct
{
	int capacity;
	int size;
	float *arr;
	int *idarr;
	char *name[5];
	
};
typedef struct heapstruct pq;
void display(pq* q);

pq* createpq(int capacity)
{
	pq *h;
	if(capacity<MIN)
	{
		printf("enter valid size \n");
		exit(0);
	}
	h=(pq*)malloc(sizeof(pq));
	if(h==NULL)
	{
		printf("memory not allocated \n");
		exit(0);
	}
	h->arr=(float*)malloc(sizeof(float)*(capacity+1));
	h->idarr=(int*)malloc(sizeof(int)*(capacity+1));
	for(int i=0;i<capacity+1;i++)
		h->name[i]=(char*)malloc(sizeof(char)*10);
	h->capacity=capacity;
	h->size=0;
	h->arr[0]=MIN;
	return h;
	
}

int isFull(pq* q)
{
	return q->size==q->capacity;
}

int isEmpty(pq* q)
{
	return q->size==0;
}

void insert(float element,int id,char name[],pq* q)
{
	int i;
	//printf("entering insert\n");
	if(isFull(q))
	{
		printf("Pqueue is alreary full\n");
		return;
	}
	for(i=++q->size;(q->arr[i/2]<element)&&(q->arr[i/2]!=0);i/=2)
	{
		q->arr[i]=q->arr[i/2];
		q->idarr[i]=q->idarr[i/2];
		strcpy(q->name[i],q->name[i/2]);
	}
	q->arr[i]=element;
	q->idarr[i]=id;
	strcpy(q->name[i],name);	
	//printf("end of insert\n");
	display(q);
}

float pop(pq*q)
{
	int i,child;
	float minelement,lastelement;
	int id;
	char name[10];
	
	if(isEmpty(q))
	{
		printf("pqueue is empty\n");
		return -1122;
	}
	minelement=q->arr[1];
	id=q->idarr[q->size];
	strcpy(name,q->name[q->size]);
	lastelement=q->arr[q->size--];
	for(i=1;(i*2)<=q->size;i=child)
	{
		child=i*2;
		if(child!=q->size&&q->arr[child+1]>q->arr[child])
			child++;
		if(lastelement<q->arr[child])
		{
			q->arr[i]=q->arr[child];
			q->idarr[i]=q->idarr[child];
			strcpy(q->name[i],q->name[child]);
			
		}
		else
			break;
	}
	q->arr[i]=lastelement;
	q->idarr[i]=id;
	strcpy(q->name[i],name);	
	return minelement;
}

void display(pq* q)
{
	printf("------------------------------\n");
	for(int i=1;i<=q->size;i++)
	{
		printf("name	:  %s\n",q->name[i]);
		printf("salary	:  %.1f\n",q->arr[i]);
		printf("id	:  %d\n\n",q->idarr[i]);
		
	}
	
	printf("----------------------------------\n");
}

int main()
{
	int total,i=0,id;
	float num;
	char name[10];
	printf("enter size : ");
		scanf("%d",&total);
	pq* pqhead=NULL;
	pqhead=createpq(total);
	while(i<total)
	{
		printf("enter name : ");
			scanf("%s",name);
		printf("enter element to salary : ");
			scanf("%f",&num);
		printf("enter id : ");
			scanf("%d",&id);
		insert(num,id,name,pqhead);
		i++;
	}
	while(1)
	{
		int choice;
		printf("1 --insert\n2 --delete\n3 --display\nenter choice : ");
			scanf("%d",&choice);
		if(choice==1)
		{
			printf("enter name : ");
				scanf("%s",name);
			printf("enter element to add : ");
				scanf("%f",&num);
			printf("enter id : ");
				scanf("%d",&id);
			
		insert(num,id,name,pqhead);
		}
		else if(choice==2)
		{
			num=pop(pqhead);
			if(num==-1122)
				printf("queue is empty \n");
			else
				printf("%f is poped out \n",num);
		}
		else if(choice==3)
		{
			display(pqhead);			
		}
		else if(choice==-1)
			break;
	}
	display(pqhead);
 	return 0;

}

/*
SAMPLE i/o : 
aswin@aswin-pavilion-15:~/Desktop/sem3/data structures in c/lab/ex10$ ./r
enter size : 3
enter name : a
enter element to salary : 1
enter id : 11
------------------------------
name	:  a
salary	:  1.0
id	:  11

----------------------------------
enter name : b
enter element to salary : 2
enter id : 22
------------------------------
name	:  b
salary	:  2.0
id	:  22

name	:  a
salary	:  1.0
id	:  11

----------------------------------
enter name : 3
enter element to salary : 3
enter id : 33
------------------------------
name	:  3
salary	:  3.0
id	:  33

name	:  a
salary	:  1.0
id	:  11

name	:  b
salary	:  2.0
id	:  22

----------------------------------
1 --insert
2 --delete
3 --display
enter choice : 
2
3.000000 is poped out 
1 --insert
2 --delete
3 --display
enter choice : 3
------------------------------
name	:  b
salary	:  2.0
id	:  2

name	:  a
salary	:  1.0
id	:  11

----------------------------------
1 --insert
2 --delete
3 --display
enter choice : 1
enter name : c
enter element to add : 
5
enter id : 55
------------------------------
name	:  c
salary	:  5.0
id	:  55

name	:  a
salary	:  1.0
id	:  11

name	:  b
salary	:  2.0
id	:  2

----------------------------------
1 --insert
2 --delete
3 --display
enter choice : -1
------------------------------
name	:  c
salary	:  5.0
id	:  55

name	:  a
salary	:  1.0
id	:  11

name	:  b
salary	:  2.0
id	:  2

----------------------------------

*/
