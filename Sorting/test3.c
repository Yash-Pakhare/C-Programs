#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
void merge(long int* a, long int p, long int r, long int q)
{
    long int a1[r-p+1],a2[q-r+1],l=0;
    for(long int i=p;i<r;i++)
        a1[l++]=a[i];
    a1[l]=__INT_MAX__;
    l=0;
    for(long int i=r;i<q;i++)
        a2[l++]=a[i];
    a2[l]=__INT_MAX__;
    l=0;
    long int b[q-p],i=0,j=0;
    for(int k=0;k<q-p;k++)
    {
        if(a1[i]<=a2[j])
        {
            b[k]=a1[i];
            i++;
        }
        else
        {
            b[k]=a2[j];
            j++;
        }
    }
    for(long int k=p;k<q;k++)
        a[k]=b[l++];
}
void merge_sort(long int* a, long int p, long int q)
{
    long int r=(p+q)/2;
    if(q-p>1)
    {
        merge_sort(a,p,r);
        merge_sort(a,r,q);
        merge(a,p,r,q);
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long int n,m,q;
        scanf("%ld %ld %ld",&n,&m,&q);
        long int* b;
        b=(long int*)malloc(m*sizeof(long int));
        for(long int i=0;i<m;i++)       
            scanf("%ld",&b[i]);
        long int a[q];
        for(long int i=0;i<q;i++)
            scanf("%ld",&a[i]);
        merge_sort(b,0,m);
        // long int min=__INT_MAX__,max=-__INT_MAX__;
        // for(int i=0;i<m;i++)
        // {
        //     if(min>b[i])
        //         min=b[i];
        //     if(max<b[i])
        //         max=b[i];
        // }
        long int x,y,moves=0;
        long int min1=__INT_MAX__,min2=__INT_MAX__;
        for(long int i=0;i<q;i++)       
        {
            if(a[i]<b[0])
                moves=b[0]-1;
            else if(a[i]>b[m-1])
                moves=n-b[m-1];
            // if(a[i]<min)
            //     moves=min-1;
            // else if(a[i]>max)
            //     moves=n-max;
            else
            {
                for(long int j=0;j<m-1;j++)
                {
                    if(a[i]>b[j] && a[i]<b[j+1])
                    {
                        moves=((b[j]+b[j+1])/2)-b[j];
                        break;
                    }
                }
                // for(long int j=0;j<m;j++)
                // {
                //     if(b[j]<a[i])
                //     {
                //         if(min1>a[i]-b[j])
                //         {
                //             min1=a[i]-b[j];
                //             x=b[j];
                //         }
                //     }
                //     else
                //     {
                //         if(min2>b[j]-a[i])
                //         {
                //             min2=b[j]-a[i];
                //             y=b[j];
                //         }
                //     }
                // }
                // moves=((x+y)/2)-x;
            }
            printf("%d\n",moves);
        }
    }
    return 0;
}