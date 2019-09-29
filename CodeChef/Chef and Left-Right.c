#include <stdio.h>

int main()

{
        int T,j, m = 1000000007 ;
        int i;
        char s[100005];
        scanf("%d\n", &T);
        while(T--)
        {
                gets(s);
                i = 1;
                for(j=0;s[j];j++)
                {
                        if(s[j]=='l')
                        {
                                i = 2 * i;
                                i = i % m;
                        }
                        else if(s[j]=='r')
                        {
                                i = 2 * i + 2 ;
                                i = i%m;

                        }

                        j++;

                        if(!s[j])
                                break;


                        if(s[j]=='l')
                        {
                                i = 2 * i - 1 ;
                                i = i%m;
                        }
                        else if(s[j]=='r')
                        {
                                i = 2 * i +1;
                                i =  i % m ;
                        }

                }

                printf("%d\n", i);

        }
}
