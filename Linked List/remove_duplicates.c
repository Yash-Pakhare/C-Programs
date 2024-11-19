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
void remove_duplicates(struct node* n)
{
    struct node* p;
    p=n;
    n=n->next;
    while(n!=NULL)
    {
        if(p->data==n->data)
        {
            p->next=n->next;
            free(n);
            n=p->next;
        }
        else
        {
            p=p->next;
            n=p->next;
        }
    }
}
int main()
{
    int a[5]={1,1,4,4,4};
    create(a,5);
    display(first);
    remove_duplicates(first);
    display(first);
    return 0;
}