#include<stdio.h>
#include<math.h>
int fact(int n)
{
    if(n<=1)
        return 1;
    return n*fact(n-1);
}
double taylor_series(int n, int x, int i)
{
    double s=pow(x,i-n)/(double)fact(i-n);
    if(n==1)
        return s;
    return s+taylor_series(n-1,x,i);
}
int main()
{
    int n;
    printf("Enter number of terms: ");
    scanf("%d",&n);
    int x;
    printf("Enter number x: ");
    scanf("%d",&x);
    double a[n];
    for(int i=1;i<=n;i++)
        a[i-1]=taylor_series(i,x,i);
    for(int i=0;i<n;i++)
        printf("%lf ",a[i]);
    return 0;
}