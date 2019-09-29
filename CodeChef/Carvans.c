#include <stdio.h>


int scan()
{
        int t=0;
        char c;
        c=getchar_unlocked();
        while(c<'0' || c>'9')
        c=getchar_unlocked();
        while(c>='0' && c<='9'){
        t=(t<<3)+(t<<1)+c-'0';
        c=getchar_unlocked();
        }
        return(t);
}
int main()

{
        int T,i,num1,num2,count,N;
        T = scan();
        while(T--)
        {
               count = 1;
                N = scan();
                num1 = scan();
                N--;
                while(N--)
                {
                        num2= scan();
                        if(num2<num1)
                                count++;
                        else
                                continue;
                        num1 = num2;
                }

                printf("%d\n", count);
        }
        return 0;
}
