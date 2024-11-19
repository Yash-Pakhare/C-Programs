#include<stdio.h>
#include<stdlib.h>
#define MAX_VERTICES 100
struct vertex{
    char name;
    int in_deg;
};
struct graph{
    struct vertex v[MAX_VERTICES];
    int adj[MAX_VERTICES][MAX_VERTICES];
};
struct stack
{
    char data;
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
void display(struct stack* s)
{
    if(s->next->next!=NULL)
        display(s->next);
    printf("%c ",s->data);

}
void push(struct stack** top, char n)
{
    struct stack* s;
    s=(struct stack*)malloc(sizeof(struct stack));
    s->data=n;
    s->next=(*top);
    (*top)=s;
}
char pop(struct stack** top)
{
    if(!isEmpty(top))
    {
        char x=(*top)->data;
        struct stack* s;
        s=(*top);
        (*top)=(*top)->next;
        free(s);
        return x;
    }
    return '\0';
}
void allTopologicalSorts(struct graph g, int n, struct stack** s, int* count){
    int flag=0;
    for(int i=0;i<n;i++)
    {
        if(g.v[i].in_deg==0)
        {
            flag=1;
            g.v[i].in_deg=-1;
            for(int j=0;j<n;j++)
                if(g.adj[i][j]==1)
                    g.v[j].in_deg--;
            push(s,g.v[i].name);
            allTopologicalSorts(g,n,s,count);
            g.v[i].in_deg=0;
            for(int j=0;j<n;j++)
                if(g.adj[i][j]==1)
                    g.v[j].in_deg++;
        }
    }
    if(flag==0)
    {
        struct stack* x;
        x=(*s);
        (*count)++;
        display(x);
        printf("\n");
    }
    pop(s);
}
int main()
{
    int n;
    printf("Enter the number of vertices: ");
    scanf("%d",&n);
    struct graph g;
    printf("Enter name of vertices (in order in which adjacency matrix is to be filled): ");
    for(int i=0;i<n;i++)
    {
        g.v[i].in_deg=0;
        scanf("\n%c",&g.v[i].name);
    }
    printf("Enter the inputs of adjacency matrix (with respect to out degree):\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&g.adj[i][j]);
            if(g.adj[i][j]==1)
                g.v[j].in_deg++;
        }
    }
    struct stack** s=create(s);
    int count=0;
    printf("All possible Topological sorts of given directed acyclic graph are:\n");
    allTopologicalSorts(g,n,s,&count);
    printf("Total number of Topological sorts are: %d",count);
    return 0;
}