#include<stdio.h>
#include<stdlib.h>
struct queue
{
    int data;
    struct queue* next;
}*rear=NULL,*front=NULL;
int isEmpty()
{
    struct queue* q=front;
    if(q==NULL)
        return 1;
    return 0;
}
int getFront()
{
    if(isEmpty())
    {
        printf("Queue underflow\n");
        return -1;
    }
    return front->data;
}
int getRear()
{
    if(isEmpty())
    {
        printf("Queue underflow\n");
        return -1;
    }
    return rear->data;
}
void enqueue(int n)
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
int dequeue()
{
    struct queue* q=front;
    int x=-1;
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
            printf("%d ",q->data);
            q=q->next;
        }
        printf("\n");
    }
}
int main()
{
    int choice;
    while(1)
    {
        printf("Enter choice: ");
        scanf("%d",&choice);
        if(choice==1)
            display();
        if(choice==2)
        {
            if(isEmpty())
                printf("Queue is empty\n");
            else
                printf("Queue is not empty\n");
        }
        if(choice==3)
        {
            int n;
            printf("Enter element: ");
            scanf("%d",&n);
            enqueue(n);
        }
        if(choice==4)
        {
            int n=dequeue();
            if(n>=0)
                printf("Element dequeued: %d\n",n);
        }
        if(choice==5)
            printf("Front Element: %d\n",getFront());
        if(choice==6)
            printf("Rear Element: %d\n",getRear());
        if(choice==7)
            break;
    }
    return 0;
}