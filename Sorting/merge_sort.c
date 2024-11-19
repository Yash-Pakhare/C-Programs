#include<stdio.h>
void merge(int* a, int p, int r, int q)
{
    int a1[r-p+1],a2[q-r+1],l=0;
    for(int i=p;i<r;i++)
        a1[l++]=a[i];
    a1[l]=__INT_MAX__;
    l=0;
    for(int i=r;i<q;i++)
        a2[l++]=a[i];
    a2[l]=__INT_MAX__;
    l=0;
    int b[q-p],i=0,j=0;
    for(int k=0;k<q-p;k++)
    {
        if(a1[i]<=a2[j])
        {
            b[k]=a1[i];
            i++;
        }
        else
        {
            b[k]=a2[j];
            j++;
        }
    }
    for(int k=p;k<q;k++)
        a[k]=b[l++];
}
void merge_sort(int* a, int p, int q)
{
    int r=(p+q)/2;
    if(q-p>1)
    {
        merge_sort(a,p,r);
        merge_sort(a,r,q);
        merge(a,p,r,q);
    }
}
int main()
{
    int n;
    printf("Enter size of array: ");
    scanf("%d",&n);
    int a[n];
    printf("Enter elements of array: ");
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    merge_sort(a,0,n);
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);
    return 0;
}