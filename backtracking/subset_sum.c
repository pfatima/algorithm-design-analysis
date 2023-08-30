//Subset Sum Problem using backtracking
/*
to find the subset of elements (i where x[i] == 1, as index in w[]) 
that are selected from a given set w[] whose sum (r) adds up to a given number (d)

Time Complexity:  O(2^N)
*/
#include<stdio.h>
int w[10], x[10], i, n, r, d, count, flag = 1;

void subset(int s, int k, int r)
{
    x[k] = 1; //including w[k] element in subset
    if(s + w[k] == d)
    {
        printf("\nsubset %d: ", ++count);
        for(i = 0; i <= k; i++)
        {
            if(x[i] == 1)
                printf("\t%d", w[i]);
        }
    } 
    else
    {
        if((s + w[k] + w[k + 1]) <= d)
        {
            subset(s + w[k], k + 1, r - w[k]);
        }

        if(((s + r - w[k]) >= d) && (s + w[k + 1] <= d))
        {
            x[k] = 0; //unselect || exclude w[k] element in subset
            subset(s, k+1, r-w[k]);
        }

        if(s == n)
            flag = 0;
    }
}

void main()
{
    printf("enter no of set elements, n: \n");
    scanf("%d", &n);
    printf("enter the elements of the set in ascending order:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &w[i]);
        x[i] = 0;
        r += w[i];
    }
    printf("enter d value: \n");
    scanf("%d", &d);
    subset(0, 0, r);
    if(flag == 0)
        printf("subset not possible :(\n");
}

/*
sample input output:

enter no of set elements, n:
5
enter the elements of the set in ascending order:
1 2 5 6 8
enter d value:
9

subset 1:
1 2 6
subset 2:
1 8
*/
