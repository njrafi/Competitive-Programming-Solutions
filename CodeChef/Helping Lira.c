#include <stdio.h>


int main()
{
        int x1,y1,x2,y2,x3,y3,min=9999999,max=-1,a,b,c,area;
        int t,max_i,min_i,i;
        scanf("%d", &t);
        for(i=1;i<=t;i++)
        {
                scanf("%d %d %d %d %d %d",&x1,&y1,&x2,&y2,&x3,&y3);
                area =  (x1-x3)*(y2-y1) - (x1-x2)*(y3-y1);
                if(area<0)
                        area*=-1;
               // printf("%d/n",area);
                if(area>=max)
                {
                        max = area;
                        max_i = i;
                }
                if (area<=min)
                {
                        min = area;
                        min_i = i;
                }
        }
        printf("%d %d\n",min_i,max_i);
        return 0;
}
