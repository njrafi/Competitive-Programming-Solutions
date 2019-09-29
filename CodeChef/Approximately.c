#include <stdio.h>
#include <stdlib.h>

void devide(int a,int b,int k)

{
        int i,r;
        printf("%d",a/b);
        if(k)
                printf(".");
        r = a%b;
        for(i=0;i<k;i++)
        {
                r *= 10;
                a = r;
                if(a<b)
                {
                        printf("0");
                        continue;
                }
                putchar_unlocked(a/b+'0');
                r = a%b;
        }


        printf("\n");
}

int main()
{
        int T,K;
        scanf("%d", &T);
        while(T--)
        {
                scanf("%d", &K);
                devide(103993,33102,K);
        }
        return 0;
}
