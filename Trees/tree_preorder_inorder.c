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
void build(struct node* t, int in[], int n, int x)
{
    int pivot;
    for(int i=0;i<n;i++)
    {
        if(t->data==in[i])
        {
            pivot=i;
            break;
        }
    }
    if(x<pivot)
    {
        if(t->left->data!=-1)
            build(t->left,in,n,x);
        else
        {
            t->left->data=in[x];
            t->left->left=create();
            t->left->right=create();
        }
    }
    else if(x>pivot)
    {
        if(t->right->data!=-1)
            build(t->right,in,n,x);
        else
        {
            t->right->data=in[x];
            t->right->left=create();
            t->right->right=create();
        }
    }
}
struct node* tree(int pre[], int in[], int n)
{
    int x;
    struct node* t=create();
    t->data=pre[0];
    t->left=create();
    t->right=create();
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(in[j]==pre[i])
            {
                x=j;
                break;
            }
        }
        build(t,in,n,x);
    }
    return t;
}
int main()
{
    int n=7;
    // printf("Enter no. of nodes: ");
    // scanf("%d",&n);
    int pre[7]={3,2,1,8,4,7,5},in[7]={1,2,8,3,4,7,5};
    // printf("Enter preorder: ");
    // for(int i=0;i<n;i++)
    //     scanf("%d",&pre[i]);
    // printf("Enter inorder: ");
    // for(int i=0;i<n;i++)
    //     scanf("%d",&in[i]);
    struct node* t=tree(pre,in,n);
    levelorder(t);
    return 0;
}