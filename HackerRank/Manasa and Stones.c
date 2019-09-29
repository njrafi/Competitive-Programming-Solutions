#include <stdio.h>


int main()

{
        int t,n,a,b,min,max,i;
        scanf("%d", &t);
        while(t--)
        {
                scanf("%d %d %d",&n,&a,&b);
                n--;
                if(a==b)
                {
                        printf("%d\n",n*a);
                        continue;
                }
                else if(a>b)
                {
                        min = b;
                        max = a;
                }
                else
                {
                        min = a;
                        max = b;
                }
                for(i=0;i<=n;i++)
                {
                        printf("%d ", (n-i)*min + i* max );
                }
                printf("\n");

        }
        return 0;
}
