#include<stdio.h>
void swap(int* a, int* b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
int partition(int* a, int p, int q)
{
    int pivot=p;
    int i=p,j=q;
    while(i<j)
    {
        do
        {
            i++;
        }while(a[i]<=a[pivot]);
        do
        {
            j--;
        }while(a[j]>a[pivot]);
        if(i<j)
            swap(&a[i],&a[j]);
    }
    swap(&a[pivot],&a[j]);
    return j;
}
void quick_sort(int* a, int p, int q)
{
    int r=partition(a,p,q);
    if(p<q)
    {
        quick_sort(a,p,r);
        quick_sort(a,r+1,q);
    }
}
int main()
{
    int n;
    printf("Enter n: ");
    scanf("%d",&n);
    int a[n];
    printf("Enter the array: ");
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    quick_sort(a,0,n);
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);
    return 0;
}