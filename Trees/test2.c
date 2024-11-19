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
void inorder(struct node* t)
{
    if(t->data!=-1)
    {
        inorder(t->left);
        printf("%d ",t->data);
        inorder(t->right);
    }
}
int max(int a, int b)
{
    if(a>b)
        return a;
    return b;
}
int height(struct node* t)
{
    if(t->data==-1)
        return 0;
    int left_height=height(t->left);
    int right_height=height(t->right);
    return max(left_height,right_height)+1;
}
void level(struct node* t, int i)
{
    if(t->data==-1)
        return;
    if(i==0)
        printf("%d ",t->data);
    else
    {
        level(t->left,i-1);
        level(t->right,i-1);
    }
}
void levelorder(struct node* t)
{
    int h=height(t);
    for(int i=0;i<h;i++)
    {
        level(t,i);
        printf("\n");
    }
}
struct node* findPivot(struct node* t, int n)
{
    if(t->data==n)
        return t;
    else if(t->data==-1)
        return NULL;
    if(t->data!=-1)
    {
        struct node* x=findPivot(t->left,n);
        struct node* y=findPivot(t->right,n);
        if(x==NULL)
            return y;
        return x;
    }
}
int main()
{
    struct node* t=create();
    t->data=1;
    t->left=create();
    t->right=create();
    t->left->data=2;
    t->left->left=create();
    t->left->right=create();
    t->right->data=3;
    t->right->left=create();
    t->right->right=create();
    struct node* x=findPivot(t,1);
    printf("%d",x->data);
    return 0;
}