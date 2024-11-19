#include<stdio.h>
#include<stdlib.h>
int compare(const void* a, const void* b)
{
    const int* r1=(const int*)a;
    const int* r2=(const int*)b;
    if(r1[0]!=r2[0])
        return r1[0]-r2[0];
    return r1[1]-r2[1];
}
int main()
{
    int a[4][2]={{3,2},{3,1},{2,2},{2,1000}};
    qsort(a,4,sizeof(a[0]),compare);
    for(int i=0;i<4;i++)
        printf("(%d, %d)\n",a[i][0],a[i][1]);
    return 0;
}