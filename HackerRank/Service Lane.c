#include <stdio.h>
#include <stdlib.h>

int main()
{
        int n,t,*h,i,ans,j;
        scanf("%d %d",&n, &t);
        h = malloc(n*sizeof(int));
        for(i=0;i<n;i++)
                scanf("%d", &h[i]);
        while(t--)
        {
                ans = 4;
                scanf("%d %d", &i, &j);
                for(;i<=j;i++)
                        if(h[i]<ans)
                                ans = h[i];

                printf("%d\n", ans);
        }
}

