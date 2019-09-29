#include <stdio.h>
#include <stdlib.h>
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
        int n,i,a,count=0,max=0;
        n = read_int();
        while(n--)
        {
                a = read_int();
                if(!a)
                        count = 0;
                else
                        count++;
                if(count>max)
                        max = count;
        }
        printf("%d", max);
        return 0;
}
