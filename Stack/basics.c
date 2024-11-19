#include<stdio.h>
#include<stdlib.h>
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
int main()
{
    struct stack* s;
    s=(struct stack*)malloc(sizeof(struct stack));
    int x;
    create(s);
    display(s);
    push(s,1);
    display(s);
    x=pop(s);
    printf("%d\n",x);
    x=pop(s);
    printf("%d\n",x);
    for(int i=0;i<s->size;i++)
        push(s,i+1);
    display(s);
    push(s,100);
    x=pop(s);
    printf("%d\n",x);
    display(s);
    x=peek(s,1);
    printf("%d\n",x);
    return 0;
}