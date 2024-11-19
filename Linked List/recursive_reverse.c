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
struct node* reverse(struct node* n)
{
    struct node* p;
    struct node* q;
    if(n->next!=NULL)
    {
        q=reverse(n->next);
        q->next=n;
    }
    else
        p=n;
    if(n==first)
    {
        n->next=NULL;
        first=p;
        return first;        
    }
    return n;
}
int main()
{
    int a[5]={1,2,3,4,5};
    create(a,5);
    display(first);
    struct node* p=reverse(first);
    display(p);
    display(first);
    return 0;
}