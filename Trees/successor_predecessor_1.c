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
void inorder(struct node* t, int* a, int l)
{
    if(t->data!=-1)
    {
        inorder(t->left,a,l);
        a[l++]=t->data;
        inorder(t->right,a,l);
    }
}
int successor(int* a, int n, int k)
{
    for(int i=0;i<n-1;i++)
        if(a[i]==k)
            return a[i+1];
    return -1;
}
int predecessor(int* a, int n, int k)
{
    for(int i=1;i<n;i++)
        if(a[i]==k)
            return a[i-1];
    return -1;
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
    int* b;
    b=(int*)malloc(n*sizeof(int));
    inorder(t,b,0);
    printf("Inorder: ");
    for(int i=0;i<n;i++)
        printf("%d ",b[i]);
    printf("\n");
    int k;
    printf("Enter a key: ");
    scanf("%d",&k);
    int s=successor(b,n,k);
    int p=predecessor(b,n,k);
    if(s>=0)
        printf("Successor of %d is: %d\n",k,s);
    else
        printf("Successor does not exits\n");
    if(p>=0)
        printf("Predecessor of %d is: %d\n",k,p);
    else
        printf("Predecessor does not exits\n");
}