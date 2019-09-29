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

int bubble(int index[], int num)
{
        int i,j,tem;

        for(i=0;i<num-1;i++)
                for(j=0;j<num-1-i;j++)
                {
                        if(index[j]>index[j+1])
                        {
                                tem = index[j];
                                index[j] = index[j+1];
                                index[j+1] = tem;
                        }
                }

}

int main()
{
        int a[102],t,n,i,count;
        fastRead(&t);
        while(t--)
        {
                fastRead(&n);
                count = 0;
                for(i=0;i<n;i++)
                        fastRead(&a[i]);
                bubble(a,n);
                for(i=1;i<n;i++)
                           count += a[i] - a[0];
                printf("%d\n",count);
        }
        return 0;
}
