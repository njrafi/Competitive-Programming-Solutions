#include <stdio.h>

int main()

{
        int t,i,a,b,n,sum,max;
        scanf("%d", &t);
        while(t--)
        {
                max = 0;
                sum = 0;
                scanf("%d", &n);
                scanf("%d", &a);
                n--;
                while(n--)
                {
                        scanf("%d", &b);
                        if(b==a)
                        {
                                sum++;
                                if(max<sum)
                                        max = sum;
                        }
                        else
                                sum = 0;
                        a = b;
                }
                printf("%d\n", max);


        }

        return 0;
}
