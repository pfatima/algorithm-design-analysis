// Prim's Algorithm (greedy technique)
/*
finds a minimum spanning tree for a weighted undirected graph
finds a subset of the edges that forms a tree that includes every vertex, 
where the total weight of all the edges in the tree is minimized.

Time Complexity: O(V^2)
*/

#include<stdio.h>
#define INF 9999
int i, j, n, c[20][20], visited[20];

void prims(){
    int a, b, min, cost = 0, count = 0;
    min = INF;
    printf("the minimal spanning tree is: \n");
    visited[1] = 1;
    while(count < (n -1))
    {
        min = INF;
        for(i = 1; i <= n; i++)
        {
            for(j = 1; j <= n; j++)
            {
                if(visited[i] && (!visited[j]) && min > c[i][j])
                {
                    min = c[i][j];
                    a = i;
                    b = j;
                }
            }
        }
        printf("%d --> %d = %d\n", a, b, c[a][b]);
        cost += c[a][b];
        visited[b] = 1;
        count++;
    }
    printf("the total cost is : %d", cost);
}

void main()
{
    printf("enter the number of vertices:\n");
    scanf("%d", &n);
    printf("enter the adjacency matrix:\n");
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            scanf("%d", &c[i][j]);
            visited[i] = 0;
        }        
    }
    prims();
}

/*
sample input output:
enter the number of vertices:
5
enter the adjacency matrix:
9999 5 2 9999 9999
5 9999 9999 6 9999
2 9999 9999 1 3
9999 6 1 9999 4
9999 9999 3 4 9999

the minimal spanning tree is: 
3 --> 4 = 1
1 --> 3 = 2
3 --> 5 = 3
1 --> 2 = 5

the total cost is : 11
*/