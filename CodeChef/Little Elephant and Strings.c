#include <stdio.h>
#include <string.h>

int main()
{
        char N[55][55], K[55];
        int n,k,i,tem;
        scanf("%d %d\n", &n, &k);
        for(i=0;i<n;i++)
                gets(N[i]);

        while(k--)
        {
                gets(K);
                tem = 0;
                if(strlen(K)>=47)
                {
                        printf("Good\n");
                        continue;
                }

                for(i=0;i<n;i++)
                        if( strstr(K,N[i]) )
                        {
                                tem++;
                                break;
                        }

                if(!tem)
                        printf("Bad\n");
                else
                        printf("Good\n");
        }
        return 0;
}
