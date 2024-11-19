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
void insert(struct node* n, int value)
{
    struct node* t;
    t=(struct node*)malloc(sizeof(struct node));
    t->data=value;
    if(n->data >= value)
    {
        t->next=n;
        first=t;
    }
    else
    {
        struct node* p;
        while(n!=NULL && n->data<value)
        {    
            p=n;
            n=n->next;
        }
        p->next=t;
        t->next=n;
    }
}
int main()
{
    int a[5]={2,5,10,22,50};
    create(a,5);
    display(first);
    insert(first,30);
    display(first);
    return 0;
}