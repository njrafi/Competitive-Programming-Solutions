#include <stdio.h>

int main()
{
        int a,b,c,t,n,tem,trip[3][1210],i=0,max,j;
        for(a=1;a<=3000;a++)
                for(b=a+1;b<=3000-a;b++)
                        for(c=b+1;c<=3000-a-b;c++)
                                if(a*a + b*b == c*c)
                                {
                                        trip[0][i] = a;
                                        trip[1][i] = b;
                                        trip[2][i] = c;
                                        i++;
                                }
        scanf("%d", &t);
        while(t--)
        {
                max = -1;
                scanf("%d", &n);
                for(j=0;j<i;j++)
                        if(trip[0][j]+trip[1][j]+trip[2][j]==n && trip[0][j]*trip[1][j]*trip[2][j]>max)
                                max = trip[0][j]*trip[1][j]*trip[2][j];
              printf("%d\n",max);
        }
        return 0;
}
