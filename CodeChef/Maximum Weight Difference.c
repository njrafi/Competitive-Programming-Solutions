#include <stdio.h>


int bubble(int index[], int num,int k)
{
        int i,j,tem;
        for(i=0;i<num-1;i++)
                for(j=0;j<num-i-1;j++)
                {
                        if(index[j]>index[j+1])
                        {
                                tem = index[j];
                                index[j] = index[j+1];
                                index[j+1] = tem;
                        }
                }
        tem = 0;
        for(i=0;i<k;i++)
                tem += ( 2 * index[i] ) ;
        return tem;
}

int main()
{
        int T,i,n,k, N[100],sum;
        scanf("%d", &T);
        while(T--)
        {
                sum = 0;
                scanf("%d %d", &n,&k);
                for(i=0;i<n;i++)
                {
                        scanf("%d", &N[i]);
                        sum += N[i];
                }
                if(k<n-k)
                        sum -= bubble(N,n,k);
                else
                        sum -= bubble(N,n,n-k);
                printf("%d\n", sum);
        }
        return 0;
}
