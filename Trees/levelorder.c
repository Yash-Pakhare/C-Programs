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
        level(t,i);
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
    levelorder(t);
    return 0;
}