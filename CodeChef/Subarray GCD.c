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


int GCD(int m, int n) // the two numbers
{
    int r;
    while(1)
    {
        r = m % n;
        if(r == 0)
            break;
        m = n;
        n = r;
    }


    return n;
}

int num_gcd(int k[],int n)
{
        int tem, i;
        tem = GCD(k[0],k[1]);
        for(i=2;i<n;i++)
                tem = GCD(tem,k[i]);

        return tem;
}

int main()
{
        int n[100000],t,N,i ;
        scanf("%d", &t);
        while(t--)
        {
                fastRead(&N);
                for(i=0;i<N;i++)
                        fastRead(&n[i]);
                if(num_gcd(n,N)==1)
                        printf("%d\n", N);
                else
                        printf("-1\n");
        }
        return 0;
}
