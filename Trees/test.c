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
struct node* maximum(struct node* t)
{
    while(t->right->data!=-1)
        t=t->right;
    return t;
}
struct node* predecessor(struct node* x, int n)
{
    struct node* p=search(x,n);
    if(p->left->data!=-1)
        return maximum(p->left);
    struct node* r=x;
    int flag=0;
    while(x->data!=-1 && x->data!=p->data)
    {
        if(p->data>x->data)
        {
            flag=1;
            r=x;
            x=x->right;
        }
        else
            x=x->left;
    }
    if(flag==1)
        return r;
    return NULL;
}
void inorder(struct node* t)
{
    if(t!=NULL)
    {
        inorder(t->left);
        if(t->data!=-1)
            printf("%d ",t->data);
        inorder(t->right);
    }
}
// struct node* delete(struct node* root, int k)
// {
//     // Base case
//     if (root == NULL)
//         return root;
 
//     // Recursive calls for ancestors of
//     // node to be deleted
//     if (root->data > k) {
//         root->left = delete(root->left, k);
//         return root;
//     }
//     else if (root->data < k) {
//         root->right = delete(root->right, k);
//         return root;
//     }
 
//     // We reach here when root is the node
//     // to be deleted.
 
//     // If one of the children is empty
//     if (root->left == NULL) {
//         struct node* temp = root->right;
//         free(root);
//         return temp;
//     }
//     else if (root->right == NULL) {
//         struct node* temp = root->left;
//         free(root);
//         return temp;
//     }
 
//     // If both children exist
//     else {
 
//         struct node* succParent = root;
 
//         // Find successor
//         struct node* succ = root->right;
//         while (succ->left != NULL) {
//             succParent = succ;
//             succ = succ->left;
//         }
 
//         // Delete successor.  Since successor
//         // is always left child of its parent
//         // we can safely make successor's right
//         // right child as left of its parent.
//         // If there is no succ, then assign
//         // succ->right to succParent->right
//         if (succParent != root)
//             succParent->left = succ->right;
//         else
//             succParent->right = succ->right;
 
//         // Copy Successor Data to root
//         root->data = succ->data;
 
//         // Delete Successor and return root
//         free(succ);
//         return root;
//     }
// }
void delete_case1(struct node* p)
{
    p->data=-1;
    free(p->left);
    free(p->right);
    p->left=NULL;
    p->right=NULL;
}
void delete_case2(struct node* t, struct node* p)
{
    struct node* x;
    if(p->left->data==-1)
        x=p->right;
    else
        x=p->left;
    while(t->data!=-1)
    {
        if(t->data>p->data)
        {
            if(t->left->data==p->data)
            {
                t->left=x;
                free(p);
                break;
            }
            t=t->left;
        }
        else
        {
            if(t->right->data==p->data)
            {
                t->right=x;
                free(p);
                break;
            }
            t=t->right;
        }
    }
}
void delete_case3(struct node* t, struct node* p)
{
    struct node* s=successor(t,p->data);
    if(s==NULL)
        s=predecessor(t,p->data);
    p->data=s->data;
    if(s->left->data==-1 && s->right->data==-1)
        delete_case1(s);
    else if(s->left->data==-1 && s->right->data!=-1)
        delete_case2(t,s);
    else if(s->right->data==-1 && s->left->data!=-1)
        delete_case2(t,s);
    else
        delete_case3(t,s);
}
void delete(struct node* t, int n)
{
    struct node* p=search(t,n);
    if(p==NULL)
    {
        printf("Element to be deleted not found\n");
        return;
    }
    if(p->data==t->data)
        delete_case3(t,p);
    else if(p->left->data==-1 && p->right->data==-1)
        delete_case1(p);
    else if(p->left->data==-1 && p->right->data!=-1)
        delete_case2(t,p);
    else if(p->right->data==-1 && p->left->data!=-1)
        delete_case2(t,p);
    else
        delete_case3(t,p);
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
    int choice;
    while(1)
    {
        printf("1. Insert\n2. Delete\n3. Search\n4. Print (Inorder)\n5. Successor\n6. Predeccessor\n7. Exit\n");
        printf("Enter choice: ");
        scanf("%d",&choice);
        if(choice==1)
        {
            int x;
            printf("Enter element to insert: ");
            scanf("%d",&x);
            insert(t,x);
        }
        else if(choice==2)
        {
            int x;
            printf("Enter element to delete: ");
            scanf("%d",&x);
            delete(t,x);
        }
        else if(choice==3)
        {
            int x;
            printf("Enter element to search: ");
            scanf("%d",&x);
            struct node* p=search(t,x);
            if(p!=NULL)
                printf("Found %d\n",p->data);
            else
                printf("Not found\n");
        }
        else if(choice==4)
        {
            printf("Inorder: ");
            inorder(t);
            printf("\n");
        }
        else if(choice==5)
        {
            int x;
            printf("Enter element to find successor: ");
            scanf("%d",&x);
            struct node* p=successor(t,x);
            if(p!=NULL)
                printf("Successor of %d is %d\n",x,p->data);
            else
                printf("Successor does not exist\n");
        }
        else if(choice==6)
        {
            int x;
            printf("Enter element to find predecessor: ");
            scanf("%d",&x);
            struct node* p=predecessor(t,x);
            if(p!=NULL)
                printf("Predecessor of %d is %d\n",x,p->data);
            else
                printf("Predecessor does not exist\n");
        }
        else
            break;
    }
    return 0;
}