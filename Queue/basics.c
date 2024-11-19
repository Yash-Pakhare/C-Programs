#include<stdio.h>
#include<stdlib.h>
struct queue
{
    int max_size;
    int* element;
    int front;
    int rear;
};
int isEmpty(struct queue* q)
{
    if(q->front==q->rear && q->front==-1)
        return 1;
    return 0;
}
int isFull(struct queue* q)
{
    if(q->rear==q->max_size-1)
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
    q->front=-1;
    q->rear=-1;
}
void enqueue(struct queue* q, int n)
{
    if(isFull(q))
        printf("Queue overflow\n");
    else
        q->element[++(q->rear)]=n;
    if(q->front==-1)
        q->front=0;
}
int dequeue(struct queue* q)
{
    int x=-1;
    if(isEmpty(q))
        printf("Queue underflow\n");
    else
    {
        x=q->element[q->front];
        for(int i=0;i<q->rear;i++)
            q->element[i]=q->element[i+1];
        --(q->rear);
    }
    if(q->rear==-1)
        q->front=-1;
    return x;
}
void display(struct queue* q)
{
    if(!isEmpty(q))
    {
        for(int i=q->front;i<=q->rear;i++)
            printf("%d ",q->element[i]);
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