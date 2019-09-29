#include <stdio.h>
#define nl printf("\n")

int main()
{
       int t,i,N;
       scanf("%d", &t);
       while(t--)
       {
                scanf("%d", &N);
                if(!N)
                {
                        printf("0\n");
                        continue;
                }
                if(N%2)
                {

                        printf("0\n");
                        continue;
                }
                N = N/2 - 1;
                printf("9");
                for(i=0;i<N;i++)
                        printf("0");
                nl;
       }
       return 0;
}
