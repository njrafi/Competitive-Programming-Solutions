#include <stdio.h>
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

inline void fastWrite(int a)
{
        char snum[20];
        int i=0;
        do
        {
                snum[i++] = a%10+48;
                a=a/10;
        }
        while(a!=0);
                i=i-1;
        while(i>=0)
        pc(snum[i--]);
        pc('\n');
}


int main()
{
        int a[105],d[105],max,i,t,N,j;
        fastRead(&t);
        while(t--)
        {
                fastRead(&N);
                max = 0;
                int n[1005] = {0};
                for(i=1;i<=N;i++)
                        fastRead(&a[i]);
                for(i=1;i<=N;i++)
                        fastRead(&d[i]);
                for(i=1;i<=N;i++)
                        for(j=a[i];j<d[i];j++)
                                n[j]++;

                for(i=1;i<1000;i++)
                        if(n[i]>max)
                                max = n[i];
                fastWrite(max);

        }
        return 0;
}
