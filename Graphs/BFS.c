#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct G
{
    struct G* pred;
    int data;
    int dist;
    char color[10];
};
struct node
{
    struct G* g_node;
    struct node* next;
};
struct queue
{
    struct G* data;
    struct queue* next;
}*rear=NULL,*front=NULL;
int isEmpty()
{
    struct queue* q=front;
    if(q==NULL)
        return 1;
    return 0;
}
void enqueue(struct G* n)
{
    struct queue* q=rear;
    struct queue* t;
    t=(struct queue*)malloc(sizeof(struct queue));
    t->data=n;
    t->next=NULL;
    if(isEmpty())
        front=t;
    else
        q->next=t;
    rear=t;   
}
struct G* dequeue()
{
    struct queue* q=front;
    struct G* x=NULL;
    if(isEmpty())
        printf("Queue underflow\n");
    else
    {
        x=q->data;
        if(q->next==NULL)
        {
            free(q);
            front=NULL;
            rear=NULL;
        }
        else
        {
            front=q->next;
            free(q);
        }
    }
    return x;
}
void display()
{
    struct queue* q=front;
    if(isEmpty())
        printf("Queue underflow\n");
    else
    {
        while(q!=NULL)
        {
            printf("%d ",q->data->data);
            q=q->next;
        }
        printf("\n");
    }
}
void BFS(struct node* G[], int n, struct G* s)
{
    s->dist=0;
    strcpy(s->color,"Grey");
    enqueue(s);
    while(!isEmpty())
    {
        struct G* x=dequeue();
        printf("%d ",x->data);
        struct node* a;
        for(int i=0;i<n;i++)
        {
            if(G[i]->g_node->data==x->data)
            {
                a=G[i]->next;
                break;
            }
        }
        while(a!=NULL)
        {
            if(strcmp(a->g_node->color,"White")==0)
            {
                strcpy(a->g_node->color,"Grey");
                a->g_node->dist=x->dist+1;
                a->g_node->pred=x;
                enqueue(a->g_node);
            }
            a=a->next;
        }
        strcpy(x->color,"Black");
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
    printf("BFS Traversal: ");
    BFS(A,n,V[0]);
    return 0;
}