#include <stdio.h>


int main()

{
        int T,t1,t2,t3,t4;
        scanf("%d", &T);
        while(T--)
        {
                scanf("%d %d %d %d", &t1,&t2,&t3,&t4);
                printf("%lf\n", (double) t1 /  ( (t1+t2) ) );
        }
        return 0;
}
