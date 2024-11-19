#include<stdio.h>
#include<math.h>
int fact(int n)
{
    if(n<=1)
        return 1;
    return n*fact(n-1);
}
void sumup(double* a, int n)
{
    double b[n],sum;
    for(int i=0;i<n;i++)
    {
        sum=0;
        for(int j=0;j<i+1;j++)
            sum+=a[j];
        b[i]=sum;
    }
    for(int i=0;i<n;i++)
        a[i]=b[i];
}
double taylor_series(int n, int x, int i, double* a)
{
    double s=pow(x,i-n)/(double)fact(i-n);
    a[i-n]=s;
    if(n==1)
    {
        sumup(a,i);
        return s;
    }
    return s+taylor_series(n-1,x,i,a);
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
    double t=taylor_series(n,x,n,a);
    for(int i=0;i<n;i++)
        printf("%lf ",a[i]);
    return 0;
}