#include <stdio.h>
#include <stdlib.h>
int main()
{
        int t,i,n,count;
        char s[1001];
        scanf("%d", &t);
        while(t--)
        {
                scanf("%d\n", &n);
                count = 0;
                int p[1001] = {0};
                gets(s);
                for(i=0;s[i];i++)
                        if(s[i]=='1')
                                if(i==0)
                                {
                                        p[i] = 1;
                                        p[i+1] = 1;
                                }
                                else if(i==n-1)
                                {
                                        p[i] = 1;
                                        p[i-1] = 1;
                                }
                                else
                                {
                                        p[i] = 1;
                                        p[i+1] = 1;
                                        p[i-1] = 1;
                                }
                for(i=0;i<n;i++)
                        if(!p[i])
                                count++;

                printf("%d\n", count);

        }
}
