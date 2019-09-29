#include <stdio.h>
#ifndef ONLINE_JUDGE
    #define gc getchar
#else
    #define gc getchar_unlocked
#endif


inline void fastRead(int *a)
{
        register char c=0;
        while (c<33)
                c=gc();
        *a=0;
        while (c>33)
        {
                *a= *a*10+c-'0';
                c=gc();
        }
}

int main()

{
        long long int t,n,k,tem1,a[100002],i;
        long long int tem2,max;
        scanf("%d", &t);
        while(t--)
        {
                scanf("%d %d", &n, &k);
                max = 0;
                for(i=0;i<n;i++)
                        fastRead(&a[i]);
                for(i=0;i<n;i++)
                {
                        fastRead(&tem1);
                        if(a[i]>k)
                                continue;

                        tem2 = tem1 * (k/a[i]) ;

                        if(tem2>max)
                                max = tem2;

                }

                printf("%lld\n", max);
        }
        return 0;
}
