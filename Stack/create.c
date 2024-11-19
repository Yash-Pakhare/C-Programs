#include<stdio.h>
#include<stdlib.h>
struct stack
{
    int size;
    int top;
    int* elements;
};
void create(struct stack* s)
{
    printf("Enter the size: ");
    scanf("%d",&s->size);
    s->top=-1;
    s->elements=(int*)malloc(s->size*sizeof(int));
}
int main()
{
    struct stack* s;
    s=(struct stack*)malloc(sizeof(struct stack));
    create(s);
    return 0;
}