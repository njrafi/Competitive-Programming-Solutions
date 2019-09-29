#include <stdio.h>

int main()

{
        int T,N,i,j;
        char a;
        long long int count;
        scanf("%d", &T);
        while(T--)
        {
                scanf("%d\n", &N);
                count = 0;
                while(N--)
                {
                        scanf("%c", &a);
                        if(a=='1')
                                count++;

                }
                printf("%lld\n", ( count*(count+1) / 2 )  );
        }
        return 0;
}
