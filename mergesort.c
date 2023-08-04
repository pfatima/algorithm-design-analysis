// Lab Program 2
// Mergesort (divide & conquer)
// Avg/Best/Worst Time Complexity: O(n*log(n))

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void display(int arr[], int n)
{
    int i;
    for(i = 0; i < n; i++)
        printf("%d\t", arr[i]);
}

void merge(int arr[], int low, int mid, int high)
{
    int i, j, k, t[500];
    i = low, j = mid + 1, k = low;
    while(i <= mid && j <= high)
    {
        if(arr[i] < arr[j])
            t[k++] = arr[i++];
        else
            t[k++] = arr[j++];
    }
    while(i <= mid)
        t[k++] = arr[i++];
    while(j <= high)
        t[k++] = arr[j++];
    for(i = low; i <= high; i++)
        arr[i] = t[i];
}

void mergesort(int arr[], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        mergesort(arr, low, mid);
        mergesort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

void main()
{
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
    mergesort(arr, 0, n-1);
    end = clock();
    
    printf("\nthe sorted elements are:\n");
    display(arr, n);
    
    printf("\ntime taken : %f",(end-start)/(double)CLOCKS_PER_SEC);
}