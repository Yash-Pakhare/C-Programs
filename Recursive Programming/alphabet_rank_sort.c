#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void rank_sort(char* s)
{
    int n=strlen(s);
    int r[n];
    for(int i=0;i<n;i++)
        r[i]=0;
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if((int)s[j]<(int)s[i])
                r[i]++;
            else
                r[j]++;
        }
    }
    char u[n+1];
    for(int i=0;i<n;i++)
        u[r[i]]=s[i];
    u[n]='\0';
    strcpy(s,u);
}
int main()
{
    char s[100];
    printf("Enter string: ");
    scanf("%s",s);
    rank_sort(s);
    printf("%s",s);
    return 0;
}