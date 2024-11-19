#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int* create(int n)
{
    int size=pow(2,n)-1;
    int* a;
    a=(int*)malloc(size*sizeof(int));
    for(int i=0;i<size;i++)
        a[i]=-1;
    return a;
}
// insertion is like binary search tree
void insert(int* a, int size, int k)
{
    int i=0;
    while(i<size)
    {
        if(a[i]==-1)
        {
            a[i]=k;
            break;
        }
        if(k<a[i])
            i=(2*i)+1;
        else if(k>a[i])
            i=(2*i)+2;
        else
            printf("Key already exists");
    }
}
int search(int* a, int size, int k)
{
    int x=-1;
    int i=0;
    while(i<size)
    {
        if(a[i]==-1)
        {
            printf("Element not found");
            break;
        }
        if(k<a[i])
            i=(2*i)+1;
        else if(k>a[i])
            i=(2*i)+2;
        else
        {
            x=i;
            break;
        }
    }
    return x;
}
void delete(int* a, int size, int k)
{
    int i=0;
    while(i<size)
    {
        if(a[i]==-1)
        {
            printf("Element not found");
            break;
        }
        if(k<a[i])
            i=(2*i)+1;
        else if(k>a[i])
            i=(2*i)+2;
        else
        {
            a[i]=-1;
            printf("Element deleted");
        }
    }
}
int main()
{
    int n=4;
    int size=pow(2,n)-1;
    int* t=create(n);
    insert(t,size,1);
    insert(t,size,2);
    insert(t,size,3);
    for(int i=0;i<size;i++)
        printf("%d ",t[i]);
    return 0;
}