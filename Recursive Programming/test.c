#include<stdio.h>
// Corner cases like 100, 12, 124 etc to be covered
// Also cover case of size<3
int count(long int n)
{
    int c=0;
    while(n!=0)
    {
        n=n/10;
        c++;
    }
    return c;
}
void alpha(long int n, int size, int track)
{
    char ones[9][10]={"One ","Two ","Three ","Four ","Five ","Six ","Seven ","Eight ","Nine "};
    char tens[9][10]={"Ten ","Twenty ","Thirty ","Fourty ","Fifty ","Sixty ","Seventy ","Eighty ","Ninety "};
    char tens2[9][10]={"Eleven ","Twelve ","Thirteen ","Fourteen ","Fifteen ","Sixteen ","Seventeen ","Eighteen ","Nineteen "};
    char powers[4][10]={"Hundred ", "Thousand ","Lakh ","Crore "};
    int x=0,l=0,r;
    for(int i=0;i<size;i++)
    {
        r=n%10;
        if(size%2==0 && i==n-1)
        {
            l++;
            printf("%s ",powers[l-1]);
            printf("%s ",ones[r-1]);
            break;
        }
        if(i==0)
            printf("%s ",ones[r-1]);
        if(i==1)
            printf("%s ",tens[r-1]);
        if(i==2)
        {
            l++;
            printf("%s ",powers[l-1]);
            printf("%s ",ones[r-1]);
        }
        if(i>2)
        {
            if(x==0)
            {
                x++;
                l++;
                int q=n;
                q=q/10;
                int r2=q%10;
                if(r2==1)
                {
                    n=n/10;
                    x=0;
                    i++;
                }
                printf("%s ",powers[l-1]);
                if(r2==1 && r!=0)
                    printf("%s ",tens2[r-1]);
                else if(r2==1)
                    printf("%s ",tens[0]);
                else
                    printf("%s ",ones[r-1]);
            }
            else
            {
                x=0;
                printf("%s ",tens[r-1]);
            }
        }
        n=n/10;
    }
}
int main()
{
    int n;
    printf("Enter number: ");
    scanf("%ld",&n);
    alpha(n,count(n),0);
    return 0;
}