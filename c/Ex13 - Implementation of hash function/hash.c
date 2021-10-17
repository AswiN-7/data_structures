#include<stdio.h>
#include<stdlib.h>
#define max 5

struct record
{
	int element;
	struct record* next;
};
typedef struct record record;
void insert(int element,record*hashTable[]);
void display(record*hashTable[]);
int search_element(int key,record*hashTable[]);
int hash_function(int key);
int remove_function(int key,record*hashTable[]);
int main()
{
	record * hashTable[max];
	for(int i=0;i<max;i++)
	{
		hashTable[i]=NULL;
	}
	int choice;
	while(1)
	{
		printf("\n1 --insert\n2 --sarch\n3 --display\n4 --remove\n-1 --stop\nenter choice : ");
			scanf("%d",&choice);
		if(choice==-1)
			break;
		else if(choice==1)
		{
			int element;
			printf("enter element : ");
				scanf("%d",&element);

			insert(element,hashTable);
		}
		else if(choice ==3)
			display(hashTable);
		else if(choice==2)
		{
			int key,res;
			printf("enter element to search : ");
				scanf("%d",&key);

			res=search_element(key,hashTable);
			if(res==-1)
				printf("elemet is not there \n");
			else
				printf("int in the cell %d",res);
		}
		else if(choice==4)
		{
			int key,res,h;
			printf("enter element to delete : ");
				scanf("%d",&key);
			res=remove_function(key,hashTable);
			if(res==-1)
				printf("elemet is not there \n");
			else
				printf("element is deleted \n");

		}
	}
}

void insert(int element,record*hashTable[])
{
	int key,h;
	record* temp;
	key=element;
	if(search_element(key,hashTable)!=-1)
	{
		printf("it is duplicate key\n");
		return;
	}
	h=hash_function(key);
	temp=(record*)malloc(sizeof(record));
	temp->element=element;
	temp->next=hashTable[h];
	hashTable[h]=temp;
}

void display(record*hashTable[])
{
	int count;
	record *ptr;
	for (count= 0;  count < max; count++)
	{
		printf("\n%d : ",count);
		if(hashTable[count]!=NULL)
		{
			ptr=hashTable[count];
			while(ptr!=NULL)
			{
				printf("%d\t",ptr->element);
				ptr=ptr->next;
			}
		}
	}

}

int search_element(int key,record*hashTable[])
{
		int h;
	record*ptr;
	h=hash_function(key);
	ptr=hashTable[h];
	while(ptr!=NULL)
	{
		if(ptr->element==key)
			return h;
		ptr=ptr->next;
	}
	return -1;

}



int hash_function(int key)
{
	return key%max;
}


int remove_function(int key,record*hashTable[])
{
	int h;
	h=hash_function(key);

	record*temp,*ptr;
	temp=hashTable[h];
	if(hashTable[h]==NULL)
	{
		return -1;
	}
	else if(hashTable[h]->element==key)
	{
		temp=hashTable[h];
		hashTable[h]=hashTable[h]->next;
		free(temp);
		return 1;
	}
	else 
	{
		ptr=hashTable[h];
		
		while(ptr->next!=NULL)
		{
			if(ptr->next->element==key)
			{
				temp=ptr->next;
				ptr->next=temp->next;
				free(temp);
				return 1;	
			}	
			ptr=ptr->next;

		}
		return -1;
	}
}

/*
sample i/o : 
aswin@aswin-pavilion-15:~/Desktop/sem3/data structures in c/lab/ex13$ gcc hash.c -o 1
aswin@aswin-pavilion-15:~/Desktop/sem3/data structures in c/lab/ex13$ ./1

1 --insert
2 --sarch
3 --display
4 --remove
-1 --stop
enter choice : 1
enter element : 35

1 --insert
2 --sarch
3 --display
4 --remove
-1 --stop
enter choice : 3

0 : 35	
1 : 
2 : 
3 : 
4 : 
1 --insert
2 --sarch
3 --display
4 --remove
-1 --stop
enter choice : 1
enter element : 26

1 --insert
2 --sarch
3 --display
4 --remove
-1 --stop
enter choice : 1
enter element : 12

1 --insert
2 --sarch
3 --display
4 --remove
-1 --stop
enter choice : 1
enter element : 24

1 --insert
2 --sarch
3 --display
4 --remove
-1 --stop
enter choice : 3

0 : 35	
1 : 26	
2 : 12	
3 : 
4 : 24	
1 --insert
2 --sarch
3 --display
4 --remove
-1 --stop
enter choice : 1
enter element : 43

1 --insert
2 --sarch
3 --display
4 --remove
-1 --stop
enter choice : 3

0 : 35	
1 : 26	
2 : 12	
3 : 43	
4 : 24	
1 --insert
2 --sarch
3 --display
4 --remove
-1 --stop
enter choice : 1
enter element : 38

1 --insert
2 --sarch
3 --display
4 --remove
-1 --stop
enter choice : 1
enter element : 38
it is duplicate key

1 --insert
2 --sarch
3 --display
4 --remove
-1 --stop
enter choice : 1
enter element : 41

1 --insert
2 --sarch
3 --display
4 --remove
-1 --stop
enter choice : 1
enter element : 22

1 --insert
2 --sarch
3 --display
4 --remove
-1 --stop
enter choice : 1
enter element : 11

1 --insert
2 --sarch
3 --display
4 --remove
-1 --stop
enter choice : 3

0 : 35	
1 : 11	41	26	
2 : 22	12	
3 : 38	43	
4 : 24	
1 --insert
2 --sarch
3 --display
4 --remove
-1 --stop
enter choice : 1
enter element : 15

1 --insert
2 --sarch
3 --display
4 --remove
-1 --stop
enter choice : 3

0 : 15	35	
1 : 11	41	26	
2 : 22	12	
3 : 38	43	
4 : 24	
1 --insert
2 --sarch
3 --display
4 --remove
-1 --stop
enter choice : 1
enter element : 45

1 --insert
2 --sarch
3 --display
4 --remove
-1 --stop
enter choice : 3

0 : 45	15	35	
1 : 11	41	26	
2 : 22	12	
3 : 38	43	
4 : 24	
1 --insert
2 --sarch
3 --display
4 --remove
-1 --stop
enter choice : 2
enter element to seaarch : 37
elemet is not there 

1 --insert
2 --sarch
3 --display
4 --remove
-1 --stop
enter choice : 1
enter element : 37

1 --insert
2 --sarch
3 --display
4 --remove
-1 --stop
enter choice : 3

0 : 45	15	35	
1 : 11	41	26	
2 : 37	22	12	
3 : 38	43	
4 : 24	
1 --insert
2 --sarch
3 --display
4 --remove
-1 --stop
enter choice : 2
enter element to seaarch : 37
int in the cell 2
1 --insert
2 --sarch
3 --display
4 --remove
-1 --stop
enter choice : 4
enter element to delete : 38
element is deleted 

1 --insert
2 --sarch
3 --display
4 --remove
-1 --stop
enter choice : 3

0 : 45	15	35	
1 : 11	41	26	
2 : 37	22	12	
3 : 43	
4 : 24	
1 --insert
2 --sarch
3 --display
4 --remove
-1 --stop
enter choice : 3

0 : 45	15	35	
1 : 11	41	26	
2 : 37	22	12	
3 : 43	
4 : 24	
1 --insert
2 --sarch
3 --display
4 --remove
-1 --stop
enter choice : -1

*/




