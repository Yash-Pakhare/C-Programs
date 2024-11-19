#include<stdio.h>
#include<stdlib.h>
struct hash
{
    int data;
    struct hash* next;
};
struct hash** create()
{
    struct hash** h;
    h=(struct hash**)malloc(10*sizeof(struct hash*));
    for(int i=0;i<10;i++)
        h[i]=(struct hash*)malloc(sizeof(struct hash));
    for(int i=0;i<10;i++)
    {
        h[i]->data=-1;
        h[i]->next=NULL;
    }
    return h;
}
void display(struct hash** h)
{
    int flag=0;
    for(int i=0;i<10;i++)
    {
        struct hash* p;
        p=h[i];
        if(p->data==-1)
            continue;
        flag=1;
        while(p!=NULL)
        {
            printf("%d ",p->data);
            p=p->next;
        }
        printf("\n");
    }
    if(flag==0)
        printf("Empty\n");
}
void insert(struct hash** h, int key)
{
    struct hash* p;
    p=h[key%10];
    if(h[key%10]->data==-1)
        p->data=key;
    else
    {
        struct hash* t;
        t=(struct hash*)malloc(sizeof(struct hash));
        t->data=key;
        if(p->data>key)
        {
            t->next=p;
            h[key%10]=t;        
        }
        else
        {
            struct hash* q;
            while(p!=NULL)
            {
                if(p->data>key)
                    break;
                q=p;
                p=p->next;
            }
            q->next=t;
            t->next=p;
        }
    }
}
void delete(struct hash** h, int key)
{
    struct hash* p;
    p=h[key%10];
    if(p->data==key && p->next==NULL)
        p->data=-1;
    else
    {
        if(p->data==key)
        {
            h[key%10]=p->next;
            free(p);
        }
        else
        {
            struct hash* q;
            while(p!=NULL)
            {
                if(p->data==key)
                    break;
                q=p;
                p=p->next;
            }
            if(p!=NULL)
            {
                q->next=p->next;
                free(p);
            }
            else
                printf("Element to be deleted not found\n");
        }
    }
}
int search(struct hash** h, int key)
{
    if(h[key%10]->data!=-1)
    {
        struct hash* p;
        p=h[key%10];
        while(p!=NULL)
        {
            if(p->data==key)
                return 1;
            p=p->next;
        }
    }
    return 0;
}
int main()
{
    struct hash** h=create();
    int choice;
    while(1)
    {
        printf("Enter choice: ");
        scanf("%d",&choice);
        if(choice==1)
        {
            int x;
            printf("Enter element to insert: ");
            scanf("%d",&x);
            insert(h,x);
        }
        if(choice==2)
        {
            int x;
            printf("Enter element to delete: ");
            scanf("%d",&x);
            delete(h,x);
        }
        if(choice==3)
        {
            int x;
            printf("Enter element to search: ");
            scanf("%d",&x);
            if(search(h,x))
                printf("Element found\n");
            else
                printf("Element not found\n");
        }
        if(choice==4)
            display(h);
        if(choice==5)
            break;
    }
}