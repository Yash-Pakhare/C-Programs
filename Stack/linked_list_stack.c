#include<stdio.h>
#include<stdlib.h>
struct stack
{
    int data;
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
        printf("%d ",s->data);
        s=s->next;
    }
    if(isEmpty(top))
        printf("Stack underflow\n");
    else
        printf("\n");
}
void push(struct stack** top, int n)
{
    struct stack* s;
    s=(struct stack*)malloc(sizeof(struct stack));
    s->data=n;
    s->next=(*top);
    (*top)=s;
}
int pop(struct stack** top)
{
    if(!isEmpty(top))
    {
        int x=(*top)->data;
        struct stack* s;
        s=(*top);
        (*top)=(*top)->next;
        free(s);
        return x;
    }
    printf("Stack underflow\n");
    return -1;
}
int main()
{
    struct stack** s=create(s);
    push(s,1);
    push(s,2);
    display(s);
    pop(s);
    pop(s);
    display(s);
    return 0;
}