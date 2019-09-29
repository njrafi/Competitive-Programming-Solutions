#include <stdio.h>
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
        pc(' ');
}

int main()
{
        int t,comp[3][10000],n,m,i,j;
        fastRead(&t);
        while(t--)
        {
                fastRead(&n);
                fastRead(&m);
                for(i=0;i<m;i++)
                        comp[2][i] = 1;
                for(i=0;i<m;i++)
                {
                        fastRead(&comp[0][i]);
                        fastRead(&comp[1][i]);
                }
                i--;

                while(i>0)
                {
                        for(j=i-1;j>=0;j--)
                                if(comp[0][i]==comp[0][j] || comp[0][i]==comp[1][j] || comp[1][i]==comp[0][j] || comp[1][i]==comp[1][j] )
                                        comp[2][j] = 0;

                        i--;
                        if(!i)
                                break;

                        while(!comp[2][i])
                                i--;
                }

                for(i=0;i<m;i++)
                        if(comp[2][i])
                                fastWrite(i);

                printf("\n");
        }
        return 0;
}
