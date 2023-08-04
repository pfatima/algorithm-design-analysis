// Topological Ordering (decrease and conquer)

#include <stdio.h>

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

int find_indegree(int a[10][10], int n, int indegree[])
{
    int i, j, sum;
    // incoming edges for j are given by summation of jth column elements
    for(j = 0; j < n; j++)
    {
        sum = 0;
        for(i = 0; i < n; i++)
        {
            sum += a[i][j];
        }
        indegree[j] = sum;
    }
}

void topological_order(int a[10][10], int n)
{
    int i, j, k = 0, u, v, s[10], t[10], top = -1, indegree[10];
    find_indegree(a, n, indegree);
    
    // check for vertex with no incoming edge 
    // then push the vertex to stack ie source vertex removal
    for(i = 0; i < n; i++)
    {
        if(indegree[i] == 0) 
            s[++top] = i;    
    }

    // loop till all vertices are popped from stack
    while(top != -1)
    {
        u = s[top--]; //pop vertex from stack
        t[k++] = u;   //append the vertex to topological array 
        
        // remove outgoing edges from popped vertex (ie edges from vertex u to v)
        for(v = 0; v < n; v++)
        {
            if(a[u][v] == 1)
            {
                indegree[v]--;
                if(indegree[v] == 0) //vertex with no incoming edge // then push the vertex to stack
                    s[++top] = v; //vertex removal
            } 
        }
    }
    printf("the topological order is: \n");
    for(i = 0; i < n; i++)
        printf("%d\t", t[i]);
    printf("\nthe alphabetical topological order is: \n");
    for(i = 0; i < n; i++)
        printf("%c\t", t[i]+97);
}

void main()
{
    int adjacencyMatrix[10][10], n;

    printf("enter the number of vertices: ");
    scanf("%d", &n);
    
    printf("enter the adjacency matrix:\n");
    read_adjacency_matrix(adjacencyMatrix, n);
    
    printf("topological order:\n");
    topological_order(adjacencyMatrix, n);
}

/*
sample input, output
input:
0 0 1 1 0
1 0 0 1 0
0 0 0 0 1
0 0 1 0 1
0 0 0 0 0

output: 
1 0 3 2 4 
b a d c e
*/