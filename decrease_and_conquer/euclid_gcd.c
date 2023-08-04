// Euclid's Algorithm to find GCD (decrease and conquer)

#include<stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int gcd(int m, int n)
{
    int r;
    if (m < n)
        swap(&m, &n);
    if((m % n) == 0)
        return n;
    else
        return gcd(n, m%n);
}

void main()
{
    int a, b;
    printf("enter two integers: ");
    scanf("%d %d", &a, &b);
    int res = gcd(a, b);
    printf("gcd: %d", res);
}