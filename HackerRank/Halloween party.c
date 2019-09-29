#include <stdio.h>

int main()
{
        int t;
        long long int i,n;
        scanf("%d", &t);
        while(t--)
        {
                scanf("%lld", &n);
                i = n/2;
                if(n%2)
                        printf("%lld\n", i*(i+1) );
                else
                        printf("%lld\n", i*i);
        }
        return 0;
}
