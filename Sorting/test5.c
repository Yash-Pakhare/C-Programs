#include<stdio.h>
#include<stdlib.h>
int compare(const void* a, const void* b)
{
    return (*(int*)a - *(int*)b);
}
int main()
{
    int a[4]={33,1,5,2};
    qsort(a,4,sizeof(int),compare);
    for(int i=0;i<4;i++)
        printf("%d ",a[i]);
    return 0;
}