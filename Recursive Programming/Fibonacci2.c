#include<stdio.h>
int fib(int n)
{
    if(n==1)
        return 1;
    if(n==0)
        return 0;
    return fib(n-1)+fib(n-2); 
}
int main()
{
    int n;
    printf("Enter number: ");
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
    {
        a[i]=fib(i);
        printf("%d ",a[i]);
    }
    return 0;
}
// 0 1 1 2 3 5 8 13
// 1 2 3 4 5 6 7 8  