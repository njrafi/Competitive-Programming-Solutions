#include <stdio.h>

int main()
{
        int t,i,count;
        char s1[10005],s2[10005];
        scanf("%d\n", &t);
        while(t--)
        {
                gets(s1);
                gets(s2);
                int a[130]={0};
                int b[130]={0};
                count=0;
                for(i=0;s1[i];i++)
                        a[s1[i]]++;
                for(i=0;s2[i];i++)
                        b[s2[i]]++;

                for(i=0;i<130;i++)
                        if(a[i] && b[i])
                                if(a[i]<=b[i])
                                        count += a[i];
                                else
                                        count += b[i];

                printf("%d\n", count);

        }
}
