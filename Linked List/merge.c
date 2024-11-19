#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
}*first=NULL,*second=NULL,*third=NULL;
void create(int* a, int* b, int n1, int n2)
{
    struct node* last;
    struct node* t;
    first=(struct node*)malloc(sizeof(struct node));
    last=(struct node*)malloc(sizeof(struct node));
    first->data=a[0];
    first->next=NULL;
    last=first;
    for(int i=1;i<n1;i++)
    {
        t=(struct node*)malloc(sizeof(struct node));
        t->data=a[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
    second=(struct node*)malloc(sizeof(struct node));
    last=(struct node*)malloc(sizeof(struct node));
    second->data=b[0];
    second->next=NULL;
    last=second;
    for(int i=1;i<n2;i++)
    {
        t=(struct node*)malloc(sizeof(struct node));
        t->data=b[i];
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
void merge(struct node* a, struct node* b)
{
    struct node* last;
    struct node* t;
    third=(struct node*)malloc(sizeof(struct node));
    if(a->data < b->data)
    {
        third->data=a->data;
        a=a->next;
    }
    else
    {
        third->data=b->data;
        b=b->next;
    }
    last=(struct node*)malloc(sizeof(struct node));
    third->next=NULL;
    last=third;
    while(1)
    {
        t=(struct node*)malloc(sizeof(struct node));
        if(a==NULL)
        {
            while(b!=NULL)
            {
                t->data=b->data;
                t->next=NULL;
                last->next=t;
                last=t;
                b=b->next;
            }
            break;
        }
        if(b==NULL)
        {
            while(a!=NULL)
            {
                t->data=a->data;
                t->next=NULL;
                last->next=t;
                last=t;
                a=a->next;
            }
            break;
        }
        if(a->data < b->data)
        {
            t->data=a->data;
            t->next=NULL;
            last->next=t;
            last=t;
            a=a->next;
        }
        else
        {
            t->data=b->data;
            t->next=NULL;
            last->next=t;
            last=t;
            b=b->next;
        }
    }
}
int main()
{
    int a[5]={1,3,5,7,9};
    int b[5]={2,4,6,8,10};
    create(a,b,5,5);
    merge(first,second);
    display(third);
    return 0;
}