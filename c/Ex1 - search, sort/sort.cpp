/*
Menu driven program that perform 
1. bubble sort
2. selection sort
3. insertion sort
4. merge sort
5. quick sort
*/
#include<iostream>
#include<stdlib.h>

using namespace std;
void bubble_sort(int arr[], int n);
void selection_sort(int arr[], int n);
void insertion_sort(int arr[], int n);
void merge(int arr[],int start, int mid, int end);
int partition(int arr[], int p, int r);
void merge_sort(int arr[], int start, int end);
void quick_sort(int arr[], int p, int r);
void print_arr(int arr[], int size);

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
               
               printf("1-bubble sort\n2-selection sort\n3-insertion sort\n4 - merge sort\n5 - quick sort\nenter sort : ");
               scanf("%d", &choice);
               if (choice == 1)
               {
                    bubble_sort(arr, n);
                    print_arr(arr, n);
               }
               else if (choice == 2)
               {
                    selection_sort(arr, n);
                    print_arr(arr, n);

               }
               else if (choice == 3)
               {
                    insertion_sort(arr, n);
                    print_arr(arr, n);

               }
               else if (choice == 4)
               {
                    merge_sort(arr, 0, n);
                    print_arr(arr, n);

               }
               else if (choice == 5)
               {
                    quick_sort(arr, 0, n);
                    print_arr(arr, n);

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

void insertion_sort(int arr[], int n){
     int key, insert;
     for(int i=1;i<n;i++){
          key = arr[i];
          insert = i-1;
          while(insert>=0 && arr[insert]>key){
               arr[insert+1] = arr[insert];
               insert--;
          }
          arr[insert+1] = key;
     }
}

void merge(int arr[],int start, int mid, int end){
    int temp[end-start+1];
    int i=start, j=mid+1, k=0;
    while(i<=mid&&j<=end){
        if(arr[i]<=arr[j]){
            temp[k++] = arr[i++];
        }
        else{
            temp[k++] = arr[j++];
        }
    }
    while(i<=mid){
        temp[k++] = arr[i++];
    }
    while(j<=end){
        temp[k++] = arr[j++];
    }

    for(i = start;i<=end;i++){
        arr[i] = temp[i-start];
    }
}

void merge_sort(int arr[], int start, int end){
    if(start<end){
        int mid  = (start+end)/2;
        merge_sort(arr, start, mid);
        merge_sort(arr, mid+1, end);
        merge(arr, start, mid, end);
    }
}

int partition(int arr[], int p, int r){
    int pivot = arr[r];
    int i=p-1;
    for(int j=p;j<r;j++){
        if(arr[j]<pivot){
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[++i];
    arr[i] = pivot;
    arr[r] = temp;
    return i;
}

void quick_sort(int arr[], int p, int r){
    if(p<r){
        int q = partition(arr, p, r);
        quick_sort(arr, p, q-1);
        quick_sort(arr, q+1, r);
    }
}

void print_arr(int arr[], int size){
    for(int i=0;i<size;i++){
       cout<<arr[i]<<" ";
    }
    cout<<endl;
}