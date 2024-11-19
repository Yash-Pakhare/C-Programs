#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* left;
    struct node* right;
};
struct node* create()
{
    struct node* t;
    t=(struct node*)malloc(sizeof(struct node));
    t->data=-1;
    t->left=NULL;
    t->right=NULL;
    return t;
}
void insert(struct node* t, int key)
{
    if(t->data==-1)
    {
        t->data=key;
        t->left=create();
        t->right=create();
    }
    else if(t->data==key)
        printf("Key is already present");
    else if(key<t->data)
        insert(t->left,key);
    else if(key>t->data)
        insert(t->right,key);
}
struct node* search(struct node* t, int key)
{
    if(t->data==-1)
        return NULL;
    if(t->data==key)
        return t;
    else if(key<t->data)
        return search(t->left,key);
    else if(key>t->data)
        return search(t->right,key);
    return NULL;
}
void inorder(struct node* t)
{
    if(t->data!=-1)
    {
        inorder(t->left);
        printf("%d ",t->data);
        inorder(t->right);
    }
}
struct node* minimum(struct node* t)
{
    while(t->left->data!=-1)
        t=t->left;
    return t;
}
struct node* successor(struct node* x, int n)
{
    struct node* p=search(x,n);
    if(p->right->data!=-1)
        return minimum(p->right);
    struct node* r=x;
    int flag=0;
    while(x->data!=-1 && x->data!=p->data)
    {
        if(p->data<x->data)
        {
            flag=1;
            r=x;
            x=x->left;
        }
        else
            x=x->right;
    }
    if(flag==1)
        return r;
    return NULL;
}
int main()
{
    int n;
    printf("Enter no. of nodes: ");
    scanf("%d",&n);
    int a[n];
    printf("Enter the values of nodes: ");
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    struct node* t=create();
    for(int i=0;i<n;i++)
        insert(t,a[i]);
    printf("Inorder: ");
    inorder(t);
    printf("\n");
    int x;
    printf("Enter a number to find successor: ");
    scanf("%d",&x);
    struct node* s=successor(t,x);
    if(s!=NULL)
        printf("%d\n",s->data);
    return 0;
}