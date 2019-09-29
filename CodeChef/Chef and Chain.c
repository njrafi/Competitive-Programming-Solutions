#include <stdio.h>

int main()

{
        int T,i,count1,count2;
        char tem[100005];
        scanf("%d\n", &T);
        while(T--)
        {
                count1 = 0;
                count2 = 0;
                gets(tem);
                for(i=0;tem[i];i+=2)
                {
                        if(tem[i]!='+')
                                count1++;

                        if(!tem[i+1])
                                break;

                        if(tem[i+1]!='-')
                                count1++;
                }

                for(i=0;tem[i];i+=2)
                {
                        if(tem[i]!='-')
                                count2++;

                        if(!tem[i+1])
                                break;

                        if(tem[i+1]!='+')
                                count2++;
                }

                if(count1<count2)
                        printf("%d\n", count1);
                else
                        printf("%d\n", count2);

        }
        return 0;
}
