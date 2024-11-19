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
    t->next=first;
}
void display(struct node* n)
{
    do
    {
        printf("%d ",n->data);
        n=n->next;
    }while(n!=first);
    printf("\n");
}
int main()
{
    int a[5]={1,2,3,4,5};
    create(a,5);
    display(first);
    struct node* n;
    n=first;
    for(int i=0;i<10;i++)
    {
        printf("%d ",n->data);
        n=n->next;
    }
    return 0;
}