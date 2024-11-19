#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
    char data;
    struct node* next;
    struct node* prev;
}*first=NULL,*end=NULL;
void create(char a[])
{
    struct node* last;
    struct node* t;
    first=(struct node*)malloc(sizeof(struct node));
    last=(struct node*)malloc(sizeof(struct node));
    first->data=a[0];
    first->next=NULL;
    first->prev=NULL;
    last=first;
    for(int i=1;i<strlen(a);i++)
    {
        t=(struct node*)malloc(sizeof(struct node));
        t->data=a[i];
        t->next=NULL;
        t->prev=last;
        last->next=t;
        last=t;
    }
    end=last;
}
int check_palindrome()
{
    struct node* p=first;
    struct node* q=end;
    while(p->prev!=q)
    {
        if(p->data!=q->data)
            return 0;
        if(p==q)
            break;
        p=p->next;
        q=q->prev;
    }
    return 1;
}
void display(struct node* n)
{
    while(n!=NULL)
    {
        printf("%c ",n->data);
        n=n->next;
    }
    printf("\n");
}
int main()
{
    char str[20];
    printf("Enter a string: ");
    scanf("%s",str);
    create(str);
    if(check_palindrome())
        printf("It is a palindrome\n");
    else
        printf("It is not a palindrome\n");
    return 0;
}