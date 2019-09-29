#include <stdio.h>

int main()
{
        int T,i,n,len;
        scanf("%d", &T);
        while(T--)
        {
                len = 1;
                scanf("%d", &n);
                for(i=1;i<=n;i++)
                {
                        len = 2*len;
                        i++;
                        if(i>n)
                                break;
                        len += 1;
                }
                printf("%d\n", len);

        }
        return 0;

}
