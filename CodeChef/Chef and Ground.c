#include <stdio.h>

int main()
{
        int t,n,m,a[105],i,max,count;
        scanf("%d", &t);
        while(t--)
        {
                max = 0;
                count = 0;
                scanf("%d %d", &n, &m);
                for(i=0;i<n;i++)
                {
                        scanf("%d", &a[i]);
                        if(a[i]>max)
                                max = a[i];
                }
                for(i=0;i<n;i++)
                        count += max - a[i];
                m -= count;

                if(m==0 && count==0)
                {
                      printf("Yes\n");
                      continue;
                }

                if(m<0)
                {
                        printf("No\n");
                        continue;
                }


                if(m%n)
                        printf("No\n");
                else
                        printf("Yes\n");


        }
}
