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
        int T,N,M,i,count,li[101],lf[101],C,L;
        fastRead(&T);
        while(T--)
        {
                count = 0;
                for(i=1;i<101;i++)
                {
                        li[i] = 0;
                        lf[i] = 0;
                }

                fastRead(&N);
                fastRead(&M);

                while(N--)
                {
                        fastRead(&C);
                        fastRead(&L);
                        li[L] += C;
                }

                while(M--)
                {
                        fastRead(&C);
                        fastRead(&L);
                        lf[L] += C;
                }

                for(i=1;i<101;i++)
                        if(lf[i]>li[i])
                                count += lf[i]-li[i];
                        fastWrite(count);

        }
        return 0;
}


