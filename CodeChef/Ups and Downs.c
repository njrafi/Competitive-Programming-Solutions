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


void UaD(int a[], int num)
{
        int i,j,tem;

        for(i=0;i<num-1;i++)
        {
                if(i%2==0)
                {
                        if(a[i]>a[i+1])
                        {
                                tem = a[i];
                                a[i] = a[i+1];
                                a[i+1] = tem;
                        }
              }
                else
                {
                        if(a[i]<a[i+1])
                        {
                               tem = a[i];
                                a[i] = a[i+1];
                                a[i+1] = tem;
                        }
                }
        }

}


int main()
{
        int i,T,N, j,k,l;
        T = read_int();
        while(T--)
        {
                N = read_int();
                int *num;
                num = malloc(N*sizeof(int));
                for(i=0;i<N;i++)
                        num[i] = read_int();


                UaD(num,N);

                for(i=0;i<N;i++)
                        printf("%d ", num[i]);
                printf("\n");

        }
        return 0;
}
