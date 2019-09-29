#include  <stdio.h>


int main()


{
        int t,N, id,sum, ans;
        scanf("%d", &t);
        while(t--)
        {
                scanf("%d", &N);
                ans= 0;
                while(N--)
                {
                        scanf("%d %d", &id, &sum);
                        ans += id-sum;
                }
                printf("%d\n", ans);
        }
        return 0;
}
