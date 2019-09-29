#include <stdio.h>
#ifndef ONLINE_JUDGE
    #define gc getchar
    #define pc putchar
#else
    #define gc getchar_unlocked
    #define pc putchar_unlocked
#endif


inline void fastRead(int *a)
{
        register char c=0;
        while (c<33)
                c=gc();
        *a=0;
        while (c>33)
        {
                *a= *a*10+c-'0';
                c=gc();
        }
}

inline void fastWrite(int a)
{
        char snum[20];
        int i=0;
        do
        {
                snum[i++] = a%10+48;
                a=a/10;
        }
        while(a!=0);
                i=i-1;
        while(i>=0)
        pc(snum[i--]);
        pc('\n');
}




long long int fast_pow(int x,int y)
{
        int i;
        long long int ans=x;
        if(y==1)
                return ans;
        for(i=2; i<=y/2 ; i++)
                ans *= x;

        if(y%2)
                return ans*ans*x;
        else
                return ans*ans;

}
int level(int n)
{
       int i;
       for(i=1;fast_pow(2,i)-1<n;i++)
                continue;
        return i;

}
int main()
{
        int a,b,la,lb,N,count;
        fastRead(&N);
        while(N--)
        {
                fastRead(&a);
                fastRead(&b);
                count = 0;
                la = level(a);
                lb = level(b);
                if(la>lb)
                        while(la!=lb)
                        {
                                la--;
                                count++;
                                if(a%2==0)
                                        a /= 2;
                                else
                                        a = (a-1) /2;

                        }
                else if(lb>la)
                        while(la!=lb)
                        {
                                lb--;
                                count++;
                                if(b%2==0)
                                        b /= 2;
                                else
                                        b = (b-1) /2;

                        }


                while(a!=b)
                {
                        if(a%2==0)
                                a /= 2;
                        else
                                a = (a-1) /2;

                        if(b%2==0)
                                b /= 2;
                        else
                                b = (b-1) /2;
                        count += 2;
                }

                fastWrite(count);
        }
        return 0;
}
