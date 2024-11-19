#include<stdio.h>
#include<stdlib.h>
// To be completed
struct stack
{
    int size;
    int top;
    int* elements;
};
int isEmpty(struct stack* s)
{
    if(s->top==-1)
        return 1;
    return 0;
}
int isFull(struct stack* s)
{
    if(s->top==s->size-1)
        return 1;
    return 0;
}
void create(struct stack* s)
{
    printf("Enter the size: ");
    scanf("%d",&s->size);
    s->top=-1;
    s->elements=(int*)malloc(s->size*sizeof(int));
}
void display(struct stack* s)
{
    if(isEmpty(s))
        printf("Stack underflow");
    for(int i=s->top;i>=0;i--)
        printf("%d ",s->elements[i]);
    printf("\n");
}
void push(struct stack* s, int n)
{
    if(!isFull(s))
        s->elements[++(s->top)]=n;
    else
        printf("Stack overflow\n");
}
int pop(struct stack* s)
{
    if(!isEmpty(s))
        return s->elements[s->top--];
    printf("Stack underflow\n");
    return -1;
}
int peek(struct stack* s, int index)
{
    if(s->top-index+1>=0)
        return s->elements[s->top-index+1];
    printf("Invalid index\n");
    return -1;
}
// void hanoi(int n, int a, int b, int c)
void hanoi(int n, struct stack *a, struct stack *b, struct stack *c)
{
    if(n==1)
    {
        push(c,pop(a));
    }
    else
    {
        hanoi(n-1,a,c,b);
        push(c,pop(a));
        hanoi(n-1,b,a,c);
    }
}
int main()
{
    struct stack* a;
    struct stack* b;
    struct stack* c;
    a=(struct stack*)malloc(sizeof(struct stack));
    b=(struct stack*)malloc(sizeof(struct stack));
    c=(struct stack*)malloc(sizeof(struct stack));
    create(a);
    create(b);
    create(c);
    for(int i=3;i>=1;i--)
        push(a,i);
    hanoi(3,a,b,c);
    // hanoi(3,1,2,3);
    return 0;
}