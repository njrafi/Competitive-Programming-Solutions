#include <stdio.h>
int main()
{
        int T,i,N,max;
        scanf("%d", &T);
        while(T--)
        {
                int count[10001] = {0},num;
                scanf("%d", &N);
                for(i=0;i<N;i++)
                {
                        scanf("%d", &num);
                        count[num]++;
                }

                num = 0;
                for(i=0;i<10001;i++)
                {
                        if(count[i]>num)
                        {
                                num = count[i];
                                max = i;
                        }
                }

                printf("%d %d\n", max ,num);
        }


        return 0;
}



