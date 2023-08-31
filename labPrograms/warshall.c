// Lab Program 4
// Warshall's Algorithm (dynamic programming)
// find transitive closure

#include<stdio.h>

void read_adjacency_matrix(int a[10][10], int n)
{
    int i, j;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
}

void warshall_algo(int a[10][10], int n)
{
    int i, j, k;
    for(k = 0; k < n; k++)
    {
        for(i = 0; i < n; i++)
        {
            for(j = 0; j < n; j++)
                a[i][j] = (a[i][j] || (a[i][k] && a[k][j]));
        }
    }
}

void display(int a[10][10], int n)
{
    int i, j;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
            printf("%d\t", a[i][j]);
    printf("\n");
    }
}


void main()
{
    int n, adjacencyMatrix[10][10];
    
    printf("enter no. of vertices:\n");
    scanf("%d", &n);
    
    printf("enter the adjacency matrix:\n");
    read_adjacency_matrix(adjacencyMatrix, n);

    warshall_algo(adjacencyMatrix, n);
    
    printf("transitive closure:\n");
    display(adjacencyMatrix, n);
}

/*
sample input output:

enter no. of vertices:
4
enter the adjacency matrix:
0 1 0 0
0 0 0 1
0 0 0 0
1 0 1 0

transitive closure:
1       1       1       1
1       1       1       1
0       0       0       0
1       1       1       1
*/
