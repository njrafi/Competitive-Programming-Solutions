#include <stdio.h>
int main()

{
        double s,t,D;
        int T;
        scanf("%d", &T);

        while(T--)
        {
                scanf("%lf %lf %lf", &s,&t,&D);
                if(s+t<D)
                        printf("%lf\n", D-s-t);
                else if(s+D<t)
                        printf("%lf\n", t-s-D);
                else if(t+D<s)
                        printf("%lf\n", s-t-D);
                else
                        printf("0\n");
        }
        return 0;
}
