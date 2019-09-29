#include <stdio.h>


long int GCD(long long int m,long long int n) // the two numbers
{
    long long int r;
    while(1)
    {
        r = m % n;
        if(r == 0)
            break;
        m = n;
        n = r;
    }
    return n;
}

long long int LCM(long long int n,long long int m)
{
        return (n*m)/ GCD(n,m);
}

int main()

{
        long long int i, m;
        int t,n;
        scanf("%d", &t);
        while(t--)
        {
                scanf("%d", &n);
                if(n==1)
                {
                        printf("1\n");
                        continue;
                }
                m = LCM(1,2);
                for(i=3;i<=n;i++)
                        m = LCM(m,i);

                printf("%lld\n", m);
        }

}

