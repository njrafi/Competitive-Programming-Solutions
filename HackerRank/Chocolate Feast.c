#include <stdio.h>

int main()
{
        int t,n,c,m,ck,w;
        scanf("%d", &t);
        while(t--)
        {
                scanf("%d %d %d", &n,&c,&m);
                ck = n/c;
                w = ck;
                while(w)
                {
                        ck += w/m;
                        w = (w%m) + (w/m);
                        if(w<m)
                                break;
                }
                printf("%d\n", ck);
        }
        return 0;
}

