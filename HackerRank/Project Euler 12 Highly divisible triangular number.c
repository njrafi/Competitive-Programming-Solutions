#include <stdio.h>
#include <math.h>
#include <stdlib.h>


void SoE(int limit,int prime[])
{
        int *index,i,j,count=0;
        index = malloc(limit*sizeof(int));
        int k = sqrt(limit);
        for(i=0;i<limit;i++)
                index[i] = 1;

         for(i=2;i<=k;i++)
                if(index[i])
                        for(j=2*i; j<limit; j+=i)
                                index[j] = 0;

         for(i=2,k=0;i<limit;i++)
                if(index[i])
         {
                prime[k] = i;
                 k++;
         }

}

int div2(long long int n,int p[])
{
        int count=1,rem=n,pow,i;
        for(i=0;p[i]<=sqrt(n);i++)
        {
               pow = 1;
               while(rem%p[i]==0)
               {
                       rem /= p[i];
                       pow++;
               }
               count *= pow ;

               if(rem==1)
                        return count;
        }
        if(rem>1)
                count *= 2;
       return count;

}

int div1(long long int n)
{
        int i,count=0;
        for(i=2;i<=sqrt(n);i++)
                if(n%i==0)
                        count +=2;

        if(sqrt(n)*sqrt(n) == n)
                count--;

        return count+2;
}

int main()
{


        int i,t,n,prime[200],cnt,dn1,dn2;
        SoE(1000,prime);
        long long int tri;
        scanf("%d", &t);
        while(t--)
        {
                cnt = 0;
                dn1 = 2;
                dn2 = 2;
                tri = 0;
                scanf("%d", &n);
                if(n<100)
                {
                        for(i=1;div1(tri)<=n;i++)
                                tri += i;
                        printf("%lld\n", tri);
                        continue;
                }

                for(i=2;cnt<n;i++)
                {
                        if(i%2==0)
                        {
                                dn1 = div2(i+1,prime);
                                cnt = dn1*dn2;
                        }
                        else
                        {
                                dn2 = div2( (i+1)/2,prime);
                                cnt = dn1*dn2;
                        }
                }

                tri =  (i * (i-1) ) / 2;


                printf("%lld\n", tri);
        }
        return 0;

}
