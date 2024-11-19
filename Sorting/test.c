#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        long long a[n];
        for(int i=0;i<n;i++)
            scanf("%lld",&a[i]);
        long long ans=a[n-1]-a[n-2];
        for(int i=0;i<n-2;i++)
            ans+=a[i];
        printf("%lld\n",ans);
    }
    return 0;
}