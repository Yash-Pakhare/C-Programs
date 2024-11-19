#include<stdio.h>
int fact(int n)
{
    if(n<=1)
        return 1;
    return n*fact(n-1); 
}
int main()
{
    int n;
    printf("Enter number: ");
    scanf("%d",&n);
    int f=fact(n);
    printf("%d",f);
    return 0;
} 