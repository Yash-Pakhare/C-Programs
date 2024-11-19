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
void delete(struct node* n, int key)
{
    int flag=0;
    struct node* p;
    if(n->data==key)
    {
        flag=1;
        p=first;
        first=first->next;
        free(p);
    }
    while(n!=NULL && flag==0)
    {
        if(n->data==key)
        {
            p->next=n->next;
            free(n);
            break;
        }
        p=n;
        n=n->next;
    }
}
int main()
{
    int a[5]={1,2,3,4,5};
    create(a,5);
    display(first);
    delete(first,1);
    display(first);
    return 0;
}