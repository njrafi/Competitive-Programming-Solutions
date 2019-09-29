#include <stdio.h>

int main()

{
        int t,N,a[100000],i,low,tem,sum;
        scanf("%d", &t);
        while(t--)
        {
                sum = 0;
                tem = 0;
                low = 1000000;
                scanf("%d", &N);
                if(N==1)
                {
                        scanf("%d", &a[0]);
                        printf("2\n");
                        continue;
                }
                for(i=0;i<N;i++)
                {
                        scanf("%d", &a[i]);
                        sum += a[i];
                        if(a[i]<low)
                                low = a[i];
                }
                for(i=0;i<N;i++)
                        if(a[i]==1)
                        {
                                printf("-1\n");
                                tem++;
                                break;
                        }
                sum = sum - low + 2 ;
                if(!tem)
                        printf("%d\n", sum);
        }
        return 0;
}
