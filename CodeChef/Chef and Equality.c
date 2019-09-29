#include <stdio.h>

int main()

{
        int T,N,i,j,tem;
        scanf("%d", &T);
        while(T--)
        {
                int num[100005] = {0};
                scanf("%d", &N);
                j = N;
                while(j--)
                {
                        scanf("%d", &tem);
                        num[tem]++;
                }
                tem = 0;
                for(i=0;i<100000;i++)
                        if(tem<num[i])
                                tem = num[i];

                printf("%d\n", N-tem);
        }

        return 0;
}
