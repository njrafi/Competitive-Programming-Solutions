#include <stdio.h>

int main()


{
    int T,i,count;
    int p;
    scanf("%d", &T);

    while(T--)
    {
            scanf("%d", &p);
            count=0;
            for(i=2048;i; i=i/2)
            {
                    while(p>=i)
                    {
                            p = p - i;
                            count++;
                            if(!p)
                            {
                                    break;
                            }
                    }
            }
            printf("%d\n", count);

    }

    return 0;
}

