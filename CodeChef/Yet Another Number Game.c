#include <stdio.h>

int main()

{
        int t,N;
        scanf("%d", &t);
        while(t--)
        {
                scanf("%d", &N);
                if(N%2)
                        printf("BOB\n");
                else
                        printf("ALICE\n");

        }
        return 0;
}
