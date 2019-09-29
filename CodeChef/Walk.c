#include <stdio.h>
#ifndef ONLINE_JUDGE
    #define gc getchar
#else
    #define gc getchar_unlocked
#endif


int read_int()
{
        char c = gc();
        while(c<'0' || c>'9')
                c = gc();
        int ret = 0;
        while(c>='0' && c<='9')
        {
                ret = 10 * ret + c - 48;
                c = gc();
        }
        return ret;
}

int main()
{
        int t,N,i,tem,max;
        t = read_int();
        while(t--)
        {
                N = read_int();
                max = 0;
                for(i=0;i<N;i++)
                {
                        tem = read_int();
                        tem += i;
                        if(tem>max)
                                max = tem;
                }
                printf("%d\n", max);
        }
        return 0;
}
