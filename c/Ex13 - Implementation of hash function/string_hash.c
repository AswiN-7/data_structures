#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 50

struct record
{
	char element[20];
	struct record* next;
};
typedef struct record record;
void insert(char element[],record*hashTable[]);
void display(record*hashTable[]);
int search_element(char key[],record*hashTable[]);
int hash_function(char key[]);
int remove_function(char key[],record*hashTable[]);
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
			char element[20];
			printf("enter element : ");
				scanf("%s",element);

			insert(element,hashTable);
		}
		else if(choice ==3)
			display(hashTable);
		else if(choice==2)
		{
			int res;
			char key[20];
			printf("enter element to seaarch : ");
				scanf("%s",key);

			res=search_element(key,hashTable);
			if(res==-1)
				printf("elemet is not there \n");
			else
				printf("int in the cell %d",res);
		}
		else if(choice==4)
		{
			int res,h;
			char key[20];
			printf("enter element to delete : ");
				scanf("%s",key);
			res=remove_function(key,hashTable);
			if(res==-1)
				printf("elemet is not there \n");
			else
				printf("element is deleted \n");

		}
	}
}

void insert(char element[],record*hashTable[])
{
	char key[20],h;
	record* temp;
	strcpy(key,element);
	if(search_element(key,hashTable)!=-1)
	{
		printf("it is duplicate key\n");
		return;
	}
	h=hash_function(key);
	temp=(record*)malloc(sizeof(record));
	strcpy(temp->element,element);
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
				printf("%s\t",ptr->element);
				ptr=ptr->next;
			}
		}
	}

}

int search_element(char key[],record*hashTable[])
{
		int h;
	record*ptr;
	h=hash_function(key);
	ptr=hashTable[h];
	while(ptr!=NULL)
	{
		if(strcmp(ptr->element,key)==0)
			return h;
		ptr=ptr->next;
	}
	return -1;

}
int remove_function(char key[],record*hashTable[])
{
	int h;
	h=hash_function(key);

	record*temp,*ptr;
	temp=hashTable[h];
	if(hashTable[h]==NULL)
	{
		return -1;
	}
	else if(strcmp(hashTable[h]->element,key)==0)
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
			if(strcmp(ptr->next->element,key))
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

int hash_function(char key[])
{
	int total=0,order=1;
	for(int i=0;i<strlen(key);i++)
	{
		printf("order %d",order);
		total+=key[i]*order++;
	}
	return total%2069;
}

/*sample i/o : 
aswin@aswin-pavilion-15:~/Desktop/sem3/data structures in c/lab/ex13$ ./1

1 --insert
2 --sarch
3 --display
4 --remove
-1 --stop
enter choice : 1
enter element : abcdef
order 1order 2order 3order 4order 5order 6order 1order 2order 3order 4order 5order 6
1 --insert
2 --sarch
3 --display
4 --remove
-1 --stop
enter choice : 3

0 : 
1 : 
2 : 
3 : 
4 : 
5 : 
6 : 
7 : 
8 : 
9 : 
10 : 
11 : 
12 : 
13 : 
14 : 
15 : 
16 : 
17 : 
18 : 
19 : 
20 : 
21 : 
22 : 
23 : 
24 : 
25 : 
26 : 
27 : 
28 : 
29 : 
30 : 
31 : 
32 : 
33 : 
34 : 
35 : 
36 : 
37 : 
38 : abcdef	
39 : 
40 : 
41 : 
42 : 
43 : 
44 : 
45 : 
46 : 
47 : 
48 : 
49 : 
1 --insert
2 --sarch
3 --display
4 --remove
-1 --stop
enter choice : 1
enter element : bcdefa
order 1order 2order 3order 4order 5order 6order 1order 2order 3order 4order 5order 6
1 --insert
2 --sarch
3 --display
4 --remove
-1 --stop
enter choice : 3

0 : 
1 : 
2 : 
3 : 
4 : 
5 : 
6 : 
7 : 
8 : 
9 : 
10 : 
11 : 
12 : 
13 : 
14 : 
15 : 
16 : 
17 : 
18 : 
19 : 
20 : 
21 : 
22 : 
23 : bcdefa	
24 : 
25 : 
26 : 
27 : 
28 : 
29 : 
30 : 
31 : 
32 : 
33 : 
34 : 
35 : 
36 : 
37 : 
38 : abcdef	
39 : 
40 : 
41 : 
42 : 
43 : 
44 : 
45 : 
46 : 
47 : 
48 : 
49 : 
1 --insert
2 --sarch
3 --display
4 --remove
-1 --stop
enter choice : 1
enter element : cdefab
order 1order 2order 3order 4order 5order 6order 1order 2order 3order 4order 5order 6
1 --insert
2 --sarch
3 --display
4 --remove
-1 --stop
enter choice : defabc
enter element : order 1order 2order 3order 4order 5order 6order 1order 2order 3order 4order 5order 6
1 --insert
2 --sarch
3 --display
4 --remove
-1 --stop
enter choice : 3

0 : 
1 : 
2 : 
3 : 
4 : 
5 : 
6 : 
7 : 
8 : 
9 : 
10 : 
11 : defabc	
12 : 
13 : 
14 : cdefab	
15 : 
16 : 
17 : 
18 : 
19 : 
20 : 
21 : 
22 : 
23 : bcdefa	
24 : 
25 : 
26 : 
27 : 
28 : 
29 : 
30 : 
31 : 
32 : 
33 : 
34 : 
35 : 
36 : 
37 : 
38 : abcdef	
39 : 
40 : 
41 : 
42 : 
43 : 
44 : 
45 : 
46 : 
47 : 
48 : 
49 : 
1 --insert
2 --sarch
3 --display
4 --remove
-1 --stop
enter choice : -1

*/


