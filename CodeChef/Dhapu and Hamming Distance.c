#include <stdio.h>
#include <string.h>

int main()

{
        char a[1005],b[1005];
        int i,t,count;
        scanf("%d\n", &t);
        while(t--)
        {
                gets(a);
                gets(b);
                count = 0;
                if(strlen(a)!=strlen(b))
                {
                        printf("-1\n");
                }
                else
                {
                        for(i=0;a[i];i++)
                                if(a[i]!=b[i])
                                        count++;
                        printf("%d\n",count);

                }
        }

        return 0;

}
