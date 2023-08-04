// Quicksort (divide & conquer)
// Avg/Best Time Complexity: O(n*log(n))
// Worst Time Complexity: O(n^2)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void display(int arr[], int n)
{
    int i;
    for(i = 0; i < n; i++)
        printf("%d\t", arr[i]);
}

int partition(int arr[], int low, int high)
{
    int i = low - 1, j = high, pivot = arr[low];
    while(i < j)
    {
        while(i < high && arr[i] <= pivot)
            i++;
        while(j > low && arr[j] >= pivot)
            j--;
        if(i < j)
            swap(&arr[i], &arr[j]);
    }
    swap(&arr[low], &arr[j]);
    return j;
}

void quicksort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivotindex = partition(arr, low, high);
        quicksort(arr, low, pivotindex - 1);
        quicksort(arr, pivotindex + 1, high);
    }
}

void main(){
    int i, n, arr[500];
    clock_t start = 0, end = 0;

    srand(time(NULL));
    
    printf("enter no. of elements:\n");
    scanf("%d", &n);
    for(i = 0; i < n; i++)
        arr[i] = rand() % 500 + 1;
    
    printf("random generated array elements:\n");
    display(arr, n);

    start = clock();
    quicksort(arr, 0, n-1);
    end = clock();
    
    printf("\nthe sorted elements are:\n");
    display(arr, n);
    
    printf("\ntime taken : %f",(end-start)/(double)CLOCKS_PER_SEC);
}
