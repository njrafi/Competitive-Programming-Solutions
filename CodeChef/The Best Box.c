#include <stdio.h>
#include <math.h>

int main()

{
        int t;
        double p,s,y1,y2,v1,v2;
        scanf("%d", &t);
        while(t--)
        {
                scanf("%lf %lf", &p,&s);
                y1=  (p + sqrt(p*p-4*6*s)) / 12;
                y2 = (p - sqrt(p*p-4*6*s)) / 12;
                v1 = y1*(p/4-2*y1)*y1;
                v2 = y2*(p/4-2*y2)*y2;
                if(v1>=v2)
                        printf("%.2lf\n",v1);
                else
                        printf("%.2lf\n",v2);

        }
}
