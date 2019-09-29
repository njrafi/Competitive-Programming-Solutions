#include <stdio.h>
#include <math.h>


int ispalin(int inp)
{
        int rev = 0,tem,rem;
        tem = inp;
        while(tem)
        {
                rem = tem % 10;
                rev = rev*10 + rem;
                tem /= 10;
        }
        if(rev==inp)
                return 1;
        return 0;

}

int isprime(int n)
{
        if(n<=1)
                return 0;
        if(n<=3)
                return 1;
        if(n%2==0 || n%3==0)
                return 0;
        int i;
        for(i=5;i*i<=n;i+=6)
                if(n%i==0 || n%(i+2)==0)
                        return 0;
        return 1;
}


int main()

{
        int inp,i;
        scanf("%d", &inp);
        for(i=inp;;i++)
                if(ispalin(i))
                        if(isprime(i))
                        {
                                printf("%d\n",i);
                                break;
                        }
        return 0;
}
