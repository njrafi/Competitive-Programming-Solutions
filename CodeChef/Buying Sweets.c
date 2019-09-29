#include <stdio.h>

int main()
{
        int N,X,A[100],T,i,total,amount,tem;
        scanf("%d", &T);
        while(T--)
        {
                scanf("%d %d", &N, &X);
                total = 0;
                tem =0;
                for(i=0;i<N;i++)
                {
                        scanf("%d", &A[i]);
                        total += A[i];
                }
                amount = total/X;
                if(amount==0)
                {
                        printf("-1\n");
                        continue;
                }
                for(i=0;i<N;i++)
                {
                        if((total-A[i])>=(amount*X))
                           {
                                   printf("-1\n");
                                   tem++;
                                   break;
                           }
                }
                if(tem==0)
                {
                        printf("%d\n", amount);
                }


        }
        return 0;
}
