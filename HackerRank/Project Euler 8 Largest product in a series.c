#include <stdio.h>

long long int M(int i,int n,int b[])
{
        long long int ans=1;
        while(n--)
        {
                ans *= b[i];
                i++;
        }
        return ans;

}

int main()
{
        char a[1005];
        int i,b[1005],t,N,K;
        long long int max ;
        scanf("%d", &t);
        while(t--)
        {
                scanf("%d %d\n", &N, &K);
                gets(a);
                max = 0;

                for(i=0;a[i];i++)
                        b[i] = a[i] - '0';

                for(i=0;i<N-K;i++)
                        if(M(i,K,b)>max)
                                max = M(i,K,b);

                printf("%lld\n", max);
        }
        return 0;
}
