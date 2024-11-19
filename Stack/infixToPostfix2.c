#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct stack
{
    int size;
    int top;
    char* elements;
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
    s->elements=(char*)malloc(s->size*sizeof(char));
}
void display(struct stack* s)
{
    if(isEmpty(s))
        printf("Stack underflow");
    for(int i=s->top;i>=0;i--)
        printf("%c ",s->elements[i]);
    printf("\n");
}
void push(struct stack* s, char c)
{
    if(!isFull(s))
        s->elements[++(s->top)]=c;
    else
        printf("Stack overflow\n");
}
char pop(struct stack* s)
{
    if(!isEmpty(s))
        return s->elements[s->top--];
    printf("Stack underflow\n");
    return '\0';
}
char peek(struct stack* s, int index)
{
    if(s->top-index+1>=0)
        return s->elements[s->top-index+1];
    // printf("Invalid index\n");
    return '\0';
}
int priority(char c)
{
    if(c=='\0')
        return 0;
    if(c=='+' || c=='-')
        return 1;
    if(c=='*' || c=='/')
        return 2;
    return 3;
}
char* postfix(char* str)
{
    struct stack* t;
    t=(struct stack*)malloc(sizeof(struct stack));
    create(t);
    char* pstr;
    pstr=(char*)malloc(100*sizeof(char));
    int l=0;
    char c;
    for(int i=0;i<strlen(str);i++)
    {
        if((int)str[i]>=(int)'a' && (int)str[i]<=(int)'z')
            pstr[l++]=str[i];
        else if(str[i]=='(')
            push(t,'(');
        else if(str[i]==')')
        {
            c=peek(t,1);
            while(c!='(' && !isEmpty(t))
            {
                c=pop(t);
                if(c!='(')
                    pstr[l++]=c;
            }
        }
        else if(priority(peek(t,1))>=priority(str[i]))
        {
            c=pop(t);
            if(c!='(')
                pstr[l++]=c;
            push(t,str[i]);
        }
        else
            push(t,str[i]);    
    }
    while(!isEmpty(t))
    {
        c=pop(t);
        if(c!='(')
            pstr[l++]=c;
    }
    pstr[l]='\0';
    return pstr;
}
int main()
{
    char* str;
    str=(char*)malloc(100*sizeof(char));
    printf("Enter infix expression: ");
    scanf("\n%[^\n]s",str);
    char* r;
    r=postfix(str);
    printf("%s",r);
    return 0;
}