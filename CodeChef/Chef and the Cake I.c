#include <stdio.h>


int main()
{
        int T,i,j,x1,y1,x2,y2,count;
        scanf("%d", &T);
        while(T--)
        {
                count = 0;
               int box[1002][1002] = {0};
                scanf("%d %d %d %d", &x1,&y1,&x2,&y2);

                for(i=x1;i<x2;i++)
                        for(j=y1;j<y2;j++)
                                box[i][j]++;

                scanf("%d %d %d %d", &x1,&y1,&x2,&y2);

                for(i=x1;i<x2;i++)
                        for(j=y1;j<y2;j++)
                                box[i][j]++;

                for(i=1;i<=1001;i++)
                        for(j=1;j<=1001;j++)
                                if(box[i][j])
                                        count++;

                printf("%d\n", count);

        }
        return 0;
}
