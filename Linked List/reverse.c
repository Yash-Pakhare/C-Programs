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
void reverse(struct node* n)
{
    struct node* p;
    p=n;
    n=n->next;
    p->next=NULL;
    while(n!=NULL)
    {
        struct node* t;
        t=p;
        p=n;
        n=n->next;
        p->next=t;
    }
    first=p;
}
int main()
{
    int a[5]={1,2,3,4,5};
    create(a,5);
    display(first);
    reverse(first);
    display(first);
    return 0;
}