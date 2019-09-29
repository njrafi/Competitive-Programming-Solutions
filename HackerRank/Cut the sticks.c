#include <stdio.h>

int main()
{
        int s[1000],n,i,count,sm;
        scanf("%d", &n);
        for(i=0;i<n;i++)
                scanf("%d", &s[i]);
        printf("%d\n", n);
        count = n;
        while(1)
        {
                sm=1001;
                count = 0;
                for(i=0;i<n;i++)
                        if(s[i]<sm && s[i]>0)
                                sm=s[i];

                for(i=0;i<n;i++)
                        if(s[i])
                                s[i] -= sm;

                for(i=0;i<n;i++)
                        if(s[i])
                                count++;

                if(!count)
                        break;

                printf("%d\n", count);
        }
        return 0;
}
