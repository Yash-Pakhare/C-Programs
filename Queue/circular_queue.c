#include<stdio.h>
#include<stdlib.h>
struct queue
{
    int max_size;
    int* element;
    int front;
    int rear;
    int count;
};
int isEmpty(struct queue* q)
{
    if(q->count==0)
        return 1;
    return 0;
}
int isFull(struct queue* q)
{
    if(q->count==q->max_size)
        return 1;
    return 0;
}
int getRear(struct queue* q)
{
    if(!isEmpty(q))
        return q->element[q->rear];
    printf("Queue underflow\n");
    return -1;
}
int getFront(struct queue* q)
{
    if(!isEmpty(q))
        return q->element[q->front];
    printf("Queue underflow\n");
    return -1;
}
void create(struct queue* q)
{
    printf("Enter size of the queue: ");
    scanf("%d",&q->max_size);
    q->element=(int*)malloc((q->max_size)*sizeof(int));
    q->front=0;
    q->rear=0;
    q->count=0;
}
void enqueue(struct queue* q, int n)
{
    if(isFull(q))
        printf("Queue overflow\n");
    else
    {
        if(!isEmpty(q))
            q->rear=(q->rear+1)%(q->max_size);
        q->element[q->rear]=n;
        ++(q->count);
    }
}
int dequeue(struct queue* q)
{
    int x=-1;
    if(isEmpty(q))
        printf("Queue underflow\n");
    else
    {
        x=q->element[q->front];
        q->front=(q->front+1)%(q->max_size);
        --(q->count);
        if(q->count==0)
            q->rear=q->front;
    }
    return x;
}
void display(struct queue* q)
{
    if(!isEmpty(q))
    {
        for(int i=q->front;i<q->front+q->count;i++)
            printf("%d ",q->element[i%(q->max_size)]);
        printf("\n");
    }
    else
        printf("Queue underflow\n");
}
int main()
{
    struct queue* q;
    q=(struct queue*)malloc(sizeof(struct queue));
    create(q);
    int choice;
    while(1)
    {
        printf("Enter choice: ");
        scanf("%d",&choice);
        if(choice==1)
            display(q);
        if(choice==2)
        {
            if(isEmpty(q))
                printf("Queue is empty\n");
            else
                printf("Queue is not empty\n");
        }
        if(choice==3)
        {
            if(isFull(q))
                printf("Queue is full\n");
            else
                printf("Queue is not full\n");
        }
        if(choice==4)
        {
            int x;
            printf("Enter an element: ");
            scanf("%d",&x);
            enqueue(q,x);
        }
        if(choice==5)
        {
            int x=dequeue(q);
            if(x>=0)
                printf("Element dequeued: %d\n",x);
        }
        if(choice==6)
            if(getFront(q)>=0)
                printf("Front element: %d\n",getFront(q));
        if(choice==7)
            if(getRear(q)>=0)
                printf("Rear element: %d\n",getRear(q));
        if(choice==8)
            break;
    }
    return 0;
}