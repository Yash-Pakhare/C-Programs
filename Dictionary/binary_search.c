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
int binary_search(int* a, int key, int low, int high)
{
    if(low>high)
        return -1;
    int mid=(low+high)/2;
    if(a[mid]==key)
        return mid;
    else if(a[mid]>key)
        return binary_search(a,key,low,mid-1);
    else
        return binary_search(a,key,mid+1,high);
}
int main()
{
    int n;
    printf("Enter size of array: ");
    scanf("%d",&n);
    int* a;
    a=(int*)malloc(n*sizeof(int));
    printf("Enter the array: ");
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    sort(a,n);
    printf("Sorted array: ");
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");
    int key;
    printf("Enter element to search: ");
    scanf("%d",&key);
    int x=binary_search(a,key,0,n-1);
    if(x>=0)
        printf("Element found at position %d\n",x);
    else
        printf("Element not found\n");
    return 0;
}