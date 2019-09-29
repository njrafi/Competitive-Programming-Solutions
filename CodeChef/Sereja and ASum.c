#include <stdio.h>
#define m 1000000007
#ifndef ONLINE_JUDGE
    #define gc getchar
    #define pc putchar
#else
    #define gc getchar_unlocked
    #define pc putchar_unlocked
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
        int max,count,i,t,n,a[100005],ans;
        fastRead(&t);
        while(t--)
        {
                fastRead(&n);
                max = 0;
                count = 0;
                ans = 1;
                for(i=1;i<=n;i++)
                        fastRead(&a[i]);
                for(i=1;i<=n;i++)
                        if(a[i]>max)
                                max = a[i];
                for(i=1;i<=n;i++)
                        if(a[i]==max)
                                count++;
                while(count--)
                       ans = (ans*2) % m;


               printf("%d\n", ans-1);
        }
}
