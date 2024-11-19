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
int time=0;
void visit(struct node* G[], int n, struct G* s)
{
    strcpy(s->color,"Grey");
    printf("%d ",s->data);
    s->dt=(++time);
    struct node* a;
    for(int i=0;i<n;i++)
    {
        if(G[i]->g_node->data==s->data)
        {
            a=G[i]->next;
            break;
        }
    }
    while(a!=NULL)
    {
        if(strcmp(a->g_node->color,"White")==0)
        {
            a->g_node->dist=s->dist+1;
            a->g_node->pred=s;
            visit(G,n,a->g_node);
        }
        a=a->next;
    }
    strcpy(s->color,"Black");
    s->et=(++time);
}
void DFS(struct node* G[], int n)
{
    G[0]->g_node->dist=0;
    for(int i=0;i<n;i++)
        if(strcmp(G[i]->g_node->color,"White")==0)
            visit(G,n,G[i]->g_node);
    printf("\n");
    for(int i=0;i<n;i++)
        strcpy(G[i]->g_node->color,"White");
    time=0;
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
    DFS(A,n);
    printf("Start & End times of each node: ");
    for(int i=0;i<n;i++)
        printf("Node with data %d: start=%d, end=%d\n",V[i]->data,V[i]->dt,V[i]->et);
    return 0;
}