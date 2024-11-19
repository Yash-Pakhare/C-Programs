#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct stack
{
    char data;
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
        printf("%c ",s->data);
        s=s->next;
    }
    if(!isEmpty(top))
        // printf("Stack underflow\n");
    // else
        printf("\n");
}
void push(struct stack** top, char n)
{
    struct stack* s;
    s=(struct stack*)malloc(sizeof(struct stack));
    s->data=n;
    s->next=(*top);
    (*top)=s;
}
char pop(struct stack** top)
{
    if(!isEmpty(top))
    {
        char x=(*top)->data;
        struct stack* s;
        s=(*top);
        (*top)=(*top)->next;
        free(s);
        return x;
    }
    // printf("Stack underflow\n");
    return '\0';
}
char peek1(struct stack** top)
{
    if(!isEmpty(top))
        return (*top)->data;
    return '\0';
}
char peek2(struct stack** top)
{
    if(!isEmpty(top))
        return (*top)->next->data;
    return '\0';
}
int main()
{
    struct stack** s=create(s);
    char* exp;
    exp=(char*)malloc(20001*sizeof(char));
    printf("Expression: ");
    scanf("%s",exp);
    int size=strlen(exp);
    for(int i=0;i<size;i++)
    {
        if(exp[i]=='|' || exp[i]=='&' || exp[i]=='!')
        {
            push(s,exp[i]);
        }
        if(exp[i]=='f' || exp[i]=='t')
        {
            if(isEmpty(s))
            {
                push(s,exp[i]);
                break;
            }
            char x=peek1(s);
            char y=peek2(s);
            if(x=='|')
            {
                if(exp[i]=='t')
                {
                    pop(s);
                    i--;
                    continue;
                }
                push(s,exp[i]);
            }
            else if(x=='&')
            {
                if(exp[i]=='f')
                {
                    pop(s);
                    i--;
                    continue;
                }
                push(s,exp[i]);
            }
            else if(x=='!')
            {
                pop(s);
                if(exp[i]=='f')
                    exp[i]='t';
                else
                    exp[i]='f';
                i--;
                continue;
            }
            else
            {
                if(exp[i]=='f')
                {
                    if(y=='&')
                    {
                        pop(s);
                        pop(s);
                        i--;
                        continue;
                    }
                }
                else
                {
                    if(y=='|')
                    {
                        pop(s);
                        pop(s);
                        i--;
                        continue;
                    }
                }
            }
        }
    }
    printf("%c",pop(s));
    return 0;
}