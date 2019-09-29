#include <stdio.h>


int main()
{
        int T,N,C,Q, i,j,tem;
        scanf("%d", &T);

        while(T--)
        {
                scanf("%d %d %d", &N,&C,&Q);
                while(Q--)
                {
                        scanf("%d %d", &i,&j);
                      if(C<i || C>j)
                        continue;


                         if(C-i<j-C )
                       {
                               j -= C-i;
                               C = j;
                               continue;
                       }
                        else if(C-i==C-j)
                        {
                                continue;
                        }
                        else
                               {
                                       i += j-C;
                                       C = i;
                               }
                }

                        printf("%d\n", C);

        }

        return 0;
}
