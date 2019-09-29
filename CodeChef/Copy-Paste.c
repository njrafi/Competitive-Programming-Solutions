#include <stdio.h>


int main()


{
        int T,count,i,N,num;
        scanf("%d", &T);

        while(T--)
        {
                int array[100001]={0};
                count = 0;
                scanf("%d", &N);
                for(i=0;i<N;i++)
                {
                        scanf("%d", &num);
                        array[num]++;
                }

                for(i=0;i<100001;i++)
                        if(array[i])
                                count++;

                printf("%d\n", count);
        }


        return 0;
}
