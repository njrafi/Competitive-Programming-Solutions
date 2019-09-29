#include <stdio.h>


int main()

{
        long long int fib[100],inp;
        int i,n,t,tem;
        scanf("%d", &t);
        fib[0] = 0;
        fib[1] = 1;
        for(i=2;fib[i-1]<10000000000;i++)
                fib[i] = fib[i-2] + fib[i-1];
        n = i-1;
        
        while(t--)
        {
                scanf("%lld", &inp);
                tem = 0;
                for(i=0;i<=n;i++)
                        if(inp == fib[i])
                        {
                                printf("IsFibo\n");
                                tem++;
                                break;
                        }
                if(!tem)
                        printf("IsNotFibo\n");
        }
        return 0;
}
