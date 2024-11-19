#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct stack
{
    int size;
    int top;
    char** elements;
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
    s->elements=(char**)malloc(s->size*sizeof(char*));
    for(int i=0;i<s->size;i++)
        s->elements[i]=(char*)malloc(50*sizeof(char));
}
void display(struct stack* s)
{
    if(isEmpty(s))
        printf("Stack underflow");
    for(int i=s->top;i>=0;i--)
        printf("%s ",s->elements[i]);
    printf("\n");
}
void push(struct stack* s, char* n)
{
    if(!isFull(s))
        strcpy(s->elements[++(s->top)],n);
    else
        printf("Stack overflow\n");
}
char* pop(struct stack* s)
{
    if(!isEmpty(s))
        return s->elements[s->top--];
    printf("Stack underflow\n");
    return "\0";
}
char* peek(struct stack* s, int index)
{
    if(s->top-index+1>=0)
        return s->elements[s->top-index+1];
    printf("Invalid index\n");
    return "\0";
}
char* solve(struct stack* s, char** str, int l)
{
    char* x;
    char* y;
    x=(char*)malloc(50*sizeof(char));
    y=(char*)malloc(50*sizeof(char));
    x[0]='\0';
    y[0]='\0';
    char* new;
    new=(char*)malloc(50*sizeof(char));
    for(int i=0;i<l;i++)
    {
        if((int)str[i][0]>=(int)'0' && (int)str[i][0]<=(int)'9')
            push(s,str[i]);
        else if(str[i][0]=='+')
        {
            strcpy(x,pop(s));
            strcpy(y,pop(s));
            if(!strcmp(x,"\0") || !strcmp(y,"\0"))
                break;
            free(new);
            new=(char*)malloc(50*sizeof(char));
            new[0]='\0';
            strcat(new,"(");
            strcat(new,x);
            strcat(new,"+");
            strcat(new,y);
            strcat(new,")");
            push(s,new);
        }
        else if(str[i][0]=='-')
        {
            strcpy(x,pop(s));
            strcpy(y,pop(s));
            if(!strcmp(x,"\0") || !strcmp(y,"\0"))
                break;
            free(new);
            new=(char*)malloc(50*sizeof(char));
            new[0]='\0';
            strcat(new,"(");
            strcat(new,x);
            strcat(new,"-");
            strcat(new,y);
            strcat(new,")");
            push(s,new);
        }
        else if(str[i][0]=='*')
        {
            strcpy(x,pop(s));
            strcpy(y,pop(s));
            if(!strcmp(x,"\0") || !strcmp(y,"\0"))
                break;
            free(new);
            new=(char*)malloc(50*sizeof(char));
            new[0]='\0';
            strcat(new,"(");
            strcat(new,x);
            strcat(new,"*");
            strcat(new,y);
            strcat(new,")");
            push(s,new);
        }
        else if(str[i][0]=='/')
        {
            strcpy(x,pop(s));
            strcpy(y,pop(s));
            if(!strcmp(x,"\0") || !strcmp(y,"\0"))
                break;
            free(new);
            new=(char*)malloc(50*sizeof(char));
            new[0]='\0';
            strcat(new,"(");
            strcat(new,x);
            strcat(new,"/");
            strcat(new,y);
            strcat(new,")");
            push(s,new);
        }
    }
    strcpy(new,pop(s));
    if(isEmpty(s) && strcmp(x,"\0") && strcmp(y,"\0"))
        return new;
    printf("Invalid expression\n");
    return "\0";
}
char* postfix(char* str)
{
    struct stack* t;
    t=(struct stack*)malloc(sizeof(struct stack));
    create(t);
    char* pstr;
    pstr=(char*)malloc(100*sizeof(char));
    int l=0;
    char* c;
    c=(char*)malloc(5*sizeof(char));
    c[0]='\0';
    for(int i=0;i<strlen(str);i++)
    {
        if(str[i]=='(')
            push(t,"(");
        else if(str[i]==')')
        {
            strcpy(c,pop(t));
            if(c[0]!='(')
                pstr[l++]=c[0];
        }
        else if(str[i]=='^')
        {
            if(isEmpty(t))
            {
                push(t,"^");
                continue;
            }
            if(!strcmp(peek(t,1),"("))
                strcpy(c,pop(t));
            push(t,"^");
        }
        else if(str[i]=='*' || str[i]=='/')
        {
            char* x;
            x=(char*)malloc(5*sizeof(char));
            x[0]=str[i];
            x[1]='\0';
            if(isEmpty(t))
            {
                push(t,x);
                continue;
            }
            if(!strcmp(peek(t,1),"*") || !strcmp(peek(t,1),"/") || !strcmp(peek(t,1),"^"))
            {
                strcpy(c,pop(t));
                pstr[l++]=c[0];
            }
            else if(!strcmp(peek(t,1),"("))
                strcpy(c,pop(t));
            push(t,x);
        }
        else if(str[i]=='+' || str[i]=='-')
        {
            char* x;
            x=(char*)malloc(5*sizeof(char));
            x[0]=str[i];
            x[1]='\0';
            if(isEmpty(t))
            {
                push(t,x);
                continue;
            }
            if(!strcmp(peek(t,1),"("))
                strcpy(c,pop(t));
            else
            {
                strcpy(c,pop(t));
                pstr[l++]=c[0];
            }
            push(t,x);
        }
        else
            pstr[l++]=str[i];
    }
    while(!isEmpty(t))
    {
        strcpy(c,pop(t));
        if(c[0]!='(')
            pstr[l++]=c[0];
    }
    pstr[l]='\0';
    return pstr;
}
char* prefix(char* str)
{
    char* pstr=postfix(str);
    char** x;
    x=(char**)malloc(strlen(str)*sizeof(char*));
    for(int i=0;i<strlen(pstr);i++)
        x[i]=(char*)malloc(2*sizeof(char));
    for(int i=0;i<strlen(pstr);i++)
    {
        char* c;
        c=(char*)malloc(2*sizeof(char));
        c[0]=pstr[i];
        c[1]='\0';
        strcpy(x[i],c);
    }
    // TO BE COMPLETED
    for(int i=0;i<strlen(pstr)/2;i++)
    {
        char temp=pstr[i];
        pstr[i]=pstr[strlen(pstr)-i-1];
        pstr[strlen(pstr)-i-1]=temp;
    }
    return pstr;
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
    char* r=solve(s,str,l);
    if(strcmp(r,"\0"))
        printf("%s\n",r);
    char* pre=postfix(r);
    printf("%s\n",pre);
    return 0;
}