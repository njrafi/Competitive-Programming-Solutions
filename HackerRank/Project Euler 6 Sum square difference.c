#include <stdio.h>

int main()
{
        long long int t,n;
        scanf("%lld", &t);
        while(t--)
        {
                scanf("%lld", &n);
                printf("%lld\n", (n*(n+1)/2) * (n*(n+1)/2) -  (n * (n+1) * (2*n +1 )) /6);
        }
        return 0;
}
