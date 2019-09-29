#include <stdio.h>


int main()

{
        int T,i,j, count, sum;
        char s[201];
        scanf("%d\n", &T);
        while(T--)
        {
                int a[123]= {0};
                sum = 0;
                gets(s);
                for(i=0;s[i];i++)
                        a[s[i]]++;

                for(i=65;i<123;i++)
                {
                        count = 0;
                        if(a[i])
                                count = a[i];
                        else
                                continue;

                        if(count%2==0)
                                sum += count/2;
                        else
                                sum += ( count+1) /2 ;


                }

                printf("%d\n", sum);

        }
        return 0;
}
