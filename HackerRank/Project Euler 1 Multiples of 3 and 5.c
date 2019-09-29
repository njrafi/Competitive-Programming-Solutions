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

        long long int i,a,b,c,sum;
        int N,t;
        fastRead(&t);
        while(t--)
        {
                sum=0;
                fastRead(&N);
                N--;
                a = N/3;
                b = N/5;
                c = N/15;

                sum = (3*a + 3*a*a + 5*b + 5*b*b - 15*c - 15*c*c)/2;


            printf("%lld\n", sum);
    }
    return 0;
}

