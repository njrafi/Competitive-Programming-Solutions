#include <stdio.h>

int main()

{
        int t,i,a,b,n,sum;
        scanf("%d", &t);
        while(t--)
        {
                sum = 0;
                scanf("%d", &n);
                scanf("%d", &a);
                n--;
                while(n--)
                {
                        scanf("%d", &b);
                        if(b>a)
                                sum++;
                        a = b;
                }
                printf("%d\n", sum);


        }

        return 0;
}
