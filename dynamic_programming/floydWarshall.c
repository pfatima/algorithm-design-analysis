// Floyd - Warshall Algorithm  (dynamic programming)
/*
All pairs shortest paths:
To find the shortest distances between every pair of vertices in a given edge-weighted directed Graph. 
It is an algorithm for finding the shortest path between all the pairs of vertices in a weighted graph

Time Complexity of Floyd Warshall: O(V3)
*/
#include<stdio.h>

int min(int a, int b)
{
    return (a < b) ? a : b;
}

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

void floyds_algo(int a[10][10], int n)
{
    int i, j, k;
    for(k = 0; k < n; k++)
    {
        for(i = 0; i < n; i++)
        {
            for(j = 0; j < n; j++)
                a[i][j] = min(a[i][j], a[i][k]+a[k][j]);
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
    
    floyds_algo(adjacencyMatrix, n);
    
    printf("all pairs shortest paths:\n");
    display(adjacencyMatrix, n);
}

/*
sample input output:

enter no. of vertices:
4
enter the adjacency matrix:
0 999 3 999 2 0 999 999 999 7 0 1 6 999 999 0

all pairs shortest paths:
0       10      3       4
2       0       5       6
7       7       0       1
6       16      9       0
*/