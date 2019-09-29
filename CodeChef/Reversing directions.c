#include <stdio.h>
int main()
{
        char road[40][50], dir[40][6];
        int T,N,i;
        scanf("%d", &T);
        while(T--)
        {
                scanf("%d", &N);
                for(i=0;i<N;i++)
                {
                        scanf("%s ",  dir[i] );    // input
                        gets(road[i]);
                }
                i--;
                printf("%s %s\n", dir[0], road[i]);
                i--;
                for(;i>=0;i--)
                {
                        if(dir[i+1][0]=='L')
                                printf("%s %s\n", "Right", road[i]);  //output
                        else
                                printf("%s %s\n", "Left", road[i]);
                }
                printf("\n");
        }
        return 0;
}
