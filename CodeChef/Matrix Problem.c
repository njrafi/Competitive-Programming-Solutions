#include <stdio.h>

int main()
{
        int mat[100][100],i,j,r,c,N,m,M[100],k;
        scanf("%d %d", &N, &m);
        r = N;
        c = N;
        for(i=1;i<=r;i++)
                for(j=1;j<=c;j++)
                        scanf("%d", &mat[i][j]);

        for(i=0;i<m;i++)
                scanf("%d", &M[i]);
        for(k=0;k<m;k++)
        {
                N = M[k];
                N %= 360;
                if(!N)
                {
                        for(i=1;i<=r;i++,printf("\n"))  // normal
                                for(j=1;j<=c;j++)
                                        printf("%d ", mat[i][j]);
                }
                else if(N==90)
                {
                        for(j=1;j<=c;j++,printf("\n"))  // 90d
                                for(i=r;i>=1;i--)
                                        printf("%d ", mat[i][j]);
                }
                else if(N==180)
                {
                        for(i=r;i>=1;i--,printf("\n"))  // 180d
                                for(j=c;j>=1;j--)
                                        printf("%d ", mat[i][j]);
                }
                else
                {
                        for(j=c;j>=1;j--,printf("\n"))  // 270d
                                for(i=1;i<=r;i++)
                                        printf("%d ", mat[i][j]);
                }
                printf("\n");
        }
        return 0;
}
