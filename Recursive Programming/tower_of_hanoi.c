#include<stdio.h>
void toh(int n, int a, int c, int b)
{
    if(n==1)
        printf("%d to %d\n",a,c);
    else
    {
        toh(n-1,a,b,c);
        printf("%d to %d\n",a,c);
        toh(n-1,b,c,a);
    }
}
int main()
{
    int n;
    printf("Enter n: ");
    scanf("%d",&n);
    toh(n,1,3,2);
    return 0;
}