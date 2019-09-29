#include <stdio.h>

void bubble(int index[], int num)
{
        int i,j,tem;

        for(i=0;i<num-1;i++)
                for(j=0;j<num-1-i;j++)
                {
                        if(index[j]>index[j+1])
                        {
                                tem = index[j];
                                index[j] = index[j+1];
                                index[j+1] = tem;
                        }
                }



}

int main()
{
        int r,g,b,m,t,max,tem;
        scanf("%d", &t);
        while(t--)
        {
                int a[3] = {0};
                scanf("%d %d %d %d", &r, &g, &b, &m);
                while(r--)
                {
                        scanf("%d", &tem);
                        if(tem>a[0])
                                a[0] = tem;
                }
                while(g--)
                {
                        scanf("%d", &tem);
                        if(tem>a[1])
                                a[1] = tem;
                }
                while(b--)
                {
                        scanf("%d", &tem);
                        if(tem>a[2])
                                a[2] = tem;
                }

                while(m--)
                {
                        bubble(a,3);
                        a[2] /= 2;

                }
                bubble(a,3);
                printf("%d\n",a[2]);
        }
        return 0;
}
