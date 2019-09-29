#include <stdio.h>

int main()
{
        long long int sum,limit,i,j,ans;
        int T;
        scanf("%d", &T);
        while(T--)
        {
                i=0,
                j=1,
                ans = 0;
                scanf("%lld", &limit);
                while(1)
                {
                        sum = i +j;
                        if(sum>limit)
                        {
                                break;
                        }
                        if(sum%2==0)
                                ans += sum;

                        i = j;
                        j = sum;
                }

                printf("%lld\n",ans);
        }
        return 0;
}
