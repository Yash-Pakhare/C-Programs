#include<stdio.h>
int sum=0;
void rotate(int* a, int n, int i)
{
    int temp=a[i];
    for(int j=i;j<n;j++)
        a[j]=a[j+1];
    a[n-1]=temp;
}
void permute(int* a, int n, int i)
{
    if(i==n)
    {
        for(int j=0;j<n;j++)
            printf("%d ",a[j]);
        printf("\n");
        sum++;
    }
    else
    {
        for(int j=i;j<n;j++)
        {
            permute(a,n,i+1);
            rotate(a,n,i);
        }
    }
}
int main()
{
    int n;
    printf("Enter size: ");
    scanf("%d",&n);
    int a[n];
    printf("Enter array: ");
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    permute(a,n,0);
    printf("%d",sum);
    return 0;
}