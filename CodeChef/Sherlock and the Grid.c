#include <stdio.h>

int sher(char a[1005][1005],int n)
{
        int x,x1,y,j,tem,Y[1005]={0},count=0;
        for(x=n-1;x>=0;x--)
        {
                tem = 0;
                for(y=n-1;y>=0 ;y--)
                {
                        if(Y[y] && a[y][x]=='.')
                                continue;
                        if(a[y][x]=='#')
                        {
                                Y[y]++;
                                tem++;
                                continue;
                        }
                        if(!tem)
                                count++;



                }

        }
        return count;
}


int main()

{
        int t,i,N,j;
        char a[1005][1005];
        scanf("%d", &t);
        while(t--)
        {
                scanf("%d", &N);
                getchar_unlocked();
                for(i=0;i<N;i++,getchar_unlocked())
                        for(j=0;j<N;j++)
                                a[i][j] = getchar_unlocked();
                printf("%d\n", sher(a,N));
        }
}

