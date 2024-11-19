#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
}*first=NULL;
void create(int* a, int n)
{
    struct node* last;
    struct node* t;
    first=(struct node*)malloc(sizeof(struct node));
    last=(struct node*)malloc(sizeof(struct node));
    first->data=a[0];
    first->next=NULL;
    last=first;
    for(int i=1;i<n;i++)
    {
        t=(struct node*)malloc(sizeof(struct node));
        t->data=a[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}
void display(struct node* n)
{
    while(n!=NULL)
    {
        printf("%d ",n->data);
        n=n->next;
    }
    printf("\n");
}
void swap(struct node* a, struct node* b)
{
    int temp=a->data;
    a->data=b->data;
    b->data=temp;
}
int count(struct node* n)
{
    int c=0;
    while(n!=NULL)
    {
        n=n->next;
        c++;
    }
    return c;
}
void sort(struct node* n, int c)
{
    int flag=0;
    int x=c;
    struct node* p;
    p=n;
    n=n->next;
    c--;
    while(c--)
    {
        if(p->data > n->data)
        {
            flag=1;
            swap(p,n);
        }
        p=n;
        n=n->next;
    }
    if(flag==1)
        sort(first,x-1);
}
int main()
{
    int a[5]={3,523,334,1,3};
    create(a,5);
    display(first);
    sort(first,count(first));
    display(first);
    return 0;
}