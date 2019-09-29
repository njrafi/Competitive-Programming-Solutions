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

int main()
{
        int m[505][505],r,c,L,i,j,tem1=1,tem2=1;
        long long int sum1=0,sum2=0;
        fastRead(&r);
        fastRead(&c);
        for(i=1;i<=r;i++)
                for(j=1;j<=c;j++)
                        fastRead(&m[i][j]);
        fastRead(&L);
        while(L--)
        {
                fastRead(&i);
                fastRead(&j);
                if(tem1)
                        if(i<=r && j<=c )
                                sum1 += m[i][j];
                        else
                        {
                                tem1 = 0;
                                sum1 = -1;
                        }

                if(tem2)
                        if(j<=r && i<=c )
                                sum2 += m[j][i];
                        else
                        {
                                tem2 = 0;
                                sum2 = -1;
                        }

        }
        if(sum1>=sum2)
                printf("%lld", sum1);
        else
                printf("%lld", sum2);
        return 0;
}
