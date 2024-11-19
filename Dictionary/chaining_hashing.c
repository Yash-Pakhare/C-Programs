#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};
int hash(int key)
{
    return key%10;
}
void insert(struct node* H[], int key)
{
    int index=hash(key);
    struct node* t;
    t=(struct node*)malloc(sizeof(struct node));
    t->data=key;
    struct node* p;
    struct node* q;
    p=H[index];
    q=NULL;
    if(p==NULL)
    {
        t->next=NULL;
        H[index]=t;
    }
    else
    {
        while(p!=NULL)
        {
            if(p->data>key)
                break;
            q=p;
            p=p->next;
        }
        t->next=p;
        if(q!=NULL)
            q->next=t;
        else
            H[index]=t;
    }
}
struct node* search(struct node* H[], int key)
{
    struct node* h=H[hash(key)];
    while(h!=NULL)
    {
        if(h->data>key)
            break;
        if(h->data==key)
            return h;
        h=h->next;
    }
    printf("Not found\n");
    return NULL;
}
void delete(struct node* H[], int key)
{
    struct node* h=H[hash(key)];
    struct node* q=NULL;
    while(h!=NULL)
    {
        if(h->data>key)
        {
            printf("Not found\n");
            break;
        }
        if(h->data==key)
        {
            if(q!=NULL)
            {
                q->next=h->next;
                free(h);
            }
            else
            {
                q=h->next;
                free(h);
                H[hash(key)]=q;
            }
            break;
        }
        q=h;
        h=h->next;
    }
    if(h==NULL)
        printf("Not found\n");
}
int main()
{
    struct node* H[10];
    struct node* temp;
    for(int i=0;i<10;i++)
        H[i]=NULL;
    insert(H,1);
    insert(H,22);
    insert(H,2);
    temp=search(H,2);
    printf("%d\n",temp->data);
    printf("%d\n",temp->next->data);
    delete(H,2);
    temp=search(H,2);
    temp=search(H,22);
    printf("%d\n",temp->data);
    temp=search(H,1);
    printf("%d\n",temp->data);
    return 0;
}