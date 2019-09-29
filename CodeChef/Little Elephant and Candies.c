#include <stdio.h>
int main()
{
        int T,N,C, A[100];
        int i,sum;
        scanf("%d", &T);
        while(T--)
        {
                sum = 0;
                scanf("%d %d", &N,&C);
                for(i=0;i<N;i++)
                {
                        scanf("%d", &A[i]);
                        sum += A[i];
                }

                if(C>=sum)
                        printf("Yes\n");
                else
                        printf("No\n");
        }
        return 0;
}
