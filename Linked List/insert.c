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
void insert(struct node* n, int index, int value)
{
    int size=0;
    struct node* x;
    x=n;
    while(x!=NULL)
    {
        x=x->next;
        size++;
    }
    while(n!=NULL && index>1 && index<=size)
    {
        n=n->next;
        index--;
    }
    struct node* t;
    t=(struct node*)malloc(sizeof(struct node));
    if(index!=0 && index<=size)
    {
        t->data=value;
        t->next=n->next;
        n->next=t;
    }
    else if(index<=size)
    {
        // int temp=n->data;
        // n->data=value;
        // t->next=n->next;
        // n->next=t;
        // t->data=temp;
        t->data=value;
        t->next=n;
        first=t;
    }
}
int main()
{
    int a[5]={1,2,3,4,5};
    create(a,5);
    display(first);
    insert(first,0,10);
    display(first);
    return 0;
}