#include <stdio.h>
#define len 1000000



int main()
{
        int T,i,jump,day,count;
        char p[len];
        scanf("%d\n", &T);

        while(T--)
        {
                jump=0;
                day = 0;
                gets(p);
                for(i=0;p[i];i++)
                {
                        count = 0;
                        if(p[i]=='.')
                                while(p[i]=='.')
                                {
                                        count++;
                                        i++;
                                }
                        if(count>jump)
                        {
                                jump = count;
                                day++;
                        }

                }

                printf("%d\n", day);

        }

        return 0;
}
