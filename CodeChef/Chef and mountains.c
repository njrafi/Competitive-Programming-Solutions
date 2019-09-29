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
        int N,i,a[100005],q,l,r,tem;
        fastRead(&N);
        for(i=0;i<N;i++)
                fastRead(&a[i]);
        fastRead(&q);
        while(q--)
        {
                fastRead(&l);
                fastRead(&r);
                tem = 0;
                for(i=l;i<r-1;i++)
                        if(a[i]>a[l-1])
                        {
                                printf("NO\n");
                                tem++;
                                break;
                        }
                if(!tem)
                        printf("YES\n");
        }
        return 0;















}
