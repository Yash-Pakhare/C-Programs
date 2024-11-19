#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
    struct node* prev;
}*first=NULL,*end=NULL;
void insert(struct node* n, int x, int k)
{
    struct node* t;
    t=(struct node*)malloc(sizeof(struct node));
    t->data=x;
    if(k==0)
    {
        t->next=n;
        t->prev=NULL;
        n->prev=t;
        first=t;
    }
    else
    {
        struct node* p;
        while(k-- && n!=NULL)
        {
            p=n;
            n=n->next;
        }
        p->next=t;
        t->prev=p;
        t->next=n;
        if(n!=NULL)
            n->prev=t;
    }
}
void delete(struct node* n, int key)
{
    if(n->data==key)
    {
        first=n->next;
        n->next->prev=NULL;
        free(n);
    }
    else
    {
        while(n!=NULL)
        {
            if(n->data==key)
            {
                n->prev->next=n->next;
                if(n->next!=NULL)
                    n->next->prev=n->prev;
                free(n);
                break;
            }
            n=n->next;
        }
        if(n==NULL)
            printf("Key not found\n");
    }
}
void create(int* a, int n)
{
    struct node* last;
    struct node* t;
    first=(struct node*)malloc(sizeof(struct node));
    last=(struct node*)malloc(sizeof(struct node));
    first->data=a[0];
    first->next=NULL;
    first->prev=NULL;
    last=first;
    for(int i=1;i<n;i++)
    {
        t=(struct node*)malloc(sizeof(struct node));
        t->data=a[i];
        t->next=NULL;
        t->prev=last;
        last->next=t;
        last=t;
    }
    end=last;
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
int main()
{
    int a[5]={1,2,3,4,5};
    create(a,5);
    display(first);
    struct node* n;
    n=first;
    n=n->next;
    printf("%d\n",n->data);
    printf("%d\n",n->prev->data);
    printf("%d\n",end->data);
    insert(first,10,5);
    display(first);
    delete(first,10);
    display(first);
    return 0;
}