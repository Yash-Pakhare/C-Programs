#include<stdio.h>
#include<stdlib.h>
#define MAX_VERTICES 100
struct node
{
    int vertex;
    struct node* next;
};
struct adjList
{
    struct node* head;
};
struct graph
{
    int numVertices;
    struct adjList** array;
};
struct node* createNode(int vertex)
{
    struct node* x;
    x=(struct node*)malloc(sizeof(struct node));
    x->vertex=vertex;
    x->next=NULL;
    return x;
}
struct graph* createGraph(int numVertices)
{
    struct graph* x;
    x=(struct graph*)malloc(sizeof(struct graph));
    x->numVertices=numVertices;
    x->array=(struct adjList**)malloc(numVertices*sizeof(struct adjList*));
    for(int i=0;i<numVertices;i++)
        x->array[i]=(struct adjList*)malloc(sizeof(struct adjList));
    for(int i=0;i<numVertices;i++)
        x->array[i]->head=(struct node*)malloc(sizeof(struct node));
    printf("Enter the data of each node: ");
    for(int i=0;i<numVertices;i++)
    {
        scanf("%d",&x->array[i]->head->vertex);
        x->array[i]->head->next=NULL;
    }
    return x;
}
void addEdge(struct graph* g, int src, int dest)
{
    struct node* x=createNode(g->array[dest]->head->vertex);
    struct node* y=g->array[src]->head->next;
    g->array[src]->head->next=x;
    x->next=y;
}
void displayGraph(struct graph* g)
{
    printf("Adjacency List Representation:\n");
    for(int i=0;i<g->numVertices;i++)
    {
        printf("Vertex %d: ", i);
        struct node* temp=g->array[i]->head;
        while(temp)
        {
            printf("%d -> ", temp->vertex);
            temp=temp->next;
        }
        printf("NULL\n");
    }
}
int main()
{
    int numVertices;
    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);
    struct graph* g=createGraph(numVertices);
    printf("Enter the adjacency matrix:\n");
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
    for(int i=0;i<numVertices;i++)
    {
        for(int j=0;j<numVertices;j++)
        {
            scanf("%d", &adjacencyMatrix[i][j]);
            if(adjacencyMatrix[i][j]==1)
                addEdge(g,i,j);
        }
    }
    displayGraph(g);
    return 0;
}