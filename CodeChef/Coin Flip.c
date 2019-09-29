#include <stdio.h>

int main()
{
    long int N;
    int G,T,I,Q,head,tail;
    scanf("%d", &T);
    while (T)
    {
        scanf("%d", &G);
        while(G)
        {
            scanf("%d %d %d", &I,&N,&Q);
            if(N%2==0)
            {
                printf("%d\n",N/2);
            }
            else
            {
                if(I==1)
                {
                    head = N/2;
                    tail = head+1;
                }
                else
                {
                    tail = N/2;
                    head = tail+1;
                }
                if (Q==1)
                {
                    printf("%d\n", head);
                }
                else
                {
                    printf("%d\n", tail);
                }

            }
            G--;
        }
        T--;
    }
    return 0;
}
