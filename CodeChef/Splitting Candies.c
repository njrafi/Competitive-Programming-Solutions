#include <stdio.h>

int main()
{
        int T;
        long long int N,K;
        scanf("%d", &T);

        while(T--)
        {
                scanf("%lld %lld", &N, &K);

                if(!N)
                        printf("0 0\n");
                else if(!K)
                        printf("0 %lld\n", N);
                else if(K>N)
                        printf("0 %lld\n", N);
                else
                        printf("%lld %lld\n", N/K, N%K);
        }
}
