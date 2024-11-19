#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
    char data[100];
    struct node* next;
};
int hash(int key)
{
    return key%10;
}
void insert(struct node* H[], char k[])
{
    int key=0;
    for(int i=0;i<strlen(k);i++)
        key+=(int)k[i];
    int index=hash(key);
    struct node* t;
    t=(struct node*)malloc(sizeof(struct node));
    strcpy(t->data,k);
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
            if((int)p->data[0]>k[0])
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
struct node* search(struct node* H[], char k[])
{
    int key=0;
    for(int i=0;i<strlen(k);i++)
        key+=(int)k[i];
    struct node* h=H[hash(key)];
    while(h!=NULL)
    {
        if((int)h->data[0]>k[0])
            break;
        if(strcmp(h->data,k)==0)
            return h;
        h=h->next;
    }
    printf("Not found\n");
    return NULL;
}
void delete(struct node* H[], char k[])
{
    int key=0;
    for(int i=0;i<strlen(k);i++)
        key+=(int)k[i];
    struct node* h=H[hash(key)];
    struct node* q=NULL;
    while(h!=NULL)
    {
        if((int)h->data[0]>k[0])
        {
            printf("Not found\n");
            break;
        }
        if(strcmp(h->data,k)==0)
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
    char s1[100]="abc";
    char s2[100]="bca";
    char s3[100]="cab";
    insert(H,s2);
    insert(H,s1);
    insert(H,s3);
    temp=search(H,s1);
    printf("%s\n",temp->data);
    printf("%s\n",temp->next->data);
    printf("%s\n",temp->next->next->data);
    delete(H,s2);
    temp=search(H,s1);
    printf("%s\n",temp->data);
    printf("%s\n",temp->next->data);
    temp=search(H,s3);
    printf("%s\n",temp->data);
    temp=search(H,s2);
    return 0;
}