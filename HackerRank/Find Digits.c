#include <stdio.h>
int main ()
{
        int n,t,i,dig,count;
        scanf ("%d", &t);
        while(t--)
        {
                scanf("%d", &n);
                i=n;
                count = 0;
                while (n)
                {
                        dig = n % 10;
                        if(dig)
                                if(i%dig==0)
                                        count++;
                        n = n / 10;
                }
                printf ("%d\n",count);
        }
        return 0;
}