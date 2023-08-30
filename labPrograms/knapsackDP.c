// Lab Program 6
// 0/1 Knapsack Problem (dynamic programming)
// Time Complexity: O(nW) 
// n -> no of items ; W -> knapsack capacity

#include <stdio.h>
int i, j, n, c, w[10], p[10], v[10][10];

int max(int a, int b)
{
    return ((a > b) ? a : b);
}

void knapsack(int n, int w[10], int p[10], int c)
{
    for(i = 0; i <= n; i++)
    {
        for(j = 0; j <= c; j++)
        {
            if(i == 0 || j == 0)
                v[i][j] = 0;
            else if (w[i] > j)
                v[i][j] = v[i - 1][j];
            else 
                v[i][j] = max(v[i-1][j], (v[i-1][j-w[i]]+p[i]));
        }
    }
    printf("the maximum profit is : %d", v[n][c]);
    printf("\n\t________Table________\n");
    for(i = 0; i <= n; i++)
    {
        for(j = 0; j <= c; j++)
        {
            printf("%d\t", v[i][j]);
        }
        printf("\n");
    }
}

void main()
{
    printf("enter the no of objects:\n");
    scanf("%d", &n);
    printf("enter the weights:\n");
    for(i = 1; i <= n; i++)
    {
        scanf("%d", &w[i]);
    }
    printf("enter the profits:\n");
    for(i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
    }
    printf("enter the capacity:\n");
    scanf("%d", &c);
    knapsack(n, w, p, c);
}

/*
sample input output:

enter the no of objects:
4
enter the weights:
2 1 3 2
enter the profits:
12 10 20 15
enter the capacity:
5
the maximum profit is : 37

________Table________
0  0  0  0  0  0
0  0  12 12 12 12
0  10 12 22 22 22
0  10 12 22 30 32
0  10 12 22 30 37
*/