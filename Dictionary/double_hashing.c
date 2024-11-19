#include<stdio.h>
#include<stdlib.h>
int hash(int key, int size)
{
    return key%size;
}
int findR(int size)
{
    for(int i=size-1;i>=2;i--)
    {
        int j;
        for(j=2;j<i;j++)
        {
            if(i%j==0)
                break;
        }
        if(j==i)
            return i;
    }
    return 2;
}
void insert(int* H, int size, int key)
{
    int flag=0;
    int index=hash(key,size);
    int R=findR(size);
    int x;
    for(int i=0;i<size;i++)
    {
        x=(index+(i*(R-(key%R))))%size;
        if(H[x]<0)
        {
            flag=1;
            H[x]=key;
            break;
        }
    }
    if(flag==0)
        printf("Hash Table is Full\n");
}
int search(int* H, int size, int key)
{
    int index=hash(key,size);
    int R=findR(size);
    int x;
    for(int i=0;i<size;i++)
    {
        x=(index+(i*(R-(key%R))))%size;
        if(H[x]==key)
            return x;
    }
    return -1;
}
int delete(int* H, int size, int key)
{
    int index=hash(key,size);
    int R=findR(size);
    int x;
    for(int i=0;i<size;i++)
    {
        x=(index+(i*(R-(key%R))))%size;
        if(H[x]==key)
        {
            H[x]=-1;
            return x;
        }
    }
    return -1;
}
int main()
{
    int* H;
    int size=10;
    H=(int*)malloc(size*sizeof(int));
    for(int i=0;i<size;i++)
        H[i]=-1;
    insert(H,size,1);
    insert(H,size,2);
    insert(H,size,22);
    insert(H,size,32);
    printf("%d\n",search(H,size,2));
    printf("%d\n",delete(H,size,2));
    printf("%d\n",search(H,size,2));
    insert(H,size,2);
    printf("%d\n",search(H,size,22));
    printf("%d\n",search(H,size,32));
    return 0;
}