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
    int i,j,k,flag;
    for(i=0;i<n;i++)
    {
        flag=0;
        k=i;
        for(j=i+1;j<n;j++)
        {
            if(a[j]<=a[k])
            {
                flag=1;
                k=j;
            }
        }
        if(flag==0)
            break;
        swap(&a[i],&a[k]);
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