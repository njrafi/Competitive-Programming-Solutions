#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void SoE(int limit,long long int sum[])
{
        int *index,i,j;
        limit++;
        long long int sum_t=0;
        index = malloc(limit*sizeof(int));

       for(i=0;i<limit;i++)
                index[i] = 1;

         for(i=2;i<=sqrt(limit);i++)
                if(index[i])
                        for(j=2*i; j<limit; j+=i)
                                index[j] = 0;

         for(i=2;i<limit;i++)
                if(index[i])
                {
                        sum_t += i;
                        sum[i] = sum_t;
                }
}


int main()

{
        int N,t,i;
        long long int a,sum[999999]={0};
        SoE(999999,sum);
        scanf("%d", &t);
        while(t--)
        {
                scanf("%d", &N);
                for(i=N;i>=2;i--)
                        if(sum[i])
                        {
                                printf("%lld\n", sum[i]);
                                break;
                        }
                if(i==1)
                        printf("0\n");
        }
        return 0;
}
