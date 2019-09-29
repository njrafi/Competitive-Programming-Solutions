#include <stdio.h>
#include <string.h>

int main()


{
        int T,i,value;
        scanf("%d\n", &T);
        char str[1001];

        while(T--)
        {
                int count = 0;
                gets(str);
                for(i=1;str[i];i++)
                {
                       if(str[i]>str[i-1])
                        {
                                count += str[i] - str[i-1];

                        }
                        else if(str[i]==str[i-1])
                                continue;
                        else
                        {
                                count += 26 -  str[i-1] + str[i];
                        }
                }
         //       printf("%d", count+strlen(str)+1 );
         value = count+strlen(str)+1;
         if(value<= 11*strlen(str))
                printf("YES\n");
         else
                printf("NO\n");

        }

        return 0;
}
