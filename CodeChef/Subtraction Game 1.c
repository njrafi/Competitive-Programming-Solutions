#include <stdio.h>


int GCD(int m, int n)
{
    int r;
    while(1)
    {
        r = m % n;
        if(r == 0)
            break;
        m = n;
        n = r;
    }


    return n;
}

int main()

{
        int T,i,n,N[1000],g;
        scanf("%d", &T);
        while(T--)

        {
                scanf("%d", &n);
                for(i=0;i<n;i++)
                        scanf("%d", &N[i]);

                g = GCD(N[0],N[1]);
                for(i=1;i<n-1;i++)
                {
                       g= GCD(g,N[i+1]) ;
                }
                printf("%d\n", g);


        }

        return 0;

}
