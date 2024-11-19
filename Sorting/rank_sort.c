#include<stdio.h>
#include<stdlib.h>
void swap(int* a, int* b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
void sort(int* a, int n)
{
    int x[n];
    for(int i=0;i<n;i++)
        x[i]=0;
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(a[j]<a[i])
                x[i]++;
            else
                x[j]++;
        }
    }
    int y[n];
    for(int i=0;i<n;i++)
        y[x[i]]=a[i];
    for(int i=0;i<n;i++)
        a[i]=y[i];
}
int main()
{
    int n;
    printf("Enter the size of array: ");
    scanf("%d",&n);
    int* a;
    a=(int*)malloc(n*sizeof(int));
    printf("Enter elements of array: ");
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    sort(a,n);
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);
    return 0;
}