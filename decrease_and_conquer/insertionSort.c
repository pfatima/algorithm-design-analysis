// Insertion Sort (decrease and conquer)
/* Time complexity: 
    best case: Ω(n)
    average case: θ(n^2)
    worst case: O(n^2)
*/

#include<stdio.h>
#include <stdlib.h>

void display(int arr[], int n)
{
    int i;
    for(i = 1; i <= n; i++)
        printf("%d\t", arr[i]);
}

void insertionsort(int a[], int n)
{
    int i, j, temp;
    for(i = 2; i <= n; i++)
    {
        temp = a[i];
        j = i - 1;
        while(j >= 1 && a[j] > temp)
        {
            a[j + 1] = a[j];
                j--;
        }
        a[j + 1] = temp;
    }
}

void main(){
    int i, n, a[20];
    
    printf("enter the no. of elements:\n");
    scanf("%d", &n);
    for(i = 1; i <= n; i++)
        a[i] = rand() % 500 + 1;

    printf("random generated array elements:\n");
    display(a, n);
    
    insertionsort(a, n);
    
    printf("\nsorted array elements\n");
    display(a, n);
}