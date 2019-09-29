#include <stdio.h>
#include <stdlib.h>
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

int amb(int inp[],int n)
{
        int i,*rev;
        rev = malloc((n+1)*sizeof(int));
        for(i=1;i<=n;i++)
                rev[inp[i]] = i;
        for(i=1;i<=n;i++)
                if(inp[i]!=rev[i])
                        return 0;
        return 1;

}

int main()
{
        int n,*inp,i;
        while(1)
        {
                fastRead(&n);
                if(!n)
                        return 0;
                inp = malloc((n+1)*sizeof(int));
                for(i=1;i<=n;i++)
                        fastRead(&inp[i]);
                if(amb(inp,n))
                        printf("ambiguous\n");
                else
                        printf("not ambiguous\n");
        }
}
