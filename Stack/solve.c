#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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
    printf("Enter the size of stack: ");
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
    return __INT_MAX__;
}
int peek(struct stack* s, int index)
{
    if(s->top-index+1>=0)
        return s->elements[s->top-index+1];
    printf("Invalid index\n");
    return -1;
}
int solve(struct stack* s, char** str, int l)
{
    int x=0,y=0;
    for(int i=0;i<l;i++)
    {
        if(strcmp(str[i],"0")==0)
            push(s,atoi(str[i]));
        if(atoi(str[i]))
            push(s,atoi(str[i]));
        if(str[i][0]=='+')
        {
            x=pop(s);
            y=pop(s);
            if(x==__INT_MAX__ || y==__INT_MAX__)
                break;
            push(s,y+x);
        }
        else if(str[i][0]=='-')
        {
            x=pop(s);
            y=pop(s);
            if(x==__INT_MAX__ || y==__INT_MAX__)
                break;
            push(s,y-x);
        }
        else if(str[i][0]=='*')
        {
            x=pop(s);
            y=pop(s);
            if(x==__INT_MAX__ || y==__INT_MAX__)
                break;
            push(s,y*x);
        }
        else if(str[i][0]=='/')
        {
            x=pop(s);
            y=pop(s);
            if(x==__INT_MAX__ || y==__INT_MAX__)
                break;
            push(s,y/x);
        }
    }
    int r=pop(s);
    if(isEmpty(s) && x!=__INT_MAX__ && y!=__INT_MAX__)
        return r;
    printf("Invalid expression\n");
    return __INT_MAX__;
}
int main()
{
    char** str;
    str=(char**)malloc(50*sizeof(char*));
    for(int i=0;i<50;i++)
        str[i]=(char*)malloc(5*sizeof(char));
    printf("Enter the postfix expression (if finished type 'end'): ");
    int l=0;
    for(l=0;;l++)
    {
        scanf("%s",str[l]);
        if(strcmp(str[l],"end")==0)
            break;
    }
    struct stack* s;
    s=(struct stack*)malloc(sizeof(struct stack));
    create(s);
    int r=solve(s,str,l);
    if(r!=__INT_MAX__)
        printf("%d",r);
    return 0;
}