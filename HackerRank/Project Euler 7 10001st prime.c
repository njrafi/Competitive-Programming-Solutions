#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define high   100000

int main()

{
        int limit=1000000,t;
        int *index,i,j,count=0,*prime;
        index = malloc(limit*sizeof(int));
        prime = malloc(high*sizeof(int));
       for(i=0;i<limit;i++)
                index[i] = 1;

         for(i=2;i<=sqrt(limit);i++)
                if(index[i])
                        for(j=2*i; j<limit; j+=i)
                                index[j] = 0;

         for(i=2,j=1;i<limit;i++)
                if(index[i])
                {
                        prime[j] = i;
                        j++;
                }
        scanf("%d", &t);
        while(t--)
        {
                scanf("%d", &j);
                printf("%d\n", prime[j]);
        }


}


