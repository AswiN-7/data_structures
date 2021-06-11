/*
Menu driven program that perform 
1. Linear Search
2. Binary Search
*/
#include <stdio.h>
int binary_search(int arr[], int n, int key);
int linear_search(int arr[], int n, int key);
void bubble_sort(int arr[], int n);

int main()
{
	int i, n, key, res, j, choice = -99, again;
	while (1)
	{
		printf("enter how many numbers you going to give : ");
		scanf("%d", &n);
		int arr[n];
		for (i = 0; i < n; i++)
		{
			printf("enter number %d : ", i + 1);
			scanf("%d", &arr[i]);
		}

		while (1)
		{
			printf("1-linear\n2-binary \nenter search : ");
			scanf("%d", &choice);
			printf("enter the number to find its position : ");
				scanf("%d", &key);
			if (choice == 1){
				res = linear_search(arr, n, key);
				if (res == -1)
					printf("there is no occurance of %d\n", key);

				else
					printf("the position of %d in the given list is %d \n", key, res + 1);
			}
			else if(choice==2)
			{
				bubble_sort(arr, n);
				for (j = 0; j < n; j++)
					printf("%d\n", arr[j]);
				res = binary_search(arr, n, key);
				if (res == -1)
					printf("there is no occurance of %d\n", key);

				else
					printf("the position of %d in the given list is %d \n", key, res + 1);
			}
			else if (choice < 1 || choice > 2)
			{
				printf("enter correct choice\n\n");
				continue;
			}
			printf("do you want to continue with other search method press 1 else press other numbers");
			scanf("%d", &again);
			if (again == 1)
				continue;
			break;
		}
		printf("do you want continue with others numbers press 2 else press other numbers");
		scanf("%d", &again);
		if (again == 2)
			continue;
		break;
	}
}

int linear_search(int arr[], int n, int key)
{
	int i;
	for (i = 0; i < n; i++)
	{
		if (arr[i] == key)
			return i;
	}
	return -1;
}

int binary_search(int arr[], int n, int key)
{
	int middle, i;
	middle = n / 2;
	if (arr[middle] == key)
		return middle;
	else if (arr[middle] < key)
	{
		for (i = middle; i < n; i++)
		{
			if (arr[i] == key)
				return i;
		}
		return -1;
	}
	else
		for (i = 0; i <= middle; i++)
		{
			if (arr[i] == key)
				return i;
		}
	return -1;
}
void bubble_sort(int arr[], int n)
{
	int i, j, temp;
	for (i = 0; i < n - 1; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (arr[i] > arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}
/*
SAMPLE i/o:
PS D:\learn\6 cp> cd "e:\courses\academic\sem3\data structures in c\lab\update in git\data_structures\" ; if ($?) { gcc search.c -o search } ; if ($?) { .\search }
enter how many numbers you going to give : 4
enter number 1 : 2
enter number 2 : 3
enter number 3 : 4
enter number 4 : 5
1-linear
2-binary
enter search : 1
enter the number to find its position : 4
the position of 4 in the given list is 3 
do you want to continue with other search method press 1 else press other numbers1
1-linear
2-binary
enter search : 2
enter the number to find its position : 2
*/
