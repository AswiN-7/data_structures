/*
Menu driven program that perform 
1. bubble sort
2. selection sort
*/
#include <stdio.h>
void bubble_sort(int arr[], int n);
void selection_sort(int arr[], int n);

int main()
{
     int i, n, key, res, j, choice = -99, again;
     while (1)
     {
          printf("enter how many numbers you going to give : ");
		scanf("%d", &n);
		int arrg[n];
		for (i = 0; i < n; i++)
		{
			printf("enter number %d : ", i + 1);
			scanf("%d", &arrg[i]);
		}

          while (1)
          {
               int arr[n];
               for (int i = 0; i < n; i++)
               {
                    arr[i] = arrg[i];
               }
               
               printf("1-bubble sort\n2-selection sort\nenter sort : ");
               scanf("%d", &choice);
               if (choice == 1)
               {
                    bubble_sort(arr, n);
                    for (j = 0; j < n; j++)
                         printf("%d\n", arr[j]);
               }
               else if (choice == 2)
               {
                    selection_sort(arr, n);
                    for (j = 0; j < n; j++)
                         printf("%d\n", arr[j]);
               }

               else
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
void selection_sort(int arr[], int n)
{
     int i, j, temp, min;
     for (i = 0; i < n - 1; i++)
     {
          min = i;
          for (j = i + 1; j < n; j++)
          {
               if (arr[min] > arr[j])
                    min = j;
          }

          temp = arr[i];
          arr[i] = arr[min];
          arr[min] = temp;
     }
}