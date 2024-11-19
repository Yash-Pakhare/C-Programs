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
    int flag=0;
    for(int i=0;i<n-1;i++)
    {
        if(a[i]>a[i+1])
        {
            flag=1;
            swap(&a[i],&a[i+1]);
        }
    }
    if(flag==1)
        sort(a,n-1);
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