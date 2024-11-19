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
    int key;
    for(int i=1;i<n;i++)
    {
        key=a[i];
        if(a[i]>=a[i-1])
            continue;
        // for(int j=i;j>0;j--)
        //     if(a[j]<a[j-1])
        //         swap(&a[j],&a[j-1]);
        int j;
        for(j=i-1;j>=0;j--)
        {
            if(a[j]<key)
                break;
            a[j+1]=a[j];
        }
        a[j+1]=key;
    }
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