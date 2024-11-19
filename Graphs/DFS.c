#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct G
{
    struct G* pred;
    int data;
    int dist;
    int dt;
    int et;
    char color[10];
};
struct node
{
    struct G* g_node;
    struct node* next;
};
struct stack
{
    struct G* data;
    struct stack* next;
};
int isEmpty(struct stack** top)
{
    if((*top)->next==NULL)
        return 1;
    return 0;
}
struct stack** create(struct stack** top)
{
    top=(struct stack**)malloc(sizeof(struct stack*));
    top[0]=(struct stack*)malloc(sizeof(struct stack));
    (*top)->next=NULL;
    return top;
}
void display(struct stack** top)
{
    struct stack* s;
    s=(*top);
    while(s->next!=NULL)
    {
        printf("%d ",s->data->data);
        s=s->next;
    }
    if(isEmpty(top))
        printf("Stack underflow\n");
    else
        printf("\n");
}
void push(struct stack** top, struct G* n)
{
    struct stack* s;
    s=(struct stack*)malloc(sizeof(struct stack));
    s->data=n;
    s->next=(*top);
    (*top)=s;
}
struct G* pop(struct stack** top)
{
    if(!isEmpty(top))
    {
        struct G* x=(*top)->data;
        struct stack* s;
        s=(*top);
        (*top)=(*top)->next;
        free(s);
        return x;
    }
    return NULL;
}
void DFS(struct node* G[], int n, struct G* s)
{
    int time=0;
    printf("%d ",s->data);
    s->dist=0;
    strcpy(s->color,"Grey");
    s->dt=(++time);
    struct stack** stk;
    stk=create(stk);
    struct G* x=s;
    while(x!=NULL)
    {
        struct node* a;
        for(int i=0;i<n;i++)
        {
            if(G[i]->g_node->data==x->data)
            {
                a=G[i]->next;
                break;
            }
        }
        while(strcmp(a->g_node->color,"White")!=0)
        {
            a=a->next;
            if(a==NULL)
                break;
        }
        if(a!=NULL)
        {
            printf("%d ",a->g_node->data);
            strcpy(a->g_node->color,"Grey");
            a->g_node->dt=(++time);
            a->g_node->pred=x;
            a->g_node->dist=x->dist+1;
            push(stk,x);
            x=a->g_node;
        }
        else
        {
            strcpy(x->color,"Black");
            x->et=(++time);
            x=pop(stk);
        }
    }
    printf("\n");
    for(int i=0;i<n;i++)
        strcpy(G[i]->g_node->color,"White");
}
int main()
{
    int n;
    printf("Enter no. of nodes: ");
    scanf("%d",&n);
    struct G* V[n];
    printf("Enter the data of each node: ");
    for(int i=0;i<n;i++)
    {
        V[i]=(struct G*)malloc(sizeof(struct G));
        scanf("%d",&V[i]->data);
        V[i]->dist=__INT_MAX__;
        strcpy(V[i]->color,"White");
        V[i]->pred=NULL;
    }
    struct node* A[n];
    for(int i=0;i<n;i++)
    {
        A[i]=(struct node*)malloc(sizeof(struct node));
        A[i]->g_node=V[i];
        A[i]->next=NULL;
    }

    for(int i=0;i<n;i++)
    {
        int x;
        printf("How many adjacents does node with data %d have: ",A[i]->g_node->data);
        scanf("%d",&x);
        printf("Enter adjacents of node with data %d: ",A[i]->g_node->data);
        int data;
        for(int j=0;j<x;j++)
        {   
            scanf("%d",&data);
            struct node* t;
            t=(struct node*)malloc(sizeof(struct node));
            for(int k=0;k<n;k++)
            {
                if(V[k]->data==data)
                {
                    t->g_node=V[k];
                    break;
                }
            }
            t->next=NULL;
            struct node* a=A[i];
            while(a->next!=NULL)
                a=a->next;
            a->next=t;
        }
    }
    printf("DFS Traversal: ");
    DFS(A,n,V[0]);
    printf("Start & End times of each node: ");
    for(int i=0;i<n;i++)
        printf("Node with data %d: start=%d, end=%d\n",V[i]->data,V[i]->dt,V[i]->et);
    return 0;
}